#ifndef _CONNECTION_POOL_
#define _CONNECTION_POOL_

#include <stdio.h>
#include <list>
#include <mysql/mysql.h>
#include <error.h>
#include <string.h>
#include <iostream>
#include <string>
#include "../lock/locker.h"
#include "../log/log.h"

using namespace std;

class connection_pool
{
public:
    MYSQL *GetConnection();              // Get database connection
    bool ReleaseConnection(MYSQL *conn); // Release connection
    int GetFreeConn();                   // Get free connection
    void DestroyPool();                  // Destroy all connections

	// Singleton pattern
    static connection_pool *GetInstance();

    void init(string url, string User, string PassWord, string DataBaseName, int Port, int MaxConn, int close_log);

private:
    connection_pool();
    ~connection_pool();

    int m_MaxConn;  // Maximum number of connections
    int m_CurConn;  // Current number of used connections
    int m_FreeConn; // Current number of free connections
    locker lock;
    list<MYSQL *> connList; // Connection pool
    sem reserve;

public:
    string m_url;             // Host address
    string m_Port;            // Database port number
    string m_User;            // Username for database login
    string m_PassWord;        // Password for database login
    string m_DatabaseName;    // Name of the database in use
    int m_close_log;          // Log switch
};

class connectionRAII{

public:
	connectionRAII(MYSQL **con, connection_pool *connPool);
	~connectionRAII();
	
private:
	MYSQL *conRAII;
	connection_pool *poolRAII;
};

#endif
