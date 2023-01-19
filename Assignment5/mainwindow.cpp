/* 객체지향 프로그래밍 Assignment 5_20210479 이주현
 * 명예 서약(Honor Code): “나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.” */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 필요한 초기 설정 */
    connectWithVector(); //라벨과 벡터 초기화 및 기타 초기 설정
    disWord.fill("", 6); //단어를 저장할 벡터를 초기화
    wordFrom.fill(-10, 6); //단어가 easy인지 crazy인지 저장할 벡터를 초기화
    positionX.fill(0, 6); //x축은 랜덤으로 들어갈 것이므로 초깃값을 0으로 설정
    positionY.fill(100, 6); //y축의 초깃값은 타이머 아래의 맨 위이므로 해당 값으로 초기화
    std::srand(std::time(NULL)); //랜덤 함수 seed 설정

    wordNum = 0; //게임 재시작의 경우를 대비해 0으로 초기화

    /* 점수 초기화 */
    score = 0; //게임 재시작의 경우를 대비해 0으로 초기화
    ui->score->display("0"); //LCD 패널에 0 표시

    ui->text1->clear(); //입력창 초기화

    /* 타이머 관련 설정 */
    timer = new QTimer(this);

    leftTime = QTime(0, 0, 30);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeCount())); //1초마다 타이머가 카운트다운 되도록 timeCount 함수와 연결
    timer->start(1000); //1초 단위로 timeout 시그널이 발생하도록 함

    /* 엔터 키 이벤트 감지 */
    ui->text1->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeCount()
{
    leftTime = leftTime.addSecs(-1); //1초 카운트다운

    if(leftTime.second() <= 0 || leftTime.second() > 30) //남은 시간이 0초 이하일 때
    {
        ui->timerLCD->display("0"); //LCD 패널에 0 출력 (음수가 출력되지 않도록 함)
        haveFinished(); //메시지 박스 출력으로 넘어감
    }

    else //남은 시간이 있을 때에는 남은 시간만 출력하도록 함
        ui->timerLCD->display(QString::number(leftTime.second()));

    typingGame(); //게임을 위해 필요한 함수 호출
}

void MainWindow::haveFinished()
{
    QMessageBox::StandardButton msgBox; //타이머 종료 시 출력될 qmessagebox 객체 선언

    /* 메시지 박스 관련 설정 */
    QString title = "Time Out"; //메시지 박스의 제목 입력을 위한 qstring 객체
    QString info = ""; //내용을 하나로 합쳐서 입력하기 위한 qstring 객체 선언
    info = info + "Your score is " + info.number(score) + "." + "\n" + "Do you want to try again?"; //앞서 만든 qstring 객체에 메시지 박스에 들어가야 하는 내용 적기

    msgBox = QMessageBox::question(this, title, info, QMessageBox::Yes|QMessageBox::No); //question 타입으로 초기 설정

    if(msgBox == QMessageBox::Yes) //사용자가 yes를 누른 경우 게임 재시작
    {
        /* 초기화 보장을 위한 초기 설정 반복 */
        connectWithVector(); //라벨과 벡터 초기화 및 기타 초기 설정
        disWord.fill("", 6); //단어를 저장할 벡터를 초기화
        wordFrom.fill(-10, 6); //단어가 easy인지 crazy인지 저장할 벡터를 초기화
        positionX.fill(0, 6); //x축은 랜덤으로 들어갈 것이므로 초깃값을 0으로 설정
        positionY.fill(100, 6); //y축의 초깃값은 타이머 아래의 맨 위이므로 해당 값으로 초기화

        wordNum = 0; //게임 재시작의 경우를 대비해 0으로 초기화

        ui->text1->clear(); //입력창 초기화

        /* 점수 초기화 */
        score = 0; //게임 재시작의 경우를 대비해 0으로 초기화
        ui->score->display("0"); //LCD 패널에 0 표시

        leftTime = QTime(0, 0, 30); //시간 초기화

        MainWindow(this);
    }

    else //사용자가 no를 누른 경우 게임 종료 (위젯도 같이 종료됨)
        this->close();
}

