#include "config.h"

int main(int argc, char *argv[])
{
    // Database information that needs to be modified: login name, password, and database name
    string user = "root";
    string passwd = "root";
    string databasename = "qgydb";

    // Command line parsing
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    // Initialization
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    

    // Logging
    server.log_write();

    // Database
    server.sql_pool();

    // Thread pool
    server.thread_pool();

    // Trigger mode
    server.trig_mode();

    // Listening
    server.eventListen();

    // Running
    server.eventLoop();

    return 0;
}