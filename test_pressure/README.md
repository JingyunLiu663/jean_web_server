# Server Stress Testing
Webbench is a well-known website stress testing tool, which is developed by Lionbridge company.

- Tests the performance of different services on the same hardware, and the condition of the same service on different hardware.
- Displays two key metrics of the server: the number of requests responded to per second and the amount of data transferred per second.




Testing Rules
------------
* Testing Example

    ```C++
	webbench -c 500  -t  30   http://127.0.0.1/phpionfo.php
    ```
* Parameters

> * `-c` the number of clients
> * `-t` time