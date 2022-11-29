#include "common.h"


void transact_with_client(int sock)
{
    char buf[100];
    int n;
    while(1)
    {
        bzero(buf,sizeof(buf));
        fgets(buf, sizeof(buf)-1, stdin);
        send(sock, buf, strlen(buf),0);

        n = recv(sock, buf, sizeof(buf),0);
        printf("Data: %s", buf);
    }

}
int main(int argc, char *argv[])
{
    struct sockaddr_in serv, cli;
    int port, sd, nsd;
    port = atoi(argv[1]); // port no. given as the 1st arg.
    sd = socket (AF_INET, SOCK_STREAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons (port); // because port is multi-byte value
    bind (sd, (struct sockaddr*)&serv, sizeof (serv));
  
     listen (sd, 5);   // sd is listening socket
      while( 1 )   // server runs forever
   {
      socklen_t size = sizeof(cli);
      nsd = accept (sd, (struct sockaddr*)&cli, &size);
       printf("Client Connected\n");
      transact_with_client(nsd);  // comm. with client is over
       close(nsd); // must be closed
  }
}
