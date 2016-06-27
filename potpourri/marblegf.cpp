#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<math.h>

using namespace std;

long long int f[1000001];
long long int c[1000001];
long long int tree[1000001];


long long int read(long long int idx){
	long long int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(long long int idx ,long long int val,long long int MaxVal){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main(){
		
	long long int i,j,k,n,q,cum,ca;
	char ch;	
	scanf("%lld %lld",&n,&q);
	cum=0;
	for(i=1;i<=n;i++){
		//scanf("%lld",&f[i]);
		cin>>f[i];		
		cum+=f[i];	
		c[i]=cum;
	}

	for(j=1;j<=n;j++){
		k=(j & -j);
		//printf("%lld\n",j & -j);
		tree[j]=c[j]-c[j-k];
		//printf("%lld %lld\n",k,tree[j]);
	}

	

	//printf("I m here\n");
	for(ca=1;ca<=q;ca++){
		cin>>ch>>i>>j;
		//printf("%c\n",ch);
		if(ch=='S'){
			j++;
			i++;
			cout<<read(j)-read(i-1)<<endl;			
		}
		else if(ch=='G'){
			i++;
			update(i,j,n);		
		}

		else if(ch=='T'){
			i++;
			update(i,-j,n);
		}
	}	
	return 0;
}
