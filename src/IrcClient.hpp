#pragma once

#include <QObject>
#include <QTcpSocket>

class IrcClient : public QObject
{
    Q_OBJECT
public:
    explicit IrcClient(QObject* parent = nullptr);

signals:
    void onIncomingMessage(const QByteArray& data);

public slots:
    void connectToHost(const QString& address, const quint16 port);

private slots:
    void onConnected();
    void onReadyRead();
    void onError(const QTcpSocket::SocketError& error);

public:
    void sendRawMessage(const QString& message);
    QTcpSocket* socket;

private:
    bool _isConnected{false};
};
