
# Half-Sync/Half-Reactive Thread Pool
The use of a work queue completely decouples the main thread from the worker threads: the main thread inserts tasks into the work queue, and the worker threads compete to fetch and execute these tasks.

- Synchronous I/O simulates Proactor pattern
- Half-Sync/Half-Reactive
- Thread Pool
