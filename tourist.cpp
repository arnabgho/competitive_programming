#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>



struct point {
	long long int x;
	long long int y;
	struct point * next;
};

struct help{
	long long int val;
	long long int in_len;
	long long int out_len;
	struct point * in_list;
	struct point * out_list;
 };

struct point * insertAtBeginning(long long int x,long long int y,struct point * list){
	struct point * dummy;
	dummy=(struct point *)calloc(1,sizeof(struct point));
	dummy->x=x;
	dummy->y=y;
	dummy->next=list;
	list=dummy;
	return list;
}

long long int arr[101][101];
struct help a[101][101];

int main(){
	char ch; 		
	long long int h,w,i,j,k,c,t,in_val1,in_val2,out_val1,out_val2,in_com,out_com,in_out_com1,in_out_com2;
	struct point * dummy;
	scanf("%lld",&t);
	c=0;
	while(c++<t){
		scanf("%lld %lld\n",&h,&w);
		for(i=1;i<=h;i++){			
			for(j=1;j<=w;j++){
				scanf("%c",&ch);
				a[i][j]->out_list=NULL;
				a[i][j]->in_list=NULL;
				a[i][j].in_len=0;	
				a[i][j].out_len=0;
				if(ch=='*'){
					arr[i][j]=1;
				}
				else if(ch=='.'){
					arr[i][j]=0;
				}
				else if(ch=='#'){
					arr[i][j]=-1;
				}
			}
			if(i!=h)
				scanf("\n");
		}
		

		for(i=1;i<=w;i++){
			if(arr[i-1][1]==-1){
				a[i][1].val=-1;
			}
				
			else{
				if(arr[i-1][1]==0){
					a[i][1].val=a[i-1][1].val;
					a[i][1]->in_list=a[i-1][1]->in_list;
					a[i][1]->out_list=a[i-1][1]->out_list;
					a[i][1].in_len=a[i-1].in_len;
					a[i][1].out_len=a[i-1].out_len;
				}	
				else if(arr[i-1][1]==1){
					a[i][1].val=a[i-1][1].val+1;
					a[i][1]->in_list=insertAtBeginning(i,1,a[i-1][1]->in_list);
					a[i][1]->out_list=insertAtBeginning(i,1,a[i-1][1]->out_list);
					a[i][1].in_len=a[i-1][1].in_len+1;
					a[i][1].out_len=a[i-1][1].out_len+1;
				}
			}
		}	
		for(j=1;j<=h;j++){
			if(arr[1][j]==-1){
				a[1][j].val=-1;
			}
				
			else{
				if(arr[1][j-1]==0){
					a[1][j].val=a[1][j-1].val;
					a[1][j]->in_list=a[1][j-1]->in_list;
					a[1][j]->out_list=a[1][j-1]->out_list;
					a[1][j].in_len=a[1][j-1].in_len;
					a[1][j].out_len=a[1][j-1].out_len;
				}	
				else if(arr[1][j-1]==1){
					a[1][j].val=a[1][j-1].val+1;
					a[1][j]->in_list=insertAtBeginning(1,j,a[1][j-1]->in_list);
					a[1][j]->out_list=insertAtBeginning(1,j,a[1][j-1]->out_list);
					a[1][j].in_len=a[1][j-1].in_len+1;
					a[1][j].out_len=a[1][j-1].out_len+1;
				}
			}
		}

		for(i=2;i<=h;i++){
			for(j=2;j<=w;j++){
				if(arr[i-1][j]==-1  && arr[i][j-1]==-1){
					a[i][j].val=-1;
					a[i][j]->in_list=NULL;
					a[i][j]->out_list=NULL;
					a[i][j].in_len=0;
					a[i][j].out_len=0;
				}
				else if(arr[i-1][j]!=-1 && arr[i][j-1]==-1){
					a[i][j].val=a[i-1][j]+arr[i][j];
					if(arr[i][j]==1){
						a[i][j]->in_list=insertAtBeginning(i,j,a[i-1][j]->in_list);
						a[i][j]->out_list=insertAtBeginning(i,j,a[i-1][j]->out_list);
						a[i][j].in_len=a[i-1][j].in_len+1;
						a[i][j].out_len=a[i-1][j].out_len+1;								
					}
					else{
						a[i][j]->in_list=a[i-1][j]->in_list;
						a[i][j]->out_list=a[i-1][j]->out_list;
						a[i][j].in_len=a[i-1][j].in_len;
						a[i][j].out_len=a[i-1][j].out_len;
					}
				}

				else if(arr[i-1][j]==-1 && arr[i][j-1]!=-1){
					a[i][j].val=a[i][j-1]+arr[i][j];
					if(arr[i][j]==1){
						a[i][j]->in_list=insertAtBeginning(i,j,a[i][j-1]->in_list);
						a[i][j]->out_list=insertAtBeginning(i,j,a[i][j-1]->out_list);
						a[i][j].in_len=a[i][j-1].in_len+1;
						a[i][j].out_len=a[i][j-1].out_len+1;
					}
					else{
						a[i][j]->in_list=a[i][j-1]->in_list;
						a[i][j]->out_list=a[i][j-1]->out_list;
						a[i][j].in_len=a[i][j-1].in_len;
						a[i][j].out_len=a[i][j-1].out_len;
					}
				}
				
				else if(arr[i-1][j]!=-1 && arr[i][j-1]!=-1){
															
					in_val1=a[i-1][j].in_len;
					in_val2=a[i][j-1].in_len;
					out_val1=a[i-1][j].out_val;
					out_val2=a[i][j-1].out_val;

				}
			}
		}

	}		
	return 0;
}
