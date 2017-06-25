#include "appcore.h"

AppCore::AppCore(QObject *parent) : QObject(parent), sock()
{
    sock.connectToHost("185.195.24.240", 8001);
    QObject::connect(&sock, &QTcpSocket::readyRead, this, &AppCore::read);
}

void AppCore::read(){
    std::cout << "1111\n";
    QByteArray mess_res;
    QString text;
    double time;
    mess_res = sock.readAll();
    std::string reply;

    reply = mess_res.toStdString();
    emit res(QString::fromStdString(reply));
    std::cout << reply << std::endl;
//    time = json::prep_time(reply);
//    emit res(QString::number(time));
//    text = "Reply is: " + QString::fromStdString(reply) + QString(", size: %1 \n").arg(reply.size());
//    text += "Time: " + QString::number(time) + "\n";
//    std::cout << text.toStdString();

}

void AppCore::send(){
    double time;

    QString text;
    int len;
    std::pair<double, double> coordinates{55.1234, 34.1200};

    std::vector<std::pair<unsigned, unsigned>> list;
    list.push_back(std::pair<unsigned, unsigned> {1, 1});
    list.push_back(std::pair<unsigned, unsigned> {333, 88});
//    for(auto it = list.begin(); it < list.end(); ++it)
//    std::cout << std::get<0>(*it) << " " << std::get<1>(*it) << std::endl;

    std::string json_list = json::prepare(coordinates, list);

//    mess_res.fromStdString(json_list);
    len = sock.write(json_list.c_str());
//    s.send(boost::asio::buffer(json_list, json_list.length()));
//    std::cout << "write: " << json_list << std::endl;
    text = "Write: " + QString::fromStdString(json_list) + "\n";
    std::cout << text.toStdString();
}
