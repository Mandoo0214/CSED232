/* 객체지향 프로그래밍 Assignment 5_20210479 이주현
 * 명예 서약(Honor Code): “나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.” */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QMessageBox>
#include <QTextEdit>
#include <QKeyEvent>
#include <QVector>
#include <QLabel>

#include <iostream>
#include <cstdlib>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void timeCount(); //시간을 재며 반복할 함수
    void haveFinished(); //시간 종료 시 메시지박스를 출력해주는 함수
    void selectCrazy(int index); //crazy_words에서 단어를 랜덤 선택해주는 함수 (index에 따라 초기 설정인지 게임 중 업데이트인지 구별 가능)
    void selectEasy(int index); //easy_words에서 단어를 랜덤 선택해주는 함수 (index에 따라 초기 설정인지 게임 중 업데이트인지 구별 가능)

    bool eventFilter(QObject* target, QEvent* event); //enter 키가 눌리는 이벤트를 감지해줄 함수

private:
    Ui::MainWindow *ui;
    QTimer *timer; //시간을 재기 위한 timer 객체 선언
    QTime leftTime; //30초로 초기 설정을 마친 qtime 객체 선언

    int whether = 0; //easy_words와 crazy_words 중 어디에서 단어를 랜덤 선택할지 골라주는 변수
    int wordNum = 0; //화면에 출력된 단어의 개수가 몇 개인지 세어주는 변수
    int wordInd = 0; //qstring 배열 내의 인덱스를 랜덤으로 선택하여 저장할 변수
    int score = 0; //타자게임 점수를 누적하여 합할 변수
    int delInd = -10; //사용자가 입력하여 사라진 단어가 있을 경우 해당 단어의 index를 저장할 변수

    /* 단어 목록 */
    QString easy_words[30] = {"명징", "직조", "갈증", "비행기", "나흗날", "비둘기", "옹달샘", "줄이다", "거울", "집오리",
                              "물리학", "토마토", "올리브", "은박지", "문지방", "물병", "양치질", "어린이", "집무실", "달빛",
                              "다르다", "부고", "낫", "서당", "참외", "사다리", "천지", "인바디", "어금니", "추격"};
    QString crazy_words[10] = {"숨마쿰라우데", "우거지다", "토지소유권", "하염없다", "도톰하다", "넓적부리", "타란티노",
                               "방울토마토", "객체지향수업", "컴퓨터공학과"};

    /* 타자 게임에 단어를 띄우기 위한 변수들 */
    QVector<QString> disWord; //현재 화면에 떠 있는 단어들을 저장하는 벡터
    QVector<int> wordFrom; //해당 단어들이 easy인지 crazy인지 저장하는 배열 (0이면 easy, 1이면 crazy)
    QVector<QLabel*> wordLabel; //단어와 QLabel을 연결해줄 벡터

    QVector<int> positionX; //각 라벨의 x축 위치를 저장할 벡터
    QVector<int> positionY; //각 라벨의 y축 위치를 저장할 벡터

    /* 사용한 private 함수들 */
    void connectWithVector(); //QLabel을 담은 Vector와 Vector 연결
    void whenPressEnter(); //Enter가 눌렸을 경우 게임을 진행하기 위한 함수
    void typingGame(); //단어를 랜덤으로 선택해 라벨로 출력하기 위한 함수 (+ 각 라벨을 움직이게 함)
};

#endif // MAINWINDOW_H
