
//TCP CLIENT SIDE CODE

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

int main()
{  
 int socket_descf;
 struct structure_IN server_addr;
 char *mesg=" hello from client_telg";
 char buffer[2000];
 
 if(socket_desc=socket(AF-INET, SOCK-STREAM, 0)<0)
 {
	 printf("socket creation failed \n");
	 return -1;
 }
  printf("socket created sucessfully!! \n");
  
  server_addr.sin_family=AF-INET;
  server_addr.sin_port=htons(2024);
   server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
   
  if(connect(socket_descf, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
  {
	  printf("connection failed \n");
	  return -1;
  }
   printf("connection done sucessfully! \n");
  
 
   if(recv(socket_descf,buffer, sizeof(buffer),0)<0)
   {
	  printf("reciving message failed \n");
	  return -1;
  }
  
   printf("recived messgae is  \n");
   
   if(send(socket_descf, mesg, strlen(mesg),0)<0)
   {
	  printf("sending message failed \n");
	  return -1;
  }
   printf("client side message has been sent to server \n");
	  
close(socket_descf);

return 0;
}
