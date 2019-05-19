from socket import *
from threading import Thread
import sys
import os
import time

id = 20153235
name = 'Jungkeun Cho'
print('Student ID : ' + str(id))
print('Name : ' + name)

serverPort = int(sys.argv[1])

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',serverPort))

MAX_SYNC_SOCKET = 16

connection_list = []
serverSocket.listen(1)

def connectingSocket(connectionSocket, addr):
    socketFD = connectionSocket.fileno() 
    connection_list.append( connectionSocket )
    
    print( 'connection from host {}, port {}, socket {}'.format(addr[0], addr[1], socketFD ) )
    
    while( True ):            
        msg = connectionSocket.recv(1024)
        
        if( not msg or msg == b'^]\r\n' or msg == b'\xff\xf4\xff\xfd\x06' ):
            connection_list.remove( connectionSocket )
            print('Connection Closed {}'.format(socketFD))
            connectionSocket.close()
            return

        for sock in [s for s in connection_list if( s != connectionSocket )]:
            sock.send(msg)
    


#__main__:      
try:
    while( True ):
        conn, addr = serverSocket.accept()
        if(len(connection_list) >= MAX_SYNC_SOCKET ):
            conn.close()
            continue
        t = Thread( target = connectingSocket, args = (conn, addr), daemon = True )
        t.start()
        
    
except KeyboardInterrupt:
    for s in connection_list:
        s.close()
    serverSocket.close()
    sys.exit() 

for s in connection_list:
    s.close()
serverSocket.close()
sys.exit()
