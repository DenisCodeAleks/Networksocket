
//Socket-Server auf dem Raspberry Pi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len;
    char buffer[1024];

    // Socket erstellen
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Server-Adresse konfigurieren
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Socket an Adresse binden
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Auf Verbindungen warten
    listen(server_socket, 5);

    // Client akzeptieren
    client_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_len);

    // Daten empfangen und senden
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Server received: %s\n", buffer);
    send(client_socket, "Hello from Server!", sizeof("Hello from Server!"), 0);

    // Sockets schließen
    close(client_socket);
    close(server_socket);

    return 0;
}