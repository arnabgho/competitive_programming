#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct matrix{
	long long int val;
	long long int pos;
	struct matrix * next;
};
struct matrix * mat[101];
int main(){
	long long int i,j,row,col,start,val;
	struct matrix *temp,*curr;
	printf("Enter the number of rows and colums in the matrix\n");
	scanf("%lld %lld",&row,&col);
	printf("Enter the matrix\n");
	for(i=1;i<=row;i++){
		//mat[i]=NULL;
		start=0;
		for(j=1;j<=col;j++){
			scanf("%lld",&val);
			if(val!=0){
				temp=(struct matrix *)calloc(1,sizeof(struct matrix));
				
				
				if(start==0){
					start=1;
					temp->next=NULL;
					temp->pos=j;
					temp->val=val;
					curr=temp;
					mat[i]=temp;
				}
				else{
					temp->val=val;
					temp->next=NULL;
					temp->pos=j;
					curr->next=temp;
					curr=temp;
				}
			}
		}
		if(start==0)
			mat[i]=NULL;
	}
	for(i=1;i<=row;i++){
		printf("The matrix entries in the row %lld are :\n",i);
		temp=mat[i];
		while(temp!=NULL){
			printf("The entry at (i,j)=(%lld,%lld) is %lld\n",i,temp->pos,temp->val);
			temp=temp->next;			
		}
		printf("------------------------------\n");
	}
	return 0;
}
