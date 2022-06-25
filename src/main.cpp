#include "IrcClient.hpp"

#include <QCoreApplication>

/*
void onMessage(const QByteArray& data)
{
    QString message = data.data();
    qInfo() << "Incoming Message (own definition): " << message;
}
*/

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    //IrcClient client(a.parent());
    //client.connectToServer(QHostAddress("irc.chat.twitch.tv"), 6697);

    IrcClient client;
    //client.connect(client.socket, &QTcpSocket::readyRead, &onIncomingMessage);

    client.connectToHost("irc.chat.twitch.tv", 6697);
    client.sendRawMessage("NICK justinfan123111");

    return a.exec();
}
