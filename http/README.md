
# HTTP Connection Handling Class
Based on state transitions, the HTTP connection class is encapsulated using master and slave state machines. The master state machine internally calls the slave state machine, which then passes processing status and data back to the master state machine.
- The client initiates an HTTP connection request
- The slave state machine reads data, updates its own status and received data, and passes it to the master state machine
- The master state machine updates its own status based on the slave state machine's status, deciding whether to respond to the request or continue reading