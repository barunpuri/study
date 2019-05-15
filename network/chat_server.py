from socket import *
from threading import Thread
import sys
import os

id = 20153235
name = 'Jungkeun Cho'
print('Student ID : ' + str(id))
print('Name : ' + name)

serverPort = int(sys.argv[1])

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',serverPort))

MAX_SYNC_SOCKET = 16

connection_list = [0 for i in range(MAX_SYNC_SOCKET) ]

def connectingSocket(connectionSocket, addr):
    socketFD = connectionSocket.fileno() 
    connection_list[socketFD%MAX_SYNC_SOCKET] = connectionSocket
    
    print( 'connection from host {}, port {}, socket {}'.format(addr[0], addr[1], socketFD ) )
    
    while( True ):            
        msg = connectionSocket.recv(1024)
        
        if( not msg or msg == b'^]\r\n' ):
            connection_list[socketFD%MAX_SYNC_SOCKET] = 0
            print('Connection Closed {}'.format(socketFD))
            connectionSocket.close()
            return

        for sock in [s for s in connection_list if( type(s)==socket and s != connectionSocket )]:
            sock.send(msg)


#__main__:
            
try:
    while( 0 in connection_list ):
        serverSocket.listen(1)
        conn, addr = serverSocket.accept()
        t = Thread( target = connectingSocket, args = (conn, addr) )
        t.start()
    
except KeyboardInterrupt:
    serverSocket.close()
    sys.exit() 


serverSocket.close()
