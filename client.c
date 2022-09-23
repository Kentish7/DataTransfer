#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int main(){

    int networkSocket;
    // AF_IFNET = IPV4 PROTOCOL / SOCK_STREAM = TCP PROTOCOL
    networkSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; // address family
    serverAddress.sin_port = htons(9002); // port nunmber
    serverAddress.sin_addr.s_addr = INADDR_ANY; // any internet address;

    int connection_status  = connect(networkSocket, (struct sockaddr *) &server_address, sizeof(serverAddress));

    if (connection_status == -1)  {
    printf("Error! \n\n");
    }

    // recieve data from server;
    char serverResponse[256];

    recv(networkSocket, &serverResponse, sizeof(serverResponse), 0);

    // print out the server's response
    printf("The server sent the data: %s\n", serverResponse);

    // close
    close(networkSocket); 
return 0;
}
