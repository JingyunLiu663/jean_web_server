
# A Light Web Server
A lightweight Web server in C++ for Linux, facilitating beginners to quickly practice network programming and build their own server.

- Uses a concurrency model with thread pool + non-blocking socket + epoll (both ET and LT implemented) + event handling (both Reactor and simulated Proactor implemented)
- Utilizes state machines to parse HTTP request messages, supporting the parsing of GET and POST requests
- Access to the server's database to implement web-side user registration and login functionality; can request server images and video files
- Implements a synchronous/asynchronous logging system to record the server's operational status
- Has undergone Webbench stress testing and can achieve tens of thousands of concurrent connections for data exchange

## user instructions
- Confirm MySQL database is installed before testing

    ```C++
    // Create yourdb database
    create database yourdb;

    // Create user table
    USE yourdb;
    CREATE TABLE user(
        username char(50) NULL,
        passwd char(50) NULL
    )ENGINE=InnoDB;

    // Insert data
    INSERT INTO user(username, passwd) VALUES('name', 'passwd');
    ```

- Modify the database initialization information in main.cpp

    ```C++
    //Database login name, password, database name
    string user = "root";
    string passwd = "root";
    string databasename = "yourdb";
    ```

- build

    ```C++
    sh ./build.sh
    ```

- start server

    ```C++
    ./server
    ```

- Client-side browser

    ```C++
    ip:9006
    ```

## Personalized Execution

```C++
./server [-p port] [-l LOGWrite] [-m TRIGMode] [-o OPT_LINGER] [-s sql_num] [-t thread_num] [-c close_log] [-a actor_model]
```

Reminder: Not all the above parameters are mandatory parameters. Please apply according to personal needs

- -p, custom port number
    - Default is 9006
- -l, choose the log writing method, default is synchronous writing
    - 0, synchronous writing
    - 1, asynchronous writing
- -m, the combination of modes for listenfd and connfd, default is LT + LT
    - 0, means using LT + LT
    - 1, means using LT + ET
    - 2, means using ET + LT
    - 3, means using ET + ET
- -o, graceful shutdown of connection, not used by default
    - 0, not used
    - 1, used
- -s, the number of database connections
    - Default is 8
- -t, number of threads
    -  Default is 8
- -c, close log, open by default
    - 0, open logging
    - 1, close logging
- -a, choose reactor model, default is Proactor
    - 0, Proactor model
    - 1, Reactor model

### sample command

```C++
./server -p 9007 -l 1 -m 0 -o 1 -s 10 -t 10 -c 1 -a 1
```

- -p 9007 sets the server to listen on port 9007.
- -l 1 configures the server to write logs asynchronously.
- -m 0 selects the LT (Level Trigger) + LT mode for the listen file descriptor (listenfd) and connection file descriptor (connfd).
- -o 1 enables graceful shutdown of connections.
- -s 10 establishes a pool of 10 connections to the database.
- -t 10 creates a thread pool with 10 threads.
- -c 1 turns off logging.
- -a 1 uses the Reactor model for handling events.
