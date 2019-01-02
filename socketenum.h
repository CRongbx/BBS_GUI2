#ifndef SOCKETENUM_H
#define SOCKETENUM_H
/* 定义socket的状态枚举 */
struct SocketEnum{
    typedef enum{
        //定义类型
        Invalid,    //无效类型
        TCP,
        UDP
    }SocketType;

    typedef enum{
        //Socket错误类型
        Error = -1,
        Success = 0,
        InvalidSocket,
        InvalidAddress,
        InvalidPort,
        ConnectionRefused,  //连接被拒绝
        Timedout,   //连接超时
        NotConnected,
        Interrupted,
        ConnectionAborted,  //连接中止
        ProtocolError,  //协议错误
        InvalidBuffer,  //缓冲区无效
        ConnectionReset,    //重新连接
        AddressInUse,
        InvalidPointer,
        WSAStartupError,
        BindError,
        ListenError,
        UnknownError
    }SocketError;

    typedef enum{
        //通信方向
        Receives = 0,
        Sends = 1,
        Both = 2
    }ShutdownMode;
};

#endif // SOCKETENUM_H
