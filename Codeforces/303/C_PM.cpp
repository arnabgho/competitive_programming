#include<bits/stdc++.h>
#define ll long long
#define inf 10000000000000000l
using namespace std;

int main()
{
	int n;
	cin>>n;
	ll x[n], h[n];
	for(int i=0;i<n;++i)cin>>x[i]>>h[i];
	if(n==1){ cout<<1<<endl; return 0;}
	ll t[n+1][3][2];
	t[0][0][0] = x[0];
	t[0][0][1] = 1;
	t[0][1][0] = x[0];
	t[0][1][1] = 0;
	if(x[0]+h[0]>=x[1]){
		t[0][2][0] = inf;
		t[0][2][1] = -inf; 
	}
	else{
		t[0][2][0] = x[0]+h[0];
		t[0][2][1] = 1; 
	}
	ll lhs, rhs,temp;
	for(int i=1;i<n;++i)
	{
		//left
		lhs = x[i]-h[i];
		t[i][0][0] = inf;
		t[i][0][1] = -inf;
		for(int j=0;j<3;++j)
		{
			if(t[i-1][j][0]<lhs){
				t[i][0][1] = max(t[i][0][1], 1+ t[i-1][j][1]);t[i][0][0]=x[i];  
			}

		}
		t[i][1][0] = x[i];
		t[i][1][1] = max(t[i-1][1][1],max(t[i-1][0][1], t[i-1][2][1]));

		if(x[i+1]<=x[i]+h[i])
		{
			t[i][2][0] = inf;
			t[i][2][1] = -inf;
		}
		else
		{
			t[i][2][0] = x[i]+h[i];
			t[i][2][1] = 1+max(t[i-1][1][1],max(t[i-1][0][1], t[i-1][2][1]));
		}

	}
	ll ans = max(t[n-1][1][1],max(t[n-1][0][1], t[n-1][2][1]));
	cout<<ans<<endl;
	return 0;
}