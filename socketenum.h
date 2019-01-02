#ifndef SOCKETENUM_H
#define SOCKETENUM_H
/* ����socket��״̬ö�� */
struct SocketEnum{
    typedef enum{
        //��������
        Invalid,    //��Ч����
        TCP,
        UDP
    }SocketType;

    typedef enum{
        //Socket��������
        Error = -1,
        Success = 0,
        InvalidSocket,
        InvalidAddress,
        InvalidPort,
        ConnectionRefused,  //���ӱ��ܾ�
        Timedout,   //���ӳ�ʱ
        NotConnected,
        Interrupted,
        ConnectionAborted,  //������ֹ
        ProtocolError,  //Э�����
        InvalidBuffer,  //��������Ч
        ConnectionReset,    //��������
        AddressInUse,
        InvalidPointer,
        WSAStartupError,
        BindError,
        ListenError,
        UnknownError
    }SocketError;

    typedef enum{
        //ͨ�ŷ���
        Receives = 0,
        Sends = 1,
        Both = 2
    }ShutdownMode;
};

#endif // SOCKETENUM_H
