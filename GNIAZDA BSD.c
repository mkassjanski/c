/*
    C ECHO client example using sockets
*/
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include <netinet/in.h>
#include <sys/types.h>
#include <signal.h>
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
 //   char message[1000] , server_reply[2000];
    int slen = sizeof(server); 
    //Create socket
    sock = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("153.19.1.202");
    server.sin_family = AF_INET;
    server.sin_port = htons( 5000 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
//char message[1000];
//char server_reply[2000];
//while(1){
  //      printf("Enter message : ");
    //    scanf("%s" , message);
//if( send(sock, message, strlen(message) , 0) < 0)
//{
//	puts("Send Failed");
//	return 1;
//}
//	else {
//	puts("JEblo");
//	}
        //Receive a reply from the server
  //      if( recv(sock , server_reply , 2000 , 0) < 0)
    //    {
      //      puts("recv failed");
        //    break;
        //}
         
       // puts("Server reply :");
       // puts(server_reply);
   // 
	int buff;
	printf("Podaj liczbe");
	scanf("%d" , &buff);
	printf("Buff to %d\n", buff);
	buff = htonl(buff);
	printf("Buff htonl to %d\n", buff);
while(1){
	printf("Wysyłam bufor na serwer... \n");
	if (sendto(sock, (char*) &buff, sizeof(int),0, (struct sockaddr *) &server, sizeof(server)) == -1) {
		printf("Błąd \n");
	}
	printf("Czekam na odp \n");
    recvfrom(sock,(char *) &buff,sizeof(int),0,(struct sockaddr *) &server,&slen);
	buff = ntohl(buff);
	printf("Wynik to: %d\n", buff);
	break;
}

   // if (inet_aton("153.19.1.240", &server.sin_addr) == 0) {
     //   fprintf(stderr, "inet_aton() failed\n");
      //  return 5;
   // }
   // else{
//	puts("LOL\n");
  // }
    //keep communicating with server
 //   while(1)
   // {
     //   printf("Enter message : ");
      //  scanf("%s" , message);
         
        //Send some data
       // if( send(sock , message , strlen(message) , 0) < 0)
       // {
        //    puts("Send failed");
         //   return 1;
       // }
         
        //Receive a reply from the server
       // if( recv(sock , server_reply , 2000 , 0) < 0)
       // {
         //   puts("recv failed");
          //  break;
       // }
         
      //  puts("Server reply :");
       // puts(server_reply)   // }l
     
    close(sock);
    return 0;
}
