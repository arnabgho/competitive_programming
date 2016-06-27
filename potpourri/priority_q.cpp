#include<iostream>
#include<queue>

using namespace std;

int main(){

	std::priority_queue<int> queue;
	queue.push(100);
	queue.push(50);
	queue.push(300);
	queue.push(150);
	while(!queue.empty()){
		cout<<queue.top()<<endl;
		queue.pop();
	}			
	return 0;
}
