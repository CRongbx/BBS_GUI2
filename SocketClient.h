#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

class SocketClient
{
public:
    SocketClient();
    void RecieveFile();
private:
    WORD sockVersion = MAKEWORD(2, 2);      //���õ�WinSocket�汾��2.2�� ��֧�ֶ�Э�飬�������õ��������ԣ�
    SOCKET sclient;                         //�׽���
    const u_short TCPPORT = 8888;           //TCP�˿ں�
    const int BUFFERSIZE = 2048;            //����buffer��С
    sockaddr_in serAddr;                    //Զ�˷����ַ--Internet��ͳһ�����ַ�ṹ
};

#endif // SOCKETCLIENT_H
