#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

struct list_node{
	int start_pos;
	int length;
	struct list_node* prev;
	struct list_node* next;
};


struct memp{
	struct list_node* free_list;
	struct list_node* alloc_list;
	int pos;
};

struct remove_data{
	struct list_node * list;
	int length;
};

struct list_node * insertAtBeginning(struct list_node * list,struct list_node* new_node){
	if(list==NULL){
		list=new_node;
		list->next=NULL;
		list->prev=NULL;
	}
	else{
		new_node->next=list;
		list->prev=new_node;
		new_node->prev=NULL;
		list=new_node;
	}
}

struct remove_data * removeNode(struct list_node * list,int start_pos){
	struct list_node * dummy,*ret,*prev,*next;
	struct remove_data * res;
	res=(struct remove_data *) calloc(1,sizeof(struct remove_data));
	int found=0;
	if(list==NULL)
		ret= NULL;
	else{
		dummy=list;
		while(dummy!=NULL ){
			if(dummy->start_pos==start_pos){
				found=1;
				break;
			}
			dummy=dummy->next;
		}	
		if(found==1){
			res->length=dummy->length;
			if(dummy->next==NULL && dummy->prev==NULL){
				free(dummy);
				ret=NULL;
			}
			else if(dummy->next==NULL && dummy->prev!=NULL){
				prev=dummy->prev;
				prev->next=NULL;
				free(dummy);
				ret=list;
			}
			else if(dummy->next!=NULL && dummy->prev==NULL){
				next=list->next;
				next->prev=NULL;
				free(dummy);
				ret=next;
				
				//return next;
				//printf("I m here\n");	
			}
			else if(dummy->next!=NULL && dummy->prev!=NULL){
				ret=list;
				next=dummy->next;
				prev=dummy->prev;
				next->prev=prev;
				prev->next=next;
				free(dummy);
			}
		}
		else	{ 
			ret=list;
			printf("Invalid Deallocate operation");
		}
	}
	res->list=ret;
	return res;
} 

struct list_node* maintain_cont_free_list(struct list_node * free_list){
	struct list_node * dummy,*temp,*prev,*just_for_fun;
	int nstart_pos,nlength,enter,x,y,z,sum;
	dummy=free_list;		
	while(dummy!=NULL){
		temp=dummy;
		enter=0;
		sum=0;
		if(dummy->prev!=NULL){

			prev=dummy->prev;
		
			nstart_pos=temp->start_pos;
			nlength=temp->length;
			//printf("Inside Loop:\n");
			while(temp!=NULL && temp->next!=NULL && temp->next->start_pos==temp->start_pos+temp->length){
				enter=1;
				sum=sum+temp->length;
				//printf("%d %d\n",temp->start_pos,temp->length);
				just_for_fun=temp;
				temp=temp->next;
				free(just_for_fun);
			}
			if(enter==1){
				sum=sum+temp->length;
				//printf("After Loop:\n");
				//printf("%d %d\n",temp->start_pos,temp->length);
				temp->start_pos=nstart_pos;
				temp->length=sum;
				prev->next=temp;
				temp->prev=prev;
			}
		}
		else{
			
		
			nstart_pos=temp->start_pos;
			nlength=temp->length;
			//printf("Inside Loop:\n");
			while(temp!=NULL && temp->next!=NULL && temp->next->start_pos==temp->start_pos+temp->length){
				//printf("%d %d\n",temp->start_pos,temp->length);
				sum=sum+temp->length;
				enter=1;
				just_for_fun=temp;
				temp=temp->next;
				free(just_for_fun);
			
			}
			if(enter==1){
				//printf("After Loop:\n");
				sum=sum+temp->length;
				//printf("%d %d %d\n",temp->start_pos,temp->length,temp->start_pos+temp->length-nstart_pos);
				temp->start_pos=nstart_pos;
				temp->length=sum;
				free_list=temp;
				temp->prev=NULL;
			}
		}	
		dummy=temp->next;
	}
	return free_list;
}

struct list_node * init(int M){
	struct list_node *free_list;
	free_list=(struct list_node *)calloc(1,sizeof(list_node));
	free_list->start_pos=0;
	free_list->length=M;
	free_list->prev=NULL;
	free_list->next=NULL;
	return free_list;
}

struct memp * alloc_first_fit(struct list_node * free_list,struct list_node * alloc_list,int n){
	struct list_node * dummy,* allocated,*prev,*next;
	struct memp *ret;
	
