#include "SocketClient.h"
#include <iostream>
#include <WinSock2.h>
#include <fstream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

SocketClient::SocketClient()
{
}

void SocketClient::RecieveFile(){
    WSADATA data;
    if (WSAStartup(sockVersion, &data) != 0) {
        cerr << "WSAStartup failed:" << GetLastError() << endl;
        return ;
    }

    sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);    ////IPV4,TCP,Э����0
    if (sclient == INVALID_SOCKET) {
        cerr << "Socket Error!" << endl;
        return ;
    }
    serAddr.sin_family = AF_INET;   //��ַ��-IPV4
    serAddr.sin_port = htons(TCPPORT); //htons�������ֽ���ת��Ϊ�����ֽ���
    serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //ָ��32λIP��ַΪ��ȷ����ַ127.0.0.1
    if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) {
        //����ʧ��
        cerr << "Connected Error!" << endl;
        closesocket(sclient);
        return ;
    }

    const char* sendData = "hi!";
    send(sclient, sendData, strlen(sendData), 0);

    char recData[BUFFERSIZE];
    int ret = recv(sclient, recData, BUFFERSIZE, 0);
    if (ret > 0) {
        recData[ret] = 0x00;
    }

    ofstream fout;
    fout.open("bbs.txt");
    if(!fout)   {return ;}
    string str(recData);
    cout << str;
    fout.write(recData,strlen(recData));

    fout.close();

    closesocket(sclient);       //�ر�socketͨ��
    WSACleanup();
}
