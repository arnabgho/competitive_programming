#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char ch;
	struct node * next;
};

struct ret_val{
	struct node * stack;
	char ch;
};	

struct ret_val * POP(struct node * stack){
	struct node * temp;
	struct ret_val * res;
	char top;
	res=(struct ret_val *)calloc(1,sizeof(struct ret_val));	
	
	if (stack!=NULL){
		temp=stack;
		stack=stack->next;
		top=temp->ch;
	}
	free(temp);
	res->ch=top;
	res->stack=stack;
	return res;
}

struct node * PUSH(struct node * stack,char ch){
	struct node * temp;
	temp=(struct node *)calloc(1,sizeof(struct node));
	temp->ch=ch;
	temp->next=stack;
	stack=temp;
	return stack;
}

char TOP(struct node * stack){
	if(stack!=NULL){
		return stack->ch;
	}
}

int precedence_check(char c1,char c2){
	if(c1=='^'){
		if(c2!='^')
			return 1;
		else
			return 0;	
	}
	else if(c1=='*'){
		if(c2=='^')
			return -1;
		else if(c2=='*' || c2=='/')
			return	0;
		else return -1;	
	}	
	else if(c1=='/'){
		if(c2=='^')
			return -1;
		else if(c2=='*' || c2=='/')
			return	0;
		else return -1;	
	}
	else if(c1=='+'){
		if(c2=='^'||c2=='*'||c2=='\')
			return -1;
		else 
			return 0;	
	}
	else if(c1=='-'){
		if(c2=='^'||c2=='*'||c2=='\')
			return -1;
		else 
			return 0;	
	}
	
}

char final[101];
char arr[101];
int main(){

	char ch,ch1,ch2;
	int i,len,pointer;
	struct node * stack,*temp;
	struct ret_val * res;
	printf("Enter the given exression\n");
	scanf("%s",arr);
	len=strlen(arr);
	pointer=0;
	stack=NULL;
	for(i=0;i<len;i++){
		ch1=arr[i];
		if(ch1>='A' && ch1<='Z'){
			final[pointer]=ch1;
			pointer++;
		}
		else if(ch1=='('){
			temp=PUSH(stack,'(');
			stack=temp;
		}
		else if(ch1==')'){
			ch=TOP(stack);
			while(ch!='('){
				res=POP(stack);
				ch2=res->ch;
				stack=res->stack;
				final[pointer]=ch2;
				pointer++;
				ch=TOP(stack);
			}
			res=POP(stack);
			stack=res->stack;
		}
		else{
			if(ch1=='^'){
				temp=PUSH(stack,ch1);
				stack=temp;
			}
			else if(ch1=='*' && TOP(stack)!='^'){
				temp=PUSH(stack,ch1);
				stack=temp;
			}	
			else if(ch1=='*' && TOP(stack)=='^'){
				
			}
		}
		if(i==len-1 && stack!=NULL){
			while(stack!=NULL){
				res=POP(stack);
				ch2=res->ch;
				stack=res->stack;
				final[pointer]=ch2;
				pointer++;
			}
		}
	}	
	for(i=0;i<pointer;i++){
		printf("%c",final[i]);
	}
	printf("\n");
	return 0;
}
