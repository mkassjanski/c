#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_BUF 4096

int main(int argc, char* argv[])
{
int klient, serwer;
int buf, i, x=0;
char num[3];
char nazw[20];
char klientfifo[] = "klientfifo";
char serwerfifo[] = "serwerfifo";
mkfifo(serwerfifo, 0666);
serwer = open(serwerfifo, O_RDONLY);
klient = open(klientfifo, O_WRONLY);

typedef struct osoba {
int id;
char nazwisko[20];
} osoba;

osoba osoby[20];

for(i=0; i<20; i++) {
	osoby[i].id = i;
	sprintf(num, "%d", i);
	strncpy(nazw, "Nazwisko", 10);
	strncat(nazw, num, 3);
	strncpy(osoby[i].nazwisko, nazw, 19);
}
while (1)
    {
        if (read(serwer, &buf, MAX_BUF) > 0)
        {
for(i=0; i<20; i++) {
if(osoby[i].id == buf) {
x=0; break;
}
else {
x=1;
}
}
	int p = fork();
		if(x==0) {
		write(klient, osoby[buf].nazwisko, sizeof(osoby[i].nazwisko));
		kill(p, SIGKILL);
        	}
		else {
		write(klient, "Nie znaleziono", sizeof("Nie znaleziono"));
		kill(p, SIGKILL);
		}
}
}
}