	int found=0;
	dummy=free_list;
	while(dummy!=NULL){
		if(dummy->length == n){
			found=1;
			allocated=(struct list_node *)calloc(1,sizeof(list_node));
			allocated->start_pos=dummy->start_pos;
			allocated->length=dummy->length;
			alloc_list=insertAtBeginning(alloc_list,allocated);
			prev=dummy->prev;
			next=dummy->next;
			if(prev!=NULL && next !=NULL){
				prev->next=next;
				next->prev=prev;
				free(dummy);
				break;
			}
			else if(prev==NULL&&next!=NULL){
				free_list=next;
				next->prev=NULL;
				free(dummy);
				break;
			}
			else if(prev!=NULL && next==NULL){
				prev->next=NULL;
				free(dummy);
				break;
			}
			else if(prev==NULL && next ==NULL){
				free_list=NULL;
				free(dummy);
				break;
			}
		}	
		else if (dummy->length>n){
			found=1;
			allocated=(struct list_node *)calloc(1,sizeof(list_node));
			allocated->start_pos=dummy->start_pos;
			allocated->length=n;
			alloc_list=insertAtBeginning(alloc_list,allocated);
			dummy->start_pos=dummy->start_pos+n;
			dummy->length=dummy->length-n;	
			break;
		}
		dummy=dummy->next;
	}

	free_list=maintain_cont_free_list(free_list);

	if(found==1){
		ret=(struct memp*)calloc(1,sizeof(struct memp));
		ret->free_list=free_list;
		ret->alloc_list=alloc_list;
		ret->pos=allocated->start_pos;
	}
	if(found==0){
		return NULL;
	}
	return ret;
}


struct memp * alloc_best_fit(struct list_node * free_list,struct list_node * alloc_list,int n){
	struct list_node * dummy,* allocated,*prev,*next;
	struct memp *ret;
	
	int found=0;
	int dif,mindif;
	mindif=INT_MAX;
	dummy=free_list;
	while(dummy!=NULL){
		if(dummy->length == n){
			found=1;
			dif=0;
			mindif=0;
			allocated=(struct list_node *)calloc(1,sizeof(list_node));
			allocated->start_pos=dummy->start_pos;
			allocated->length=dummy->length;
			alloc_list=insertAtBeginning(alloc_list,allocated);
			prev=dummy->prev;
			next=dummy->next;
			if(prev!=NULL && next !=NULL){
				prev->next=next;
				next->prev=prev;
				free(dummy);
				break;
			}
			else if(prev==NULL&&next!=NULL){
				free_list=next;
				next->prev=NULL;
				free(dummy);
				break;
			}
			else if(prev!=NULL && next==NULL){
				prev->next=NULL;
				free(dummy);
				break;
			}
			else if(prev==NULL && next ==NULL){
				free_list=NULL;
				free(dummy);
				break;
			}
		}	
		else if (dummy->length>n){
			found=1;
			dif=dummy->length-n;
			if(dif<mindif)
				mindif=dif;	
		}
		dummy=dummy->next;
	}

	free_list=maintain_cont_free_list(free_list);

	if(found==1 && mindif==0){
		ret=(struct memp*)calloc(1,sizeof(struct memp));
		ret->free_list=free_list;
		ret->alloc_list=alloc_list;
		ret->pos=allocated->start_pos;
	}
	else if(found==1 && mindif>0){
		dummy=free_list;
		while(dummy!=NULL && dummy->length-n!=mindif){
			dummy=dummy->next;
		}
		allocated=(struct list_node *)calloc(1,sizeof(list_node));
		allocated->start_pos=dummy->start_pos;
		allocated->length=n;
		alloc_list=insertAtBeginning(alloc_list,allocated);
		dummy->start_pos=dummy->start_pos+n;
		dummy->length=dummy->length-n;


		ret=(struct memp*)calloc(1,sizeof(struct memp));
		ret->free_list=free_list;
		ret->alloc_list=alloc_list;
		ret->pos=allocated->start_pos;
	}
	if(found==0){
		return NULL;
	}
	return ret;
}







void test(){
	int n,start_pos;
	int ch;
	struct list_node * dummy,* list;
	struct remove_data * res;
	list=NULL;
	while(1){
		printf("Enter The Data For a node\n");
		scanf("%d %d",&n,&start_pos);
		dummy=(list_node *)calloc(1,sizeof(struct list_node));
		dummy->start_pos=start_pos;
		dummy->length=n;
		list=insertAtBeginning(list,dummy);
		printf("Do You wanna Continue(1/0)\n");	
		scanf("%d",&ch);
		if(ch==0)
			break;
	}
	dummy=list;
	while(dummy!=NULL){
		printf("%d %d\n",dummy->start_pos,dummy->length);
		dummy=dummy->next;
	}
	
		scanf("%d",&start_pos);
		res=removeNode(list,start_pos);
		list=res->list;
	//list=maintain_cont_free_list(list);
	//printf("dngfkg\n");
	dummy=list;
	while(dummy!=NULL){
		printf("%d %d\n",dummy->start_pos,dummy->length);
		dummy=dummy->next;
	}
}


