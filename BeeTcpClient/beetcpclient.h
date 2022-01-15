#ifndef BEETCPCLIENT_H
#define BEETCPCLIENT_H

#include <QTcpSocket>
#include <QThread>

class BeeTcpClientPrivate;
class BeeTcpClient: public QTcpSocket
{
    Q_OBJECT
public:
    explicit BeeTcpClient(QObject *parent = Q_NULLPTR);
    ~BeeTcpClient();


public:
    void setHostServer(QString ip, int port);
    bool connectServer();
    void connectServer(QString ip, int port);
    void disconnect();

    bool isConnected();

    void writeMsg(QByteArray data);

    void readMsg(QByteArray &data);

private:
    void connect();


private:
    QThread *threadTcp = nullptr;

    QScopedPointer<BeeTcpClientPrivate> d_ptr;

};

#endif // BEETCPCLIENT_H
