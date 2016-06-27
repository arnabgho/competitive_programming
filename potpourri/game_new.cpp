#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void game_even(int n){
	if(n==4){
		cout<<"3 * 4 = 12"<<endl;
		cout<<"2 * 1 = 2"<<endl;
		cout<<"12 * 2 = 24"<<endl;		
	}
	else{
		cout<<n<<" - "<<n-1<<" = "<<1<<endl;
		game_even(n-2);
		cout<<"24 * 1 = 24"<<endl;
	}

}
void game_odd(int n){
	if(n==5){
		cout<<"5 - 3 = 2"<<endl;
		cout<<"2 * 4 = 8"<<endl;
		cout<<"1 + 2 = 3"<<endl;	
		cout<<"8 * 3 = 24"<<endl;	
	}
	else{
		cout<<n<<" - "<<n-1<<" = "<<1<<endl;
		game_odd(n-2);
		cout<<"24 * 1 = 24"<<endl;
	}

}
int main(){
	int n;
	cin>>n;

	if(n%2==1){
		if(n<5)
			cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			game_odd(n);
		}
	}
	else{
		if(n<3){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			game_even(n);
		}
	}
	return 0;
}