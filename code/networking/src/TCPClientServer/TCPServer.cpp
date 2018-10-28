#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <vector>
#include <algorithm>


#define TRUE 0
#define ERROR 1
#define CLOSED 2


using namespace std;


class TCPServer{

private:
		int serverSocket;
		vector<int> clientFds;
		int createSocket();
		int bindSocket(int port);
		int listenSocket(int backlogs);

public:
		int start(int port , int backlogs);
		int acceptConnection(int *fd);
		int recieveData(char *buffer,int size);
		int sendData(int *fd,char *data);
		int closeClientConnection(int fd);
		int stop();
};

int TCPServer::createSocket(){

		serverSocket =socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK,0);
		if(serverSocket==-1){
			perror("Socket Fail");
			return ERROR;
		}
		else{
			return TRUE;
		}

}

int TCPServer::bindSocket(int port){

		struct sockaddr_in address;
		address.sin_family = AF_INET;
   		address.sin_addr.s_addr = INADDR_ANY;
    	address.sin_port = htons( port );


	 	if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address))==-1)
	    {
	        perror("bind failed");
	        return ERROR;
	    }
	    else
	    {
	    	return TRUE;
	    }

    

}

int TCPServer::listenSocket(int backlogs){

	if (listen(serverSocket, backlogs) == -1)
    {
        perror("listen");
		return ERROR;
    }
    else{
    	return TRUE;
    }

}

int TCPServer::start(int port,int backlogs){
	int ret=createSocket();
	if(ret==ERROR){
		cout<<"Error in creatinig Socket"<<endl;
		return ERROR;
	}

		int opt=1;
     if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT , &opt, sizeof(opt))==-1)
    {
        perror("setsockopt");
		return ERROR;

	}

	ret=bindSocket(port);
	if(ret==ERROR){
		cout<<"Error in binding Socket"<<endl;
		return ERROR;
	}

	ret=listenSocket(backlogs);
	if(ret==ERROR){
		cout<<"Error in binding Socket"<<endl;
		return ERROR;
	}

	return TRUE;
}

int TCPServer::acceptConnection(int *fd){
	
	int clientSocket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	clientSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	if(clientSocket>0){
		clientFds.push_back(clientSocket);
		*fd=clientSocket;
		cout<<"Got the request from "<<clientSocket<<endl;
		return TRUE;
	}

	else{
		return ERROR;
	}


}

int TCPServer::recieveData(char *buffer,int size){
		int bytesRead;
		for(int i=0;i<clientFds.size();i++){
			
			bytesRead=recv(clientFds[i],buffer,size,MSG_DONTWAIT);
			if(bytesRead==0){
				cout<<"Peer Terminated";
				//sleep(2);
				//closeClientConnection(clientFds[i]);

				clientFds.erase(clientFds.begin()+i);
				return ERROR;
			}

			if(bytesRead>0){
				cout<<"Data read as "<<buffer;
				return TRUE;
			}

			if(bytesRead==-1){
				return ERROR;
			}
		}

		return ERROR;

}

int TCPServer::sendData(int *fd,char *data){

	if(data==NULL){
		cout<<"Enter valid data to be sent "<<endl;
		return ERROR;
	}
	int ret=send(*fd,data,strlen(data),MSG_DONTWAIT);
	if(ret>0)
		return TRUE;
	else{
		return ERROR;
	}
}

int TCPServer::closeClientConnection(int fd){
	int ret=close(fd);
	if(ret==-1){
		return ERROR;
	}
	else{
		return TRUE;
	}
}

int TCPServer::stop(){


	int ret=close(serverSocket);
	if(ret==-1){
		return ERROR;
	}
	else{
		return TRUE;
	}
}


int main(){

	TCPServer s;
	int clientfd=0;
	int *fd=&clientfd;
	char* data=(char *)"Hello from server\n";
	char buffer[1024]={0};
	int ret=s.start(12345,3);
	if(ret==TRUE){
		while(1){
			ret=s.acceptConnection(fd);
			if(ret==TRUE){
					cout<<"ClientFD"<<*fd<<endl;
					//sleep(3);
				}
			ret=s.recieveData(buffer,1024);
			if(ret==TRUE){
				cout<<"Hello";
				cout<<buffer<<endl;
			}
			sleep(2);
			ret= s.sendData(fd,data);
				if(ret==TRUE){
				cout<<"DAta sent succcessfully";
			}
				
			memset(buffer,0,sizeof(buffer));

		}	
	}

	return 0;
}
