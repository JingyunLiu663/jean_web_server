#include "config.h"

Config::Config(){
    // Port number, default is 9006
    PORT = 9006;

    // Log writing method, default is synchronous
    LOGWrite = 0;

    // Trigger combination mode, default is listenfd LT + connfd LT
    TRIGMode = 0;

    // Trigger mode for listenfd, default is LT
    LISTENTrigmode = 0;

    // Trigger mode for connfd, default is LT
    CONNTrigmode = 0;

    // Graceful shutdown of connection, default is not used
    OPT_LINGER = 0;

    // Number of database connection pools, default is 8
    sql_num = 8;

    // Number of threads in the thread pool, default is 8
    thread_num = 8;

    // Whether to close logging, default is not closed
    close_log = 0;

    // Concurrency model, default is proactor
    actor_model = 0;
}

void Config::parse_arg(int argc, char*argv[]){
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
        {
            PORT = atoi(optarg);
            break;
        }
        case 'l':
        {
            LOGWrite = atoi(optarg);
            break;
        }
        case 'm':
        {
            TRIGMode = atoi(optarg);
            break;
        }
        case 'o':
        {
            OPT_LINGER = atoi(optarg);
            break;
        }
        case 's':
        {
            sql_num = atoi(optarg);
            break;
        }
        case 't':
        {
            thread_num = atoi(optarg);
            break;
        }
        case 'c':
        {
            close_log = atoi(optarg);
            break;
        }
        case 'a':
        {
            actor_model = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}