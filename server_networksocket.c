#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

    int server_desc, client_desc;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len;
    char buffer_to_server[1024], buffer_to_client[1024];


int createsocket();
int bindsocket();
int listensocket();
int acceptsocket();
int communicate();
void goback();
void close_clientsocket();
void close_serversocket();

int main() {

    // Socket erstellen
    createsocket();

    // Server-Adresse konfigurieren
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Socket an Adresse binden
    bindsocket();

    // Auf Verbindungen warten
    listensocket();

    // Client akzeptieren
    acceptsocket();
    // Daten empfangen und senden
    communicate();

    // Sockets schließen
    close_clientsocket();
    close_serversocket();

    return 0;
}
int createsocket()
{   server_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (server_desc < 0)
    {
        printf("Socket konnte nicht erstellt werden");
        return -1;
    }
    printf("Socket konnte erfolgreich erstellt werden");
}
int bindsocket()
{   if(bind(server_desc, (struct sockaddr*) &server_address, sizeof(server_address)) < 0)
    {
        printf("\nBind konnte nicht erstellt werden");
        return -1;
    }
        printf("\nBind zum Port wurde durchgeführt. Warten auf einkommende Verbindungen.");
}    
    
int listensocket()
{
    if(listen(server_desc, 3) < 0)
    {
        printf("\nBefehl Listen konnte nicht durchgeführt werden");
        return -1;
    }
        printf("\n(Ein wildes Client ist aufgetaucht!)");
}

int acceptsocket()
{
    client_len = sizeof(client_address);
    client_desc = accept(server_desc, (struct sockaddr*) &client_address, &client_len);

    if (client_desc < 0)
    {
        printf("\nClient konnte nicht akzeptiert werden");
        return -1;
    }
        printf("\nClient wurde verbunden\n");
}

int communicate()
{
    while(1)
    {
        memset(buffer_to_server, 0, sizeof(buffer_to_server));
        recv(client_desc, buffer_to_server, sizeof(buffer_to_server), 0);
        
        if ((strcmp(buffer_to_server, "exit\n") == 0) || (strcmp(buffer_to_server, "") == 0))
        {
            printf("Verbindung zu Client verloren");
            goback();
        }
    
        
        printf("Server hat vom Client erhalten:  %s", buffer_to_server);


        printf("Bitte Nachricht zum Versenden eingeben:");
        fgets(buffer_to_client, sizeof(buffer_to_client), stdin);
        send(client_desc, buffer_to_client, strlen(buffer_to_client), 0);

        if (strcmp(buffer_to_client, "kick\n") == 0) 
        {
            //goto funktioniert leider nur innerhalb der gleichen Funktion
            goback();
        }
        if (strcmp(buffer_to_client, "shutdown\n") == 0)
        {
            break;
        }
        else
        { 
        printf("Message has been sent. Please wait...\n");
        }
    }

    
}
void goback()
{
    listensocket();
    acceptsocket();
    communicate();  
}

void close_clientsocket()
{
    close(client_desc);
}

void close_serversocket()
{
    close(server_desc);
}
