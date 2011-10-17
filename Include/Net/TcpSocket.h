/**
 *
 *       @file  TcpSocket.h
 *
 *      @brief  C++ wrapper for the socket library
 *
 *    @version  1.0
 *       @date  10/10/2011 14:47:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef TCP_SOCKET_H__
#define TCP_SOCKET_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include <Net/SocketErrors.h>

class TcpSocket {
public:
    /**
     * @brief default constructor
     */
    TcpSocket();

    TcpSocket(int socketfd);

    /**
     * @brief connects to the host on port
     * @param host : the host
     * @param the port
     * @return SOSUCC if succeded
     * 		   SOCOPEN if socket could not be opened
     * 		   SONHOST if host not found
     * 		   SOCONN if could not connect to host
     *
     */
    int connect(string host, unsigned short port);

    /**
     * @brief sends a string over the net
     * @return 0 if successful
     */
    int sendString(const string &str);

    /**
     * @brief sends an int over the net
     * @return 0 if successful
     */
    int sendInt(const int &i);

    /**
     * @brief sends a short over the net
     * @return 0 if successful
     */
    int sendShort(const short &i);

    /**
     * @brief sends a char over the net
     * @return 0 if successful
     */
    int sendChar(const char &c);

    /**
     * @brief sends a char array over the net
     * @return 0 if successful
     */
    int sendCharArray(const char* c);

    int receiveString(string &str);

    int receiveInt(int &i);

    int receiveShort(short& s);

    int receiveChar(char &c);

    int receiveCharArray(char **c);

    /**
     * @brief disconnects from the host
     * @return code
     */
    int close();

private:
    int m_socketfd;
    int m_portNo;
    struct sockaddr_in m_servAddr;
    struct hostent *m_server;

};

#endif