void MainWindow::selectCrazy(int index)
{
    wordInd = rand() % 10; //배열 인덱스 중 하나를 랜덤 선택

    disWord[index] = crazy_words[wordInd]; //선택된 단어 저장
    wordFrom[index] = 1; //단어가 crazy임을 표시

    wordLabel[index]->setText(disWord[index]); //선택된 단어를 라벨에 표시
    wordLabel[index]->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}")); //해당 라벨의 색깔을 빨간색으로 조정

    int randX = rand() % 679; //랜덤 x위치 발생 (x위치가 700일 경우 오른쪽 끝에 붙게 되므로 700보다 작게 설정)
    positionX[index] = randX; //랜덤 x위치를 저장
    positionY[index] = 100; //사용했던 라벨을 재활용할 경우가 있으므로 y위치도 초기화

    wordLabel[index]->move(positionX[index], positionY[index]); //라벨을 랜덤 발생한 위치로 이동시킴
    wordLabel[index]->show();

    wordNum++;
}

void MainWindow::selectEasy(int index)
{
    wordInd = rand() % 30; //배열 인덱스 중 하나를 랜덤 선택

    disWord[index] = easy_words[wordInd]; //선택된 단어 저장
    wordFrom[index] = 0; //단어가 easy임을 표시

    wordLabel[index]->setText(disWord[index]); //선택된 단어를 라벨에 표시
    wordLabel[index]->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 0);}")); //해당 라벨의 색깔을 검은색으로 설정(이전에 crazy로 쓰였을 수 있기 때문)

    int randX = rand() % 679; //랜덤 x위치 발생 (x위치가 700일 경우 오른쪽 끝에 붙게 되므로 700보다 작게 설정)
    positionX[index] = randX; //랜덤 x위치를 저장
    positionY[index] = 100; //사용했던 라벨을 재활용할 경우가 있으므로 y위치도 초기화

    wordLabel[index]->move(positionX[index], positionY[index]); //라벨을 랜덤 발생한 위치로 이동시킴
    wordLabel[index]->show(); //해당 라벨을 보이게 함

    wordNum++; //단어 개수 업데이트
}

bool MainWindow::eventFilter(QObject* target, QEvent* event)
{
    if(target == ui->text1 && event->type() == QEvent::KeyPress) //모든 이벤트 감시 중 키를 누르는 이벤트에 대해서만 동작 수행
    {
        QKeyEvent* pressedKey = static_cast<QKeyEvent*>(event); //polymorphism을 이용한 type casting

        if(pressedKey->key() == Qt::Key_Return || pressedKey->key() == Qt::Key_Enter) //눌린 키가 엔터키일 경우
        {
            whenPressEnter(); //엔터가 눌렸을 경우를 다루는 함수로 연결
            return true;
        }

        return false;
    }

    return QObject::eventFilter(target, event);
}

void MainWindow::connectWithVector()
{
    /* 화면에 display할 라벨 6개와 벡터를 연결 */
    wordLabel.append(ui->label1);
    wordLabel.append(ui->label2);
    wordLabel.append(ui->label3);
    wordLabel.append(ui->label4);
    wordLabel.append(ui->label5);
    wordLabel.append(ui->label6);

    for(int i = 0; i < 6; i++) //처음에 모든 라벨을 숨김
        wordLabel[i]->hide();
}

