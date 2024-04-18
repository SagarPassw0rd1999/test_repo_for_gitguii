
//TCP SERVER SIDE CODE

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

int main()
{  
 int socket_desc, new_socket;
 int len_c=sizeof(client_addr);
 struct structure_IN server_addr, client_addr;
 char *mesg=" hello from server_bang";
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
   
  if(bind(socket_desc, (strSuct sockaddr*)&server_addr, sizeof(server_addr))<0)
  {
	  printf("Binding failed \n");
	  return -1;
  }
   printf("Binding done sucessfully! \n");
  
  if(listen(socket_desc,5)<0);
   {
	  printf("listening failed \n");
	  return -1;
  }
   printf("listening done sucessfully! \n");
   
   if(new_socket=accept(socket_desc,(struct sockaddr*)&server_addr, &len_c)<0)
   {
     printf("accepting the connection has failed \n");
	  return -1;
   }
   printf("connection accepted sucessfully! \n");
   
   if(recv(new_socket,buffer, sizeof(buffer),0)<0)
   {
	  printf("reciving message failed \n");
	  return -1;
  }
   printf("recived messgae is  \n");
   
   if(send(new_socket,mesg, strlen(mesg),0)<0)
   {
	  printf("sending message failed \n");
	  return -1;
  }
   printf("server side message has been sent to client \n");
	  
close(socket_desc);
close(new_socket);

return 0;
}
