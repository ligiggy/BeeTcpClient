#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    waitCondition = new QWaitCondition();
}

void MainWindow::on_Pb_Connect_clicked()
{
    if(tcpClient != nullptr)
    {
        emit closeConnect();
    }

    tcpClient = new BeeTcpClient();
    QObject::connect(tcpClient, &BeeTcpClient::readyRead, this, &MainWindow::readMsg, Qt::DirectConnection);
    QObject::connect(this, &MainWindow::writeData, tcpClient, &BeeTcpClient::writeMsg, Qt::BlockingQueuedConnection);
    QObject::connect(this, &MainWindow::closeConnect, tcpClient, &BeeTcpClient::disconnect, Qt::QueuedConnection);

    tcpClient->setHostServer("127.0.0.1", 9001);

    bool bConnected = tcpClient->connectServer();

    if(bConnected)
    {
        ui->textEdit->append(u8"connected success");
    }
    else
    {
        ui->textEdit->append(u8"connected fail");
    }
}

void MainWindow::on_Pb_Close_clicked()
{
    emit closeConnect();
}


void MainWindow::readMsg()
{
    QByteArray buffer = tcpClient->readAll();

    qDebug() << "read data" << buffer;

    strRecvMsg = buffer.data();

    waitCondition->wakeOne();
}


void MainWindow::isConnected(bool connected)
{
    if(connected)
    {
        qDebug() << "connected success";
    }
    else
    {
        qDebug() << "connected fail";

        emit closeConnect();
    }
}

// if you don't need to wait, just emit the signal;
void MainWindow::on_Pb_Write_clicked()
{
    emit writeData(ui->lineEdit->text().toLocal8Bit());

    mutex.lock();

    if(!waitCondition->wait(&mutex, 10000))
    {
        qDebug() << "timeout";
        mutex.unlock();
        return;
    }

    mutex.unlock();

    ui->textEdit->append(strRecvMsg);
}

void MainWindow::on_Pb_Read_clicked()
{
    QByteArray ba;

    emit readData(ba);

    QString strData = ba.data();

    QStringList strList = strData.split(',');

    ui->textEdit->append(ba.data());
}
