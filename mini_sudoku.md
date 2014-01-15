Program na podstawie klasycznego sudoku, ale w wersji mini.
```sh
#include<stdio.h>

main()
{
int tab[3][3]={{3,2,1},{1,3,2},{1,2,3}};
int i,w,j,a=0,b=0,c=0; //a=jedynki, b=dwojki, c=trojki

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++)
	printf("%3d",tab[i][j]); 
	printf("\n"); }

	for(i=0; i<3; i++) {
		a=0; b=0; c=0; w=0;
		for(j=0; j<3; j++){
		if(tab[i][j]==1) a++;
		if(tab[i][j]==2) b++;
		if(tab[i][j]==3) c++; }
		
		if(a!=1 || b!=1 ||c!=1) w++;
	}
	
	
	for(i=0; i<3; i++) {
		a=0; b=0; c=0;
		for(j=0; j<3; j++){
		if(tab[j][i]==1) a++;
		if(tab[j][i]==2) b++;
		if(tab[j][i]==3) c++; }
		
		if(a!=1 || b!=1 ||c!=1) w++;
}
if(w==0) printf("Jest\n");
else printf("Nie jest\n");
}
```
