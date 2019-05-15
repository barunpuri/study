from socket import *
import sys
import os

id = 20153235
name = 'Jungkeun Cho'
print('Student ID : ' + str(id))
print('Name : ' + name)

serverPort = int(sys.argv[1])

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)

while( True ):
    print()
    connectionSocket, addr = serverSocket.accept()

    msg = connectionSocket.recv(1024).decode()
    print(msg)
    if( len(msg)<10 ): continue
    headers = msg.split('\r\n')
    
    file_name = '.{f_name}'.format(f_name = headers[0].split()[1] )
    file_data = ''
    response = 'Connection: close\r\n'
    response += 'ID: {id}\r\n'.format(id=id)
    response += 'Name: {name}\r\n'.format(name=name)
    
    if( os.path.isfile(file_name) ):
        response = 'HTTP/1.0 200 OK\r\n' + response
        f = open(file_name, 'r')
        file_data = f.read()
        f.close()
    else:
        response = 'HTTP/1.0 404 NOT FOUND' + response
        print("Server Error : No such file {fname}!".format(fname = file_name))

    response += 'Content-Length: {c_len}\r\n'.format(c_len = len(file_data))
    response += 'Content-Type: text/html\r\n\r\n'
    len_head = len(response)
    response += file_data
    
    print(msg, end='')
    len_send = connectionSocket.send(response.encode())
    print('finish {l_send} {l_file}'.format(l_send = len_send-len_head, l_file = len(file_data)))
    
    connectionSocket.close()

serverSocket.close()
