#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int n[20000];

int main(){
	stack<int> mystack_old;
	stack<int> mystack_new;
	int N,K,i,val,ans=0,*check_new,num;
	cin>>N>>K;
	for(i=0;i<N;i++)
		cin>>n[i];
	mystack_old.push(n[0]%K);
	for(i=1;i<=N-1;i++){
		check_new=(int *)calloc(2*K,sizeof(int));
		num=0;
		while(!mystack_old.empty()){
			val=mystack_old.top();
			mystack_old.pop();
			//cout<<"val : "<<val<<" n[i] "<<n[i]<<endl;
			if(check_new[((val+n[i]%K+K)%K+K)%K]!=1){
				mystack_new.push(((val+n[i]%K+K)%K+K)%K);
				check_new[((val+n[i]%K+K)%K+K)%K]=1;
				//cout<<"val_+: "<<(val+n[i]%K)%K<<endl;
			}	
			if(check_new[((val-n[i]%K+K)%K+K)%K]!=1){
				mystack_new.push(((val-n[i]%K+K)%K+K)%K);
				check_new[((val-n[i]%K+K)%K+K)%K]=1;
				//cout<<"val_-: "<<(val-n[i]%K+K)%K<<endl;				
			}	
		}
		while(!mystack_new.empty()){
			val=mystack_new.top();
			mystack_new.pop();
			mystack_old.push(val);
			num++;
		}
		//cout<<"Number: "<<num<<endl;
		free(check_new);
	}	
	
	while(!mystack_old.empty()){
		val=mystack_old.top();
		if(val==0){
			ans=1;
			break;
		}	
		mystack_old.pop();
	}
	if(ans)
		cout<<"Divisible\n";
	else
		cout<<"Not divisible\n";
	return 0;
}

