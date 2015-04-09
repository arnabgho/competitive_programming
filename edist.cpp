#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a, int b, int c) {
	return ((a<b) ? ((a<c) ? a : c) : ((b<c) ? b : c));
}

int max(int a, int b) {
	return ((a>b) ? a : b);
}
/*
int main() {

	char a[3000];
	char b[3000];
	int temp, i, j, al, bl, c, t, **d;
	c=0;
	scanf("%d",&t);
	while (c++<t) {

		scanf("%s", a);
		scanf("%s", b);
		al=strlen(a);
		bl=strlen(b);
		d=(int**)calloc(al+1, sizeof(int*));
		for (i=0; i<=al; i++) {
			*(d+i)=(int *)calloc(bl+1, sizeof(int));

		}
		for (i=0; i<=al; i++) {
			d[i][0]=i;
		}
		for (j=0; j<=bl; j++) {
			d[0][j]=j;
		}

		for (i=1; i<=al; i++) {

			for (j=1; j<=bl; j++) {
				if (a[i-1]==b[j-1])
					temp=0;
				else
					temp=1;

				d[i][j]=min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+temp);

			}
		}
		printf("%d\n",d[al][bl]);
		for (i=0; i<=al; i++) {
			free (*(d+i));

		}
		free(d);
	}

	return 0;
}

*/
int main() {

	//char a[3000];
	//char b[3000];
	int temp, i, j, al, bl, c, t, **d,*a,*b,nx,ny;
	c=0;
	scanf("%d",&t);
	while (c++<t) {

		//scanf("%s", a);
		//scanf("%s", b);
		//al=strlen(a);
		//bl=strlen(b);

		scanf("%d",&al);
		a=(int *)calloc(al,sizeof(int));
		for(i=0;i<al;i++)
			scanf("%d",&a[i]);

		scanf("%d",&bl);
		b=(int *)calloc(bl,sizeof(int));
		for(i=0;i<bl;i++)
			scanf("%d",&b[i]);
	

		d=(int**)calloc(al+1, sizeof(int*));
		for (i=0; i<=al; i++) {
			*(d+i)=(int *)calloc(bl+1, sizeof(int));

		}
		for (i=0; i<=al; i++) {
			d[i][0]=i;
		}
		for (j=0; j<=bl; j++) {
			d[0][j]=j;
		}

		for (i=1; i<=al; i++) {

			for (j=1; j<=bl; j++) {
				if (a[i-1]==b[j-1])
					temp=0;
				else
					temp=1;

				d[i][j]=min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+temp);

			}
		}
		printf("%d\n",d[al][bl]);
		for (i=0; i<=al; i++) {
			free (*(d+i));

		}
		free(d);
	}

	return 0;
}
