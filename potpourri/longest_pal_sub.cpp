#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct type{ 
	int i,j,length;
};

struct type c[100][100];

int max(int a, int b){
	return a>b ? a:b;
}

void longest_palindrome_sequence(char * a,int n){
	int i,j,k,new_i,new_j,flag;
	char res[100];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j>=i)
				c[i][j].length=1;
			else
				c[i][j].length=0;
			
			c[i][j].i=-1;
			c[i][j].j=-1;
		}	
	}
	
	for(k=1;k<n;k++){
		for(i=0;i<n-k;i++){
			j=i+k;
			if(a[i]==a[j]){
				if(i+1<=j-1){
					c[i][j].length=2+c[i+1][j-1].length;
					c[i][j].i=i+1;
					c[i][j].j=j-1;
				}
				else{
					c[i][j].length=2;
					c[i][j].i=-1;
					c[i][j].j=-1;
				}				
			}			
			else{
				
				if(c[i+1][j].length>=c[i][j-1].length){
					c[i][j].length=c[i+1][j].length;
					c[i][j].i=i+1;
					c[i][j].j=j;
				}
				else{
					c[i][j].length=c[i][j-1].length;
					c[i][j].i=i;
					c[i][j].j=j-1;
				}
				
				//c[i][j].length=max(c[i][j+1].length,c[i+1])
			}
		}
	}
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
			printf("%d ",c[i][j].length);
		printf("\n");
	}
	k=0;
	i=0;
	j=n-1;
	while(1){
		new_i=c[i][j].i;
		new_j=c[i][j].j;
		if(new_i==i+1 && new_j==j-1){
			res[k]=a[i];
			k++;
		}
		else if(new_i==-1 && new_j==-1){
			if(c[i][j].length==1){
				res[k]=a[i];
				flag=0;
				k++;
			}
			else {
				res[k]=a[i];
				flag=1;
				k++;
			}
			break;
		}		
		i=new_i;
		j=new_j;
	}	
	for(i=0;i<k;i++)
		printf("%c",res[i]);
	if(flag==1){
		for(i=k-1;i>=0;i--)
			printf("%c",res[i]);
	}
	else if(flag==0){
		for(i=k-2;i>=0;i--)
			printf("%c",res[i]);
	}
	printf("\n%d\n",c[0][n-1].length);
	
}



int main(){
	
	int n;
	char * arr;
	scanf("%d",&n);
	arr=(char *)calloc(n,sizeof(char));
	scanf("%s",arr);
	printf("%s\n",arr);
	longest_palindrome_sequence(arr,n);
}
