#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int unsetBit(int mask,int i){
	// cout<<"mask "<<mask<<" i "<<i<<endl;
	// cout<<"reset "<<(mask & ~(1<<i))<<endl;
	return mask & ~(1<<i);
}

int main() {
	int n;
	char ch;
	string inp;
	while(cin>>inp){
		sscanf(inp.c_str(),"%d",&n);
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		int mask=(1<<3)-1;
		for (int i = 0; i <n ; ++i)
		{
			int a,b;
			cin>>a>>b;
			if(a==1){
				s.push(b);q.push(b);pq.push(b);
			}
			else{
				if(s.top()!=b)
					mask=unsetBit(mask,0);
				if(q.front()!=b)
					mask=unsetBit(mask,1);
				if(pq.top()!=b)
					mask=unsetBit(mask,2);
				s.pop();q.pop();pq.pop();
			}
		}
		while(s.size()) s.pop();
		while(q.size()) q.pop();
		while(pq.size()) pq.pop();
		// cout<<"mask "<<mask<<endl;
		if(mask==1)
			cout<<"stack\n";
		else if(mask==2)
			cout<<"queue\n";
		else if(mask==4)
			cout<<"priority queue\n";
		else if(mask==0)
			cout<<"impossible\n";
		else
			cout<<"not sure\n";
	}
	return 0;
}