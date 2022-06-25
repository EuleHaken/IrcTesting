#include "IrcClient.hpp"

IrcClient::IrcClient(QObject* parent)
    : QObject{parent}
{
    this->connect(this->socket, &QTcpSocket::connected, this,
                  &IrcClient::onConnected);

    this->connect(this->socket, &QTcpSocket::readyRead, this,
                  &IrcClient::onReadyRead);

    this->connect(this->socket, &QTcpSocket::errorOccurred, this,
                  &IrcClient::onError);
}

void IrcClient::onConnected()
{
    this->_isConnected = true;
    qInfo() << "Connected! (onConnected function called!)";
}

void IrcClient::sendRawMessage(const QString& message)
{
    this->socket->write(message.toUtf8());
    this->socket->flush();
    qDebug() << "Sent raw message: " << message;
}

void IrcClient::onError(const QTcpSocket::SocketError& error)
{
    switch (error)
    {
        case QAbstractSocket::HostNotFoundError: {
            qWarning() << "Host was not found! Closing...";
            this->socket->close();
            this->disconnect();
        }
        default: {
            qWarning() << "Unknown Socket Error thrown!";
        }
    }
}

void IrcClient::onReadyRead()
{
    const auto message = this->socket->readAll();
    //emit this->onIncomingMessage(message);
}

void IrcClient::connectToHost(const QString& address, quint16 port)
{
    this->socket->connectToHost(QHostAddress(address), port);
}

void IrcClient::onIncomingMessage(const QByteArray& data)
{
    QString message = data.data();
    qInfo() << "Incoming Message: " << message;
}
