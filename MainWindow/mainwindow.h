#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

#include "beetcpclient.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void init();

private slots:
    void on_Pb_Connect_clicked();

    void on_Pb_Close_clicked();

    void on_Pb_Write_clicked();

    void on_Pb_Read_clicked();

signals:
    void closeConnect();
    void writeData(QByteArray data);
    void readData(QByteArray &data);

private:
    BeeTcpClient *tcpClient = nullptr;

    QMutex mutex;
    QWaitCondition *waitCondition;

    QString strRecvMsg = "";

private:
    void connect();

    void readMsg();

    void isConnected(bool connected);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
