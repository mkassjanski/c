Program wypisuje wszystkie liczby doskonałe mniejsze od 1000.
```sh
#include<stdio.h>
int dosk(int s) {
		int a=6;
		int i;
		while(a<1000) {
		s=1;
		for(i=a-1; i>1; i=i-1) {
			if(a%i==0) s=s+i;
	} if(s==a) printf("%d\n",s); a=a+1;
}
}

main()
{
	int s,i,a;
	dosk(s);
}
```
