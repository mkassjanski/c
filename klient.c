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
    char klientfifo[] = "klientfifo";
    char serwerfifo[] = "serwerfifo";
    char msg[20];
    struct stat st;

    if (stat(klientfifo, &st) != 0)
        mkfifo(klientfifo, 0666);

    serwer= open(serwerfifo, O_WRONLY);
    klient= open(klientfifo, O_RDONLY);

int id;
printf("Podaj liczbe calkowita:\n");
scanf("%d", &id);
        write(serwer, &id, sizeof(id));
if(read(klient, &msg, sizeof(msg)) > 0) {
	printf("%s", msg);
	close(klient);
}
    return EXIT_SUCCESS;
}
