Program odwracający kolejnośc cyfr w liczbie.
```sh
#include<stdio.h>

int odw(int a, int n) {
	if(a==0) return n;
	return odw(a/10,n*10+a%10);
}

main()
{
	printf("Podaj liczbe:");
	int a,n=0;
	scanf("%d",&a);
	printf("%d\n",odw(a,n));
}
```
