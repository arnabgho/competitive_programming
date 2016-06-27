#include<iostream>
#include<queue>

using namespace std;

struct meteor{
	long long int t,d;
};

bool operator<(const meteor& a, const meteor& b) {
  return a.d < b.d;
}

int main(){
	long long int n,i,damage,hit;
	struct meteor curr,popped;
	std::priority_queue<struct meteor> queue;
	
	cin>>n;
	damage=0;
	hit=0;
	for(i=1;i<=n;i++){
		cin>>curr.t>>curr.d;
		damage+=curr.d;
		queue.push(curr);
		if(damage>curr.t){
			popped=queue.top();
			queue.pop();
			damage-=popped.d;
			hit++;
		}
	}
	cout<<hit<<endl;			
	return 0;
}




/*

	queue.push(100);
	queue.push(50);
	queue.push(300);
	queue.push(150);
	while(!queue.empty()){
		cout<<queue.top()<<endl;
		queue.pop();
	}


*/
