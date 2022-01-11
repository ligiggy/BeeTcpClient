#include "beetcpclient.h"
#include "qdebug.h"
#include "qmutex.h"
#include "qwaitcondition.h"


class BeeTcpClientPrivate
{
public:
    QString m_ip = "127.0.0.1";
    int m_port = 1001;

    const int m_maxConnectTime = 5000;

    bool m_bConnected = false;

    QMutex m_mutexConnect;
    QWaitCondition *m_waitConditionConnect;

};


BeeTcpClient::BeeTcpClient(QObject *parent)
    : QTcpSocket(parent)
    , d_ptr(new BeeTcpClientPrivate)
{
    d_ptr->m_waitConditionConnect = new QWaitCondition();

    threadTcp = new QThread(this);
    QObject::connect(threadTcp, &QThread::started, this, &BeeTcpClient::connect, Qt::DirectConnection);
    QObject::connect(threadTcp, &QThread::finished, this, &QTcpSocket::deleteLater);

}

BeeTcpClient::~BeeTcpClient()
{

}

void BeeTcpClient::setHostServer(QString ip, int port)
{
    d_ptr->m_ip = ip;
    d_ptr->m_port = port;
}

bool BeeTcpClient::connectServer()
{
    d_ptr->m_mutexConnect.lock();

    this->moveToThread(threadTcp);
    threadTcp->start();

    d_ptr->m_waitConditionConnect->wait(&d_ptr->m_mutexConnect);

    d_ptr->m_mutexConnect.unlock();

    return d_ptr->m_bConnected;
}

void BeeTcpClient::connectServer(QString ip, int port)
{
    d_ptr->m_ip = ip;
    d_ptr->m_port = port;

    this->moveToThread(threadTcp);
    threadTcp->start();
}

void BeeTcpClient::connect()
{
    connectToHost(d_ptr->m_ip, d_ptr->m_port, QIODevice::ReadWrite);

    d_ptr->m_bConnected = waitForConnected(d_ptr->m_maxConnectTime);

    d_ptr->m_waitConditionConnect->wakeOne();
}

void BeeTcpClient::disconnect()
{
    disconnectFromHost();

    threadTcp->terminate();
    threadTcp->wait();
}

void BeeTcpClient::writeMsg(QByteArray data)
{
    if(!d_ptr->m_bConnected)
    {
        return;
    }

    write(data);
}

void BeeTcpClient::readMsg(QByteArray &data)
{
    if(!d_ptr->m_bConnected)
    {
        return;
    }

    data = readAll();
}
