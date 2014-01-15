Program sprawdza czy wczytana liczba jest pierwsza.
```sh
#include<stdio.h>
char pierwsza(int a, int n) {
		if (a==1) return printf("Liczba nie jest pierwsza\n");
		else if (a%n!=0) return pierwsza(a, n+1);		
		else if(a==n) printf("Liczba pierwsza\n");	
		else if(a%n==0) printf("Liczba zlozona\n");
	}

main()
{
	int a,n=2;
	
	printf("Podaj liczbe od 1 do 10000\n");
	scanf("%d",&a);
	printf("%c",pierwsza(a,n));
}
```
