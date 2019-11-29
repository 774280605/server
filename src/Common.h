//
// Created by zxf on 2019/11/28.
//

#ifndef SERVER_COMMON_H
#define SERVER_COMMON_H

#ifdef WIN32
#define zxf_socklen int
#else
#include <sys/socket.h>
#define zxf_socklen socklen_t
#endif




#endif //SERVER_COMMON_H
