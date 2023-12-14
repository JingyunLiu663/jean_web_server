#ifndef CONFIG_H
#define CONFIG_H

#include "webserver.h"

using namespace std;

class Config
{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char*argv[]);

    // Port number
    int PORT;

    // Log writing method
    int LOGWrite;

    // Trigger combination mode
    int TRIGMode;

    // Trigger mode for listen file descriptor (listenfd)
    int LISTENTrigmode;

    // Trigger mode for connection file descriptor (connfd)
    int CONNTrigmode;

    // Graceful shutdown of connection
    int OPT_LINGER;

    // Number of database connection pool
    int sql_num;

    // Number of threads in the thread pool
    int thread_num;

    // Whether to close logging
    int close_log;

    // Concurrency model selection
    int actor_model;
};

#endif