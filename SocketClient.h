#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <WinSock2.h>
#include <fstream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

class SocketClient
{
public:
    SocketClient();
    void RecieveFile();                     //从服务器接受文件，更新本地bbs.txt
    void SendFile(ifstream& fin);     //向服务器发送本地文件bbs.txt
private:
    WORD sockVersion = MAKEWORD(2, 2);      //调用的WinSocket版本：2.2版 （支持多协议，且有良好的向后兼容性）
    SOCKET sclient;                         //套接字
    const u_short TCPPORT = 8888;           //TCP端口号
    const int BUFFERSIZE = 2048;            //接受buffer大小
    sockaddr_in serAddr;                    //远端服务地址--Internet的统一网络地址结构
};

#endif // SOCKETCLIENT_H