struct memp * deallocate(struct list_node * free_list,struct list_node * alloc_list,int start_pos){
	struct remove_data * rem; 
	struct list_node * new_free_node,*next_node,*prev,*dummy;
	struct memp * result;
	int length,found;
	rem=removeNode(alloc_list,start_pos);
	length=rem->length;	
	printf("length %d start_pos %d\n",length,start_pos);
	alloc_list=rem->list;
	if(length>0){
		found=0;
		new_free_node=(struct list_node *)calloc(1,sizeof(struct list_node ));
		new_free_node->start_pos=start_pos;
		new_free_node->length=length;
		dummy=free_list;
		if(dummy->start_pos>=start_pos)
		{	
			printf("In here1\n");
			new_free_node->next=dummy;
			new_free_node->prev=NULL;	
			dummy->prev=new_free_node;
			free_list=new_free_node;
			found=1;
		}
		else if(dummy->next==NULL && dummy->start_pos<=start_pos){
			printf("In here2\n");
			new_free_node->next=NULL;
			new_free_node->prev=dummy;
			dummy->next=new_free_node;
		}
		else{	
			printf("In here3\n");
			next_node=dummy->next;
			if(next_node->next==NULL){
				printf("In Fun\n");
				if(next_node->start_pos<start_pos)
				{
					new_free_node->prev=next_node;
					next_node->next=new_free_node;
					new_free_node->next=NULL;	
				}
				else {
				printf("In Fun2\n");
					new_free_node->prev=dummy;
					next_node->prev=new_free_node;
					new_free_node->next=next_node;
					dummy->next=new_free_node;	
				}
			}
			else{
				printf("In Else\n");
				while(dummy!=NULL && dummy->next!=NULL){
					printf("In Loop\n");
					if((dummy->start_pos)<(start_pos) && start_pos<(dummy->next->start_pos)){
						next_node=dummy->next;
						//prev=dummy->prev;
						//prev->next=new_free_node;
						next_node->prev=new_free_node;
						new_free_node->next=next_node;
						new_free_node->prev=dummy;
						dummy->next=new_free_node;
						found=1;
						break;
					}
					dummy=dummy->next;
				}
				if(found==0){
					dummy->next=new_free_node;
					new_free_node->prev=dummy;
					new_free_node->next=NULL;
				}
			}	
		}
	}
	else{
		printf("Invalid Deallocate Operation\n");
	}
	


		free_list=maintain_cont_free_list(free_list);
		printf("Free List:\n");
		dummy=free_list;
		while(dummy!=NULL){
			printf("%d %d\n",dummy->start_pos,dummy->length);
			dummy=dummy->next;
		}
		printf("Allocated List:\n");
		dummy=alloc_list;
		while(dummy!=NULL){
			printf("%d %d\n",dummy->start_pos,dummy->length);
			dummy=dummy->next;
		}
	//return free_list;
	result=(struct memp *)calloc(1,sizeof(struct memp));
	result->free_list=free_list;
	result->alloc_list=alloc_list;
}

void test2(int M){		//best fit case
	int arr_start_pos[100];
	int length;
	int ch,i,n;
	struct list_node * alloc_list,* free_list,*dummy;
	struct memp * ret,*dealloc_ret;
	alloc_list=NULL;
	free_list=init(M);
	i=0;
	while(1){
		printf("Enter the length of the list you wanna allocate\n");
		scanf("%d",&length);
		
		ret=alloc_best_fit(free_list,alloc_list,length);
		if(ret==NULL)
			printf("Memory Not Available For This Chunk\n");
		else{
			arr_start_pos[i+1]=ret->pos;
			i=i+1;
			free_list=ret->free_list;
			alloc_list=ret->alloc_list;
			dummy=free_list;
			printf("Free List:\n");
			while(dummy!=NULL){
				printf("%d %d\n",dummy->start_pos,dummy->length);
				dummy=dummy->next;
			}
			printf("Allocated List:\n");	
			dummy=alloc_list;
			while(dummy!=NULL){
				printf("%d %d\n",dummy->start_pos,dummy->length);
				dummy=dummy->next;
			}
		}
		printf("Do You wanna Continue(1/0)\n");
		scanf("%d",&ch);
		printf("%d\n",ch);
		if(ch==0)
			break;
	}
	while(1)
	{
		printf("Enter the index to be deallocated\n");
		scanf("%d",&n);
		dealloc_ret=deallocate(free_list,alloc_list,arr_start_pos[n]);
		free_list=dealloc_ret->free_list;
		alloc_list=dealloc_ret->alloc_list;
		
		
	}
	
	
	
}

