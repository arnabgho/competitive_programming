#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct entry{
	long long int val;
	long long int semi;
	long long int pos;
};

struct entry a[100001];
struct entry b[100001];
long long int resa[100001];
long long int resb[100001]; 
struct entry temp[200001];
int main(){

	long long int n,i,k,x,y,z;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){	
		scanf("%lld %lld",&a[i].val,&b[i].val);
		a[i].semi=1;
		b[i].semi=2;
		a[i].pos=i;
		b[i].pos=i;	
	}
	for(k=0;2*k<=n;k++){
		x=k+1;
		y=k+1;
		z=1;
		while(x+y<=2*n){
			if(a[x].val<=b[y].val){
				temp[z]=a[x];
				x++;
				z++;
			}
			else{
				temp[z]=b[y];
				z++;
				y++;					
			}
		}
		
		for(i=1;i<=k;i++){
			resa[i]=1;
			resb[i]=1;	
		}
		
		for(i=1;i<=n-2*k;i++){
			if(temp[i].semi==1){
				resa[temp[i].pos]=1;
				
			}
			else if(temp[i].semi==2){
				resb[temp[i].pos]=1;			
			}
		}
	}
	
	for(i=1;i<=n;i++){
		printf("%lld",resa[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("%lld",resb[i]);
	}
	printf("\n");
	return 0;
}
