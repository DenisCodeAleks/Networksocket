
▄▄▄█████▓ ▄████▄   ██▓███    ██████  ▒█████   ▄████▄   ██ ▄█▀▓█████▄▄▄█████▓
▓  ██▒ ▓▒▒██▀ ▀█  ▓██░  ██▒▒██    ▒ ▒██▒  ██▒▒██▀ ▀█   ██▄█▒ ▓█   ▀▓  ██▒ ▓▒
▒ ▓██░ ▒░▒▓█    ▄ ▓██░ ██▓▒░ ▓██▄   ▒██░  ██▒▒▓█    ▄ ▓███▄░ ▒███  ▒ ▓██░ ▒░
░ ▓██▓ ░ ▒▓▓▄ ▄██▒▒██▄█▓▒ ▒  ▒   ██▒▒██   ██░▒▓▓▄ ▄██▒▓██ █▄ ▒▓█  ▄░ ▓██▓ ░ 
  ▒██▒ ░ ▒ ▓███▀ ░▒██▒ ░  ░▒██████▒▒░ ████▓▒░▒ ▓███▀ ░▒██▒ █▄░▒████▒ ▒██▒ ░ 
  ▒ ░░   ░ ░▒ ▒  ░▒▓▒░ ░  ░▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ░ ░▒ ▒  ░▒ ▒▒ ▓▒░░ ▒░ ░ ▒ ░░   
    ░      ░  ▒   ░▒ ░     ░ ░▒  ░ ░  ░ ▒ ▒░   ░  ▒   ░ ░▒ ▒░ ░ ░  ░   ░    
  ░      ░        ░░       ░  ░  ░  ░ ░ ░ ▒  ░        ░ ░░ ░    ░    ░      
         ░ ░                     ░      ░ ░  ░ ░      ░  ░      ░  ░by denis       
         ░                                   ░                     


# 🌐 Network Socket Communication 🌐

This repository contains a simple client-server application written in C for network socket communication.

## 📁 Files:

1. **`client_networksocket.c`**: A simple network client that connects to a server, sends messages, and receives responses.
2. **`server_networksocket.c`**: A counterpart network server that listens for client connections, accepts messages, and sends back responses.

## 🚀 How to Test:

1. **Compile the Server and Client**:
   ```bash
   gcc server_networksocket.c -o server
   gcc client_networksocket.c -o client
   ```

2. **Run the Server**:
   ```bash
   ./server
   ```
   The server will bind to any available interface on port `8080` and will start listening for incoming client connections.

3. **Run the Client**:
   ```bash
   ./client
   ```
   The client will attempt to connect to the server located at IP `192.168.189.119` on port `8080`. Once connected, you can type messages to send to the server.

4. **End the Communication**:
   - On the client side, type `exit` and press enter to terminate the connection.
   - The server will close the connection with a client if it receives a message `kick`.

## 🚢 Deployment:

1. Ensure you have a C compiler like `gcc` installed.
2. Follow the testing steps to compile and run the server and client.
3. You may want to modify the hardcoded IP address in the client file if your server has a different IP address.
4. Deploy the server on a machine that is accessible to the client. Ensure that port `8080` is open and not blocked by any firewall or security group.
5. Run the client from any machine to communicate with the server.