void MainWindow::whenPressEnter()
{
    QString input = ui->text1->toPlainText(); //입력받은 값을 읽어옴
    ui->text1->clear(); //입력창 내의 텍스트 삭제

    int lowest = -10; //(만약 화면 내에 같은 단어가 여럿 있을 경우) 가장 낮게 있는 단어를 선택
    int y = 50; //(만약 화면 내에 같은 단어가 여럿 있을 경우 비교를 위한 변수) 가장 낮은 y축 위치를 저장

    for(int i = 0; i < 6; i++)
    {
        if(disWord[i] == "") //활성화 되지 않은 라벨의 경우 비교 없이 패스
            continue;

        if(disWord[i] == input && positionY[i] > y) //입력받은 단어와 같고 y축 위치가 더 낮을 경우 변수들 업데이트
        {
            lowest = i;
            y = positionY[i];
        }

        else //입력받은 단어가 아닐 경우 패스
            continue;
    }

    if(lowest >= 0) //입력한 단어가 올바를 경우에만 작동 (입력한 단어가 존재하며 올바를 경우 lowest가 0부터 6사이의 값이 됨을 이용)
    {
        /* 올바르게 입력한 단어 삭제 및 점수 업데이트 */
        wordLabel[lowest]->hide(); //단어 사라짐 처리

        if(wordFrom[lowest] == 1) //입력한 단어가 crazy일 경우
            score += 15;

        else //입력한 단어가 easy일 경우
            score += 10;

        /* 없어진 단어를 대신해 단어 새로 생성 (생성 방법은 확률 20% 그대로 사용) */
        wordInd = rand() % 5; //0에서 4 사이의 수를 랜덤 생성

        if(wordInd == 0) //5로 나눈 값이 0일 경우에는 crazy word 생성(확률 20%)
            selectCrazy(lowest);

        else //5로 나눈 값이 0이 아닐 모든 경우에 easy word 생성
            selectEasy(lowest);
    }

    /* 시간 재표시 */
    ui->timerLCD->display(QString::number(leftTime.second()));

    /* 점수 업데이트 */
    ui->score->display(QString::number(score));
}

void MainWindow::typingGame()
{
    wordInd = rand() % 5; //0에서 4 사이의 수를 랜덤 생성

    /* 단어 생성 */
    if(wordNum == 0) //처음 단어를 생성할 경우 (올바르게 단어를 입력하면 즉시 단어가 재생성되므로 0인 경우는 초기밖에 없음)
    {
        if(wordInd == 0) //5로 나눈 값이 0일 경우에는 crazy word 생성(확률 20%)
            selectCrazy(0);

        else //5로 나눈 값이 0이 아닐 모든 경우에 easy word 생성
            selectEasy(0);
    }

    else if(wordNum >= 1 && wordNum < 6) //기존 단어가 남아있으며 6개 미만인 경우
    {
        int target = disWord.indexOf(""); //disWord가 빈칸인 인덱스를 찾음

        if(wordInd == 0) //5로 나눈 값이 0일 경우에는 crazy word 생성(확률 20%)
            selectCrazy(target);

        else //5로 나눈 값이 0이 아닐 모든 경우에 easy word 생성
            selectEasy(target);
    }

    /* y위치 업데이트 */
    for(int i = 0; i < 6; i++)
    {
        wordLabel[i]->move(positionX[i], positionY[i]); //비활성화된 라벨의 경우에는 move 동작을 해도 보이지 않으므로 구별없이 move 적용

        if(disWord[i] == "") //비어있는 칸일 경우 위치 업데이트 불필요
            continue;

        else if(wordFrom[i] == 0) //해당 단어가 easy word인 경우
            positionY[i] += 20;

        else if(wordFrom[i] == 1 && positionY[i] <= 280) //해당 단어가 crazy word이며 화면 중앙보다 윗쪽에 위치할 경우
            positionY[i] += 30;

        else if(wordFrom[i] == 1 && positionY[i] > 280) //해당 단어가 crazy word이며 화면 중앙보다 밑에 위치할 경우
            positionY[i] += 20;
    }

    /* 실패한 단어가 있는지 확인 후 hide 처리 및 시간 단축 */
    for(int i = 0; i < 6; i++)
    {
        if(positionY[i] >= 460) //입력창 바로 아래에 다다른 라벨이 있을 경우
        {
            wordLabel[i]->hide(); //숨김처리
            disWord[i] = ""; //저장된 단어 초기화
            leftTime = leftTime.addSecs(-3); //3초 단축 처리
            wordNum--; //단어 개수 업데이트
        }

        else
            continue;
    }

    /* 시간 표기 */
    ui->timerLCD->display(QString::number(leftTime.second()));

    /* 점수 표기 */
    ui->score->display(QString::number(score));
}
