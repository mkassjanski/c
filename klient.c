#include <stdio.h>

#include <stdlib.h>

#include <fcntl.h>

#include <string.h>

#include <sys/stat.h>

#include <unistd.h>



#define MAX_BUF 4096



int main(int argc, char* argv[])

{

    int klient, serwer;

    char klientfifo[] = "kfifo";

    char serwerfifo[] = "sfifo";

    char msg[80], buf[10];

    struct stat st;



    // if no fifos, create 'em

    if (stat(klientfifo, &st) != 0)

        mkfifo(klientfifo, 0666);

    if (stat(serwerfifo, &st) != 0)

        mkfifo(serwerfifo, 0666);



    serwer= open(serwerfifo, O_WRONLY);

    klient= open(klientfifo, O_RDONLY);



int id;

printf("Podaj liczbe calkowita:\n");

scanf("%d", &id);

        write(serwer, &id, strlen(msg)+1);

char str[20];

if(read(klient, &str, MAX_BUF) > 0) {

	printf("%s", str);

	close(klient);

}

    // delete fifos

//    unlink(klientfifo);

//    unlink(fifo_name2);

    return EXIT_SUCCESS;

}



