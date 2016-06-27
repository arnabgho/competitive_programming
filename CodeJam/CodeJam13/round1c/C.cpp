#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


struct H{
	int t,left,right,strength;
};
bool operator <(const H& x, const H& y) {
    return std::tie(x.t,x.strength , x.left, x.right) < std::tie(y.t,y.strength ,y.left, y.right);
}    

std::vector<int> d,n,w,e,s,delta_d,delta_p,delta_s;
const int offset=10000;
int wall[50000];
set<H> Q;
void init(){
	memset(wall,0,sizeof(wall));
	Q.clear();
	d.clear();n.clear();w.clear();e.clear();s.clear();delta_d.clear();delta_p.clear();delta_s.clear();
}
int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		int N;
		cin>>N;
		init();
		for (int i = 0; i < N; ++i)
		{
			int di, ni, wi, ei, si, delta_di, delta_pi , delta_si;
			cin>>di>>ni>>wi>>ei>>si>>delta_di>>delta_pi>>delta_si;
			d.push_back(di);n.push_back(ni);w.push_back(wi);e.push_back(ei);s.push_back(si);delta_d.push_back(delta_di);delta_p.push_back(delta_pi);delta_s.push_back(delta_si);			
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <n[i] ; ++j)
			{
				H h={d[i]+delta_d[i]*j,w[i]+delta_p[i]*j+offset,e[i]+delta_p[i]*j+offset,s[i]+delta_s[i]*j};
				Q.insert(h);
			}
		}
		int numAttacks=0;
		std::set<H>::iterator it;
		for (it=Q.begin(); it !=Q.end() ; ++it)
		{
			H h=*it;
			// cout<<"Time "<<h.t<<" w "<<h.left<<" e "<<h.right<<" strength "<<h.strength<<endl;
			bool f=0;
			for (int i = h.left; i < h.right; ++i)
			{
				if(wall[i]<h.strength)
					f=1;
				wall[i]=max(wall[i],h.strength);
			}
			numAttacks+=f;
		}
		cout<<"Case #"<<cas<<": "<<numAttacks<<endl;
	}
	return 0;
}