void test1(int M){		//first fit case
	
	int arr_start_pos[100];
	int length;
	int ch,i,n;
	struct list_node * alloc_list,* free_list,*dummy;
	struct memp * ret,*dealloc_ret;
	alloc_list=NULL;
	free_list=init(M);
	i=0;
	while(1){
		printf("Enter the length of the list you wanna allocate\n");
		scanf("%d",&length);
		
		ret=alloc_first_fit(free_list,alloc_list,length);
		if(ret==NULL)
			printf("Memory Not Available For This Chunk\n");
		else{
			arr_start_pos[i+1]=ret->pos;
			i=i+1;
			free_list=ret->free_list;
			alloc_list=ret->alloc_list;
			dummy=free_list;
			printf("Free List:\n");
			while(dummy!=NULL){
				printf("%d %d\n",dummy->start_pos,dummy->length);
				dummy=dummy->next;
			}
			printf("Allocated List:\n");	
			dummy=alloc_list;
			while(dummy!=NULL){
				printf("%d %d\n",dummy->start_pos,dummy->length);
				dummy=dummy->next;
			}
		}
		printf("Do You wanna Continue(1/0)\n");
		scanf("%d",&ch);
		printf("%d\n",ch);
		if(ch==0)
			break;
	}
	while(1)
	{
		printf("Enter the index to be deallocated\n");
		scanf("%d",&n);
		dealloc_ret=deallocate(free_list,alloc_list,arr_start_pos[n]);
		free_list=dealloc_ret->free_list;
		alloc_list=dealloc_ret->alloc_list;
		
		
	}
	
	
}

int main(){
	int M,m;
	int arr_start_pos[100];
	int i=0;
	struct list_node *free_list,*alloc_list,* dummy;
	int c;
	int flag,val;
	struct memp * result;
	//scanf("%d",&M);
	//test2();
	//free_list=init(M);
	//printf("start :%d\nlength: %d\n",free_list->start_pos,free_list->length);
	
	alloc_list=NULL;
	free_list=NULL;
	scanf("%d %d %d",&c,&M,&flag);
	printf("%d %d %d\n",c,M,flag);
	free_list=init(M);
	if(flag==1){
		while(1){
			scanf("%d %d",&c,&val);
			printf("%d %d\n",c,val);
			if(c==0 && val==0)
				break;
			if(c==1){
				result=alloc_first_fit(free_list,alloc_list,val);
				if(result!=NULL){	
					free_list=result->free_list;
					alloc_list=result->alloc_list;
					arr_start_pos[i+1]=result->pos;
					i=i+1;
					dummy=free_list;
					printf("Free List:\n");
					while(dummy!=NULL){
						printf("%d %d\n",dummy->start_pos,dummy->length);
						dummy=dummy->next;
					}
					printf("Allocated List:\n");	
					dummy=alloc_list;
					while(dummy!=NULL){
						printf("%d %d\n",dummy->start_pos,dummy->length);
						dummy=dummy->next;
					}
				}
				else{
					printf("Memory Not Available For This Chunk\n");
				}
			}
			else if(c==2){
				result=deallocate(free_list,alloc_list,arr_start_pos[val]);
				free_list=result->free_list;
				alloc_list=result->alloc_list;
			}
		}
	}
	else if(flag==2){
		while(1){
			scanf("%d %d",&c,&val);
			if(c==0 && val==0)
				break;
			printf("%d %d\n",c,val);
			if(c==1){
				result=alloc_best_fit(free_list,alloc_list,val);
				if(result!=NULL){	
					free_list=result->free_list;
					alloc_list=result->alloc_list;
					arr_start_pos[i+1]=result->pos;
					i=i+1;
					dummy=free_list;
					printf("Free List:\n");
					while(dummy!=NULL){
						printf("%d %d\n",dummy->start_pos,dummy->length);
						dummy=dummy->next;
					}
					printf("Allocated List:\n");	
					dummy=alloc_list;
					while(dummy!=NULL){
						printf("%d %d\n",dummy->start_pos,dummy->length);
						dummy=dummy->next;
					}
				}
				else{
					printf("Memory Not Available For This Chunk\n");
				}
			}
			else if(c==2){
				result=deallocate(free_list,alloc_list,arr_start_pos[val]);
				free_list=result->free_list;
				alloc_list=result->alloc_list;
			}
		}
	}
	return 0;

}
