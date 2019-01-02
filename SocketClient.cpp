#include "SocketClient.h"
#include <iostream>
#include <WinSock2.h>
#include <string>
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

    sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);    ////IPV4,TCP,协议编号0
    if (sclient == INVALID_SOCKET) {
        cerr << "Socket Error!" << endl;
        return ;
    }
    serAddr.sin_family = AF_INET;   //地址族-IPV4
    serAddr.sin_port = htons(TCPPORT); //htons将主机字节序转换为网络字节序
    serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //指定32位IP地址为不确定地址127.0.0.1
    if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) {
        //连接失败
        cerr << "Connected Error!" << endl;
        closesocket(sclient);
        return ;
    }

    const char* sendData = "hi";
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
    fout.write(recData,strlen(recData));

    fout.close();

    closesocket(sclient);       //关闭socket通信
    WSACleanup();
}

void SocketClient::SendFile(ifstream& fin){
    WSADATA data;
    if (WSAStartup(sockVersion, &data) != 0) {
        cerr << "WSAStartup failed:" << GetLastError() << endl;
        return ;
    }

    sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);    ////IPV4,TCP,协议编号0
    if (sclient == INVALID_SOCKET) {
        cerr << "Socket Error!" << endl;
        return ;
    }
    serAddr.sin_family = AF_INET;   //地址族-IPV4
    serAddr.sin_port = htons(TCPPORT); //htons将主机字节序转换为网络字节序
    serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  //指定32位IP地址为不确定地址127.0.0.1
    if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) {
        //连接失败
        cerr << "Connected Error!" << endl;
        closesocket(sclient);
        return ;
    }

    /* const char* sendBBS = "This bbs.txt\n";
    send(sclient,sendBBS,strlen(sendBBS),0);*/

    string str;
    int j = 0;
    char sendData[BUFFERSIZE];      //send buffer
    while (getline(fin,str)) {
        for (int i = 0; i < str.length(); i++, j++)
            sendData[j] = str[i];
        sendData[j++] = '\n';
    }
    sendData[j] = '\0';
    send(sclient, sendData, strlen(sendData), 0);

    closesocket(sclient);       //关闭socket通信
    WSACleanup();
}
