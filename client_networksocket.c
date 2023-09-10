#include <sys/types.h>
#include <sys/socket.h>
//Headerdateien alte Version BSD
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //Schnittstellen UNIX Standard Bibliothek
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h> 


int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024];

    // Socket erstellen
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Server-Adresse konfigurieren
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("192.168.36.90"); 
    // Mit Server verbinden
    connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Daten senden und empfangen
    send(client_socket, "Hello from Client!", sizeof("Hello from Client!"), 0);
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Client received: %s\n", buffer);

    // Socket schließen
    close(client_socket);

    return 0;
}