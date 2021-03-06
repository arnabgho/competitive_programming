#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	long long int val,pos;
	struct node* next;
	struct node* prev;
};

struct ret_val{
	struct node* arr;
	long long int total;
};

struct ret_val * InsertAtPosition(struct node * arr,long long int value,long long int position){
	struct node * temp,*temp1,*temp2;
	struct ret_val * res;
	long long int max;
	res=(struct ret_val *)calloc(1,sizeof(struct ret_val));
	temp=(struct node *)calloc(1,sizeof(struct node));	
	temp->val=value;
	temp->pos=position;
	max=1;
	if(position==1){
		temp->next=arr;
		arr->prev=temp;
		temp->prev=NULL;
		temp1=arr;
		arr=temp;
		while(temp1!=NULL){
			temp1->pos=temp1->pos+1;
			if(temp1->pos>max){
				max=temp1->pos;
			}
			temp1=temp1->next;
		}
	}
	else{
		temp1=arr;
		while(temp1->pos!=position-1){
			temp1=temp1->next;
		}
		temp2=temp1->next;
		temp1->next=temp;
		temp2->prev=temp;
		temp->prev=temp1;
		temp->next=temp2;
		while(temp2!=NULL){
			temp2->pos=temp2->pos+1;
			if(temp2->pos>max){
				max=temp2->pos;
			}
			temp2=temp2->next;
		}
	}
	res->arr=arr;
	res->total=max;
	return res;
}

struct ret_val* DeleteAtPosition(struct node * arr,long long int position){
	struct node * temp,*temp1,*temp2;
	struct ret_val * res;
	long long int max;
	res=(struct ret_val *)calloc(1,sizeof(struct ret_val));
	max=1;
	if(position==1){
		temp=arr;
		temp1=temp->next;
		temp1->prev=NULL;
		free(temp);
		arr=temp1;
		while(temp1!=NULL){
			temp1->pos=temp1->pos-1;
			if(temp1->pos>max){
				max=temp1->pos;
			}
			temp1=temp1->next;
		}
	}
	else{
		temp1=arr;
		while(temp1->pos!=position-1){
			temp1=temp1->next;
		}
		
		temp=temp1->next;
		if(temp->next!=NULL){
			temp2=temp->next;
			temp2->prev=temp1;
			temp1->next=temp2;
			free(temp);
		
			while(temp2!=NULL){
				temp2->pos=temp2->pos-1;
				if(temp2->pos>max){
					max=temp2->pos;
				}
				temp2=temp2->next;
			}	
		}
		else{
			temp1->next=NULL;
			free(temp);
		}
	}
	res->arr=arr;
	res->total=max;
	return res;	

}

struct ret_val * insertAtLast(struct node * arr,long long int position,long long int value){
	struct node * temp,* temp1;
	struct ret_val * res;
	temp=(struct node *)calloc(1,sizeof(struct node));	
	res=(struct ret_val *)calloc(1,sizeof(struct ret_val));
	long long int max;
	temp->pos=position;
	temp->val=value;
	max=position;
	if(position==1){
		arr=temp;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else{
		temp1=arr;
		while(temp1->pos!=position-1){
			temp1=temp1->next;			
		}
		temp1->next=temp;
		temp->prev=temp1;
		temp->next=NULL;
	}
	res->arr=arr;
	res->total=position;
	return res;
}

int main(){
	long long int position,value,flag,max;
	struct node * arr,*temp;
	arr=NULL;
	struct ret_val * res;
	printf("Enter The Initial array one by one:\n");
	position=1;
	flag=1;
	while(flag){
		printf("Enter the array value at position %lld\n",position);
		scanf("%lld",&value);
		
		if(position>1)
			res=insertAtLast(arr,position,value);
		else if(position==1){
			temp=(struct node *)calloc(1,sizeof(struct node));
			temp->val=value;
			temp->pos=position;
			temp->next=NULL;
			temp->prev=NULL;
			arr=temp;
		}	
		printf("The current Array Contents are:\n");
		printf("Position Value\n");
		temp=arr;
		while(temp!=NULL){
			printf("%lld        %lld\n",temp->pos,temp->val);
			temp=temp->next;
		}	
		printf("Wanna Enter More (1 for yes , 0 for no)\n" );
		scanf("%lld",&flag);
		position++;
	}
	max=position-1;
	printf("If you wanna insert At a given position enter 1 or else enter 2 to delete ... If you wanna exit enter 0\n");
	scanf("%lld",&flag);
	
	while(flag==1 || flag==2){
		if(flag==1){
			printf("Enter The Value and the position respectively\n");
			scanf("%lld %lld",&value,&position);
			if(position>max+1 || position<=0){
				printf("Sorry not possible\n");	
				continue;		
			}
			else if(position==max+1){
				res=insertAtLast(arr,position,value);
				arr=res->arr;
				max++;
			}
			else{
				res=InsertAtPosition(arr,value,position);
				arr=res->arr;
				max=res->total;
			}
			printf("The current Array Contents are:\n");
			printf("Position Value\n");
			temp=arr;
			while(temp!=NULL){
				printf("%lld        %lld\n",temp->pos,temp->val);
				temp=temp->next;
			}
		}
		else if(flag==2){
			printf("Enter The position\n");
			scanf("%lld",&position);
			if(position>max || position<=0){
				printf("Sorry not possible\n");	
				continue;		
			}
			else{
				res=DeleteAtPosition(arr,position);
				arr=res->arr;
				max=res->total;
			}				
			printf("The current Array Contents are:\n");
			printf("Position Value\n");
			temp=arr;
			while(temp!=NULL){
				printf("%lld        %lld\n",temp->pos,temp->val);
				temp=temp->next;
			}		
		}
		
		printf("If you wanna insert At a given position enter 1 or else enter 2 to delete ... If you wanna exit enter 0\n");
		scanf("%lld",&flag);				
	}
	
	return 0;
}
