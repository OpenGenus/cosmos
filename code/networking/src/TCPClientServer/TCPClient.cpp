#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


#define TRUE 0
#define ERROR 1
#define CLOSED 2


using namespace std;



class TCPClient
{

private:
		int clientfd,connectionStatus;
		int createSocket();
		int connectToServer(int port,char *ip);
public:
		TCPClient();
		int start(int port,char * ip);
		int recieveData(char *buffer,int size);
		int sendData(char* data);
		bool isConnected();
		int stop();

};

TCPClient::TCPClient(){
	connectionStatus=1;
}

int TCPClient::createSocket()
{
	clientfd=socket(AF_INET,SOCK_STREAM,0);

	if(clientfd==-1)
	{
		perror("Error occured:");
		return ERROR;
	}
	else
	{
		return TRUE;
	}

}


int TCPClient::connectToServer(int port,char * ip)
{
		struct sockaddr_in serv_address;
		serv_address.sin_family=AF_INET;
		serv_address.sin_port=htons(port);
		serv_address.sin_addr.s_addr=inet_addr(ip);

		int connectRet = connect(clientfd,(struct sockaddr *)&serv_address,sizeof(serv_address));
		
		if(connectRet==-1)
		{
			connectionStatus=ERROR;
			perror("Error occured:");
			return ERROR;
		}
		else
		{
			connectionStatus=TRUE;
			return TRUE;
		}


}


int TCPClient::start(int port,char *ip)
{
//validate inputs
		if(port<0 || port>65536)
		{
			cout<<"Enter valid input :"<<endl;
			return ERROR;
		}

		// if(strlen(ip)<15 || strlen(ip)<7)
		// {
		// 	cout<<"Enter valid input :"<<endl;
		// 	return ERROR;
		// }

		int ret=createSocket();
		if(ret==ERROR){
			cout<<"Error occured while creating the socket"<<endl;
			return ERROR;
		}

		ret=connectToServer(port,ip);
		if(ret==ERROR){
			connectionStatus=ERROR;
			cout<<"Error occured while connecting to server"<<endl;
			return ERROR;
		}


		return TRUE;


}

int TCPClient::recieveData(char *buffer,int size)
{
	//validate input

		int ret=recv(clientfd,buffer,size,0);
		if(ret==-1){
			cout<<"Error occured"<<endl;
			return ERROR;
		}
		else if(ret==0){
			connectionStatus=ERROR;
			cout<<"Peer Terminated"<<endl;
			return ERROR;
		}
		else{
			return TRUE;
		}
	
}

int TCPClient::sendData(char *data)
{
	//validate data
	if(data==NULL){
		cout<<"Enter valid data to be sent "<<endl;
		return ERROR;
	}

	int ret=send(clientfd,data,strlen(data),0);
	if(ret==-1){
		return ERROR;
	}
	else{

		return TRUE;
	}
}


int TCPClient::stop()
{
	int ret=close(clientfd);
	if(ret==-1){
		perror("Error occured :");
		return ERROR;
	}
	return TRUE;
}

bool TCPClient::isConnected(){
	return connectionStatus;
}

int main(){

	TCPClient c;
	char* data=(char *)"Hello from client1\n";
	char buffer[1024];
	int ret=c.start(12345,(char*)"127.0.0.1");
	if(ret==TRUE){

		//while(1){
			ret=c.sendData(data);
			sleep(1);
			if(ret==TRUE){
				cout<<"Data Sent SSuccessfully"<<endl;
			}

			ret=c.recieveData(buffer,1024);
			if(ret==TRUE)
				cout<<buffer;
		//}
	}


	return 0;
}