#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
    
    int client_desc;
    struct sockaddr_in server_address;
    char buffer_to_server[1024], buffer_to_client[1024];
    int checksum = 0; 

    int createsocket ();
    void connectsocket ();
    int communicate ();
    void closesocket();

int main() {

    createsocket();

    //Serveradresse konfigurieren
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("192.168.189.119");  //IP vom Server

    connectsocket();
  
    if (checksum != -1)
    {
    communicate();


    closesocket();
    }
    return 0;
}

int createsocket()
{
    client_desc = socket(AF_INET, SOCK_STREAM, 0);
}
void connectsocket()
{
    if(connect(client_desc, (struct sockaddr*) &server_address, sizeof(server_address)) < 0)
    {
        printf("Verbindung zu Server nicht möglich");
        checksum = -1;
    }
}

int communicate()
{
    while(1) {
        printf("Bitte Nachricht zum Versenden eingeben: ");
        fgets(buffer_to_server, sizeof(buffer_to_server), stdin);     
        send(client_desc, buffer_to_server, strlen(buffer_to_server), 0);

        if (strcmp(buffer_to_server, "exit\n") == 0)
        {
            break;
        }
        printf("Message has been sent. Please wait...\n");

        memset(buffer_to_client, 0, sizeof(buffer_to_client));
        recv(client_desc, buffer_to_client, sizeof(buffer_to_client), 0);
        if ((strcmp(buffer_to_client, "kick\n") == 0) || (strcmp(buffer_to_client, "") ==0 ))
        {
            printf("Keine Verbindung zum Server");
            break;
        }
        printf("Client hat folgende Nachricht erhalten: %s", buffer_to_client);
    }
}

void closesocket()
{
    close(client_desc);
}

