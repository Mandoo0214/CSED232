/* 객체지향 프로그래밍 Assignment 5_20210479 이주현
 * 명예 서약(Honor Code): “나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.” */
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
