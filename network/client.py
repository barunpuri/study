from socket import *
import select

id = 20153235
name = 'Jungkeun Cho'
print('Student ID : ' + str(id))
print('Name : ' + name)

while( True ):
    print()
    print('>', end = '')
    cmd = list(map(str, input().split()))
    
    if( len(cmd) == 0 ):
        continue
    elif( cmd[0].lower() == 'quit' ):
        exit()
    elif( cmd[0] == 'wget' ):
        serverName = cmd[1]
        serverPort = int(cmd[2])
        image = cmd[3]
        
        clientSocket = socket(AF_INET, SOCK_STREAM)

        try:
            clientSocket.connect((serverName,serverPort))
        except Exception as e:
            print(serverName + ": unknown host")
            print("cannot connect to server " + serverName + " " + cmd[2])
            continue
        
        msg = 'GET ' + image + ' HTTP/1.0'
        msg += '\r\nHost: ' + serverName + '\r\n'
        msg += 'User-agent: HW1/1.0\r\n'
        msg += 'ID: '+ str(id) +'\r\n'
        msg += 'Name: '+ name + '\r\n'
        msg += 'Connection: close\r\n'
        msg += '\r\n'
        
        clientSocket.send(msg.encode('utf-8'))

        reply = clientSocket.recv(1024)

        headers =  reply.split(b'\r\n\r\n')[0]
        check = headers.decode().split('\r\n')[0]
        msg_code = check.split()[1]
        error_msg = check.split(msg_code)[1]
        
        #print(msg_code)
        
        if(msg_code == '200'):
            contentLen =  reply.split(b'Content-Length: ')[1]
            size = int(contentLen.split(b'\r\n')[0])
            
            print("Total Size " + str(size) + " bytes")
            i = 1
            
            image = reply[len(headers)+4:]
            
            while( True ):
                data = clientSocket.recv(1024)
                if not data:
                    break
                image += data
                if(len(image) >= i*size/10):
                    i += 1
                    print("Current Downloading " + str(len(image)) + "/" + str(size) + " (bytes) " + str(int(100*len(image)/size)) + "%")
                
            print("Download Complete: " + cmd[3].split('/')[-1] + ", " + str(size) + "/" + str(size))

            # save image
            f = open(cmd[3].split('/')[-1], 'wb')
            f.write(image)
            f.close()

        else:
            print(msg_code + error_msg)
            continue
        
        
clientSocket.close()

#wget netapp.cs.kookmin.ac.kr 80 /web/member/palladio.JPG
#wget s3.amazonaws.com 80 /american-rivers-website/wp-content/uploads/2015/09/22182724/NW-rivers-threatened-by-Red-Flat-Systems_KenMorrish-header-713x629.jpg

#fc9f7f1e776d405cbd87fd787dc1cc54
