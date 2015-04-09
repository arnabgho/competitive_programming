#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef unsigned int ui;
std::vector<ui> NUM;
bool getBit(ui n,ui i){
	return (n&(1<<i))!=0;
}

int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		ui a,b,c,d;
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		NUM.push_back(d+c*(1<<8)+b*(1<<16)+a*(1<<24));
	}
	ui ans,val;
	for (int s = 0; s < 32; ++s)
	{
		ui check=NUM[0]>>s;
		bool pos=true;
		for (int i = 0; i < n; ++i)
		{
			if(check!=NUM[i]>>s){
				pos=false;
			}
		}
		if(pos){
			val=check;ans=s;break;
		}
	}	
	// cout<<"val "<<val<<endl;
	// for (int i = 0; i < 32; ++i)
	// {
	// 	cout <<getBit(val,i)<<" ";
	// }

	// cout<<endl;
	// // cout<<"val "<<val<<endl;
	// for (int i = 0; i < 32; ++i)
	// {
	// 	cout <<getBit(0xFF000000,i)<<" ";
	// }
	
	cout<<endl;
	ui k=val<<(ans);
	ans=32-ans;
	ui a=(0xFF000000 & k)>>24;
	ui b=(0x00FF0000 & k)>>16;
	ui c=(0x0000FF00 & k)>>8;
	ui d=0x000000FF & k;
	cout<<a<<'.'<<b<<'.'<<c<<'.'<<d<<'/'<<ans<<endl;
	return 0;
}