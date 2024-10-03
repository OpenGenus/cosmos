# Socket Programming using C Language in Linux operating system.

## The client server model

Most interprocess communication uses the client server model. These terms refer to the two processes which will be communicating with each other. One of the two processes, the client, connects to the other process, the server, typically to make a request for information.  


The client needs to know of the existence of and the address of the server, but the server does not need to know the address of (or even the existence of) the client prior to the connection being established. Once a connection is established, both sides can send and receive information. 
The system calls for establishing a connection are somewhat different for the client and the server, but both involve the basic construct of a socket. A socket is one end of an interprocess communication channel. The two processes each establish their own socket. 


### The steps involved in establishing a socket on the client side are as follows: 
    1. Create a socket with the socket() system call 
    2. Connect the socket to the address of the server using the connect() system call 
    3. Send and receive data. There are a number of ways to do this, but the simplest is to use the read() and write() system calls. 

### The steps involved in establishing a socket on the server side are as follows: 
    1. Create a socket with the socket() system call 
    2. Bind the socket to an address using the bind() system call. For a server socket on the Internet, an address consists of a port number on the host machine. 
    3. Listen for connections with the listen() system call 
    4. Accept a connection with the accept() system call. This call typically blocks until a client connects with the server. 
    5. Send and receive data 



### Running the server side program

```sh
$ gcc server.c -o server
$ ./server 8080
```

### Running the client side program

```sh
$ gcc client.c -o client
$ ./client 127.0.0.1 8080
```


[Click here for more and detailed information about Socket Programming](http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html)





