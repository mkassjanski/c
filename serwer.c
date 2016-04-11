#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define MAX_BUF 4096

int main(int argc, char* argv[])
{
    int klient, serwer;
    int buf, i, x=0;
    char num[3];
    char nazw[20];

    char klientfifo[] = "kfifo";
    char serwerfifo[] = "sfifo";
    serwer= open(serwerfifo, O_RDONLY);
    klient= open(klientfifo, O_WRONLY);

typedef struct osoba {
int id;
char nazwisko[20];
} osoba;

osoba tab[20];

for(i=0; i<20; i++) {
	tab[i].id = i+1;
	sprintf(num, "%d", i);
	strncpy(nazw, "Nazwisko", 10);
	strncat(nazw, num, 3);
	strncpy(tab[i].nazwisko, nazw, 19);
//	printf("%d: %s\n", tab[i].id, tab[i].nazwisko);
}
    // receive messages
    while (1)
    {
        if (read(serwer, &buf, MAX_BUF) > 0)
        {
for(i=0; i<20; i++) {
if(tab[i].id == buf) {
x=0; break;}
else {x=1;}
}
	int sid = fork();
		if(x==0) {
		    write(klient, tab[buf].nazwisko, sizeof(tab[i].nazwisko));
		    kill(sid, SIGKILL);
        	}
		else {
		    write(klient, "nie znaleziono", sizeof("nie znaleziono"));
		    kill(sid, SIGKILL);
		}
	}
    }
}
