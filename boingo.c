#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h> // for inet_ntoa()


//Im making this program becaue I am fed up with Boingo

int rawSock;
struct sockaddr_in;

int main (int argc, char* argv[]){
  char* buffer = (char*) malloc(65535); //max size of packet
  rawSock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);

  if(rawSock < 0){printf("failed socket - quiting\n"); return -1;}

  int num_packets = 0;
  while(num_packets < 500){
    int data_size = recvfrom(rawSock, buffer , 65536 , 0 , NULL, NULL);
    if(data_size <= 0){printf("no packet - quiting\n"); return -1;}
    printf("%d packet received, size %d\n", num_packets, data_size);
    num_packets++;
  }
  close(rawSock);
  return 1;
}
