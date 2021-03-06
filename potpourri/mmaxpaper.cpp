#include<stdio.h>
#include<stdlib.h>



struct entry{

	long long int len;
	long long int breadth;
};

struct  entry arr[1001];
long long int   ans[1001];
long long int prev[10001];

long long int max(long long int a,long long int b){
	return a>b ? a:b;
}

long long int mod(long long int a){
	return a>0 ? a:-a; 
}

int main(){

	long long int n,i,l1,l2,l3,l4;
	scanf("%lld",&n);

	for(i=1;i<=n;i++)
		scanf("%lld %lld",&arr[i].len,&arr[i].breadth);

	

	l1=arr[1].len+mod(arr[2].breadth-arr[1].breadth)+arr[2].len;
	l2=arr[1].breadth+mod(arr[2].breadth-arr[1].len)+arr[2].len;
	l3=arr[1].len+mod(arr[2].len-arr[1].breadth)+arr[2].breadth;
	l4=arr[1].breadth+mod(arr[2].len-arr[1].len)+arr[2].breadth;

		if(l1>l2 && l1>l3 && l1>l4){
			ans[1]=l1-(mod(arr[2].breadth-arr[1].breadth)+arr[2].len);
			ans[2]=l1;
			prev[2]=0;
			prev[1]=0;
		}
		else if(l2>=l1 && l2>l3 && l2>l4){
			ans[1]=l2-(mod(arr[2].breadth-arr[1].len)+arr[2].len);
			ans[2]=l2;
			prev[2]=0;
			prev[1]=1;				
		}
		else if(l3>=l1 && l3>=l2 && l3>l4){
			ans[1]=l3-(mod(arr[2].len-arr[1].breadth)+arr[2].breadth);
			ans[2]=l3;
			prev[2]=1;
			prev[1]=0;
		}
		else if(l4>=l1 && l4>=l2 && l4>=l3){
			ans[1]=l4-(mod(arr[2].len-arr[1].len)+arr[2].breadth);
			ans[2]=l4;
			prev[2]=1;
			prev[1]=1;
		}		
	
	printf("%lld %lld %lld %lld\n",l1,l2,l3,l4);

	for(i=3;i<=n;i++){
		if(prev[i-2]==0){	
			l1=ans[i-2]+mod(arr[i-1].breadth-arr[i-2].breadth)+arr[i-1].len+ mod(arr[i].breadth-arr[i-1].breadth)+arr[i].len;
			l2=ans[i-2]+mod(arr[i-1].len-arr[i-2].breadth)+arr[i-1].breadth+ mod(arr[i].breadth-arr[i-1].len)+arr[i].breadth;
			l3=ans[i-2]+mod(arr[i-1].breadth-arr[i-2].breadth)+arr[i-1].len+ mod(arr[i].len-arr[i-1].breadth)+arr[i].breadth;
			l4=ans[i-2]+mod(arr[i-1].len-arr[i-2].breadth)+arr[i-1].breadth+ mod(arr[i].len-arr[i-1].len)+arr[i].breadth;	
			
			if(l1>l2 && l1>l3 && l1>l4){
				ans[i-1]=l1-(mod(arr[i].breadth-arr[i-1].breadth)+arr[i].len);
				ans[i]=l1;
				prev[i]=0;
				prev[i-1]=0;
			}
			else if(l2>=l1 && l2>l3 && l2>l4){
				ans[i-1]=l2-(mod(arr[i].breadth-arr[i-1].len)+arr[i].breadth);
				ans[i]=l2;
				prev[i]=0;
				prev[i-1]=1;				
			}
			else if(l3>=l1 && l3>=l2 && l3>l4){
				ans[i-1]=l3-(mod(arr[i].len-arr[i-1].breadth)+arr[i].breadth);
				ans[i]=l3;
				prev[i]=1;
				prev[i-1]=0;
			}
			else if(l4>=l1 && l4>=l2 && l4>=l3){
				ans[i-1]=l4-(mod(arr[i].len-arr[i-1].len)+arr[i].breadth);
				ans[i]=l4;
				prev[i]=1;
				prev[i-1]=1;
			}			
		}
		else if(prev[i-2]==1){
			l1=ans[i-2]+mod(arr[i-1].breadth-arr[i-2].len)+arr[i-1].len+ mod(arr[i].breadth-arr[i-1].breadth)+arr[i].len;
			l2=ans[i-2]+mod(arr[i-1].len-arr[i-2].len)+arr[i-1].breadth+ mod(arr[i].breadth-arr[i-1].len)+arr[i].breadth;
			l3=ans[i-2]+mod(arr[i-1].breadth-arr[i-2].len)+arr[i-1].len+ mod(arr[i].len-arr[i-1].breadth)+arr[i].breadth;
			l4=ans[i-2]+mod(arr[i-1].len-arr[i-2].len)+arr[i-1].breadth+ mod(arr[i].len-arr[i-1].len)+arr[i].breadth;				


			if(l1>l2 && l1>l3 && l1>l4){
				ans[i-1]=l1-(mod(arr[i].breadth-arr[i-1].breadth)+arr[i].len);
				ans[i]=l1;
				prev[i]=0;
				prev[i-1]=0;
			}
			else if(l2>=l1 && l2>l3 && l2>l4){
				ans[i-1]=l2-(mod(arr[i].breadth-arr[i-1].len)+arr[i].breadth);
				ans[i]=l2;
				prev[i]=0;
				prev[i-1]=1;				
			}
			else if(l3>=l1 && l3>=l2 && l3>l4){
				ans[i-1]=l3-(mod(arr[i].len-arr[i-1].breadth)+arr[i].breadth);
				ans[i]=l3;
				prev[i]=1;
				prev[i-1]=0;
			}
			else if(l4>=l1 && l4>=l2 && l4>=l3){
				ans[i-1]=l4-(mod(arr[i].len-arr[i-1].len)+arr[i].breadth);
				ans[i]=l4;
				prev[i]=1;
				prev[i-1]=1;
			}			
			
			printf("%lld %lld %lld %lld\n",l1,l2,l3,l4);
		}			
	}
	for(i=1;i<=n;i++)
		printf("%lld\n",ans[i]-ans[i-1]);

	for(i=1;i<=n;i++)
		printf("%lld\n",prev[i]);
	printf("%lld\n",ans[n]);
	return 0;
}
