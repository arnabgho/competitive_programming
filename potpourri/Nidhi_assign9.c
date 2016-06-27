#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char arr[50];
double val_arr[50];
struct node {
	double value;
	struct node * next;
};

struct node * push(struct node * stack,double val){
	struct node * temp;
	temp=(struct node *)calloc(1,sizeof(struct node));
	temp->value=val;
	temp->next=stack;
	stack=temp;
	return stack;
}
double top(struct node * stack){
	return stack->value;
}
struct node * pop(struct node * stack){
	struct node * temp;
	if(stack==NULL)
		return NULL;
		
	else{
		temp=stack;
		stack=stack->next;
		return stack;
	}	
	
}

int main(){

	int n,i,point;
	double a,b;
	struct node * stack,* temp1,* temp2;
	stack=NULL;
	printf("Enter the postfix form of the given expression: (with variable names in Upper Case alphabets)\n");
	scanf("%s",arr+1);
	printf("Enter the number of variables\n");
	scanf("%d",&n);
	printf("Enter the values of the variables from left to right\n");
	for(i=1;i<=n;i++)
		scanf("%lf",&val_arr[i]);
	point=1;
	
	//for(i=1;i<=n;i++)
	//	printf("%lf",val_arr[i]);
	
	for(i=1;i<=2*n-1;i++){
		if(arr[i]<='Z' && arr[i]>='A'){
			//printf("%lf\n",val_arr[point]);
			stack=push(stack,val_arr[point]);
			point++;
			
		}	
		else{
			a=top(stack);
			stack=pop(stack);
			b=top(stack);
			stack=pop(stack);
			//free(temp1);
			//free(temp2);
			//printf("a,b= : %lf,%lf\n",a,b);
			if(arr[i]=='^'){
				stack=push(stack,pow(b,a));
			}
			else if(arr[i]=='/'){
				stack=push(stack,b/a);
			}
			else if(arr[i]=='*'){
				stack=push(stack,b*a);
			}
			else if(arr[i]=='+'){
				stack=push(stack,b+a);
			}
			else if(arr[i]=='-'){
				stack=push(stack,b-a);
			}	
		}
	}
	a=top(stack);
	//free(temp1);
	printf("The Value of the given postfix expresssion is : %lf\n",a);
	return 0;	
}
