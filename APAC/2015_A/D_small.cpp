#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int board[400][400];
std::set<PII> Food;
void init(){
	memset(board,0,sizeof(board));
	Food.clear();
	for (int i = 1; i <400 ; ++i)
	{
		for (int j = 1; j <400 ; ++j)
		{
			if ((i+j)%2==1){
				// board[i][j]=1;
				Food.insert(PII(i,j));
			}
		}
	}
}

// 0 - > Right , 1 -> down , 2->left , 3->up
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

map<int,char> Turn;
int R,C,S;

PII getNext(PII cur,int dir){
	int x,y;
	if(cur.first+dx[dir]>R)
		x=1;
	else if(cur.first+dx[dir]<1)
		x=R;
	else
		x=cur.first+dx[dir];
	if(cur.se+dy[dir]>C)
		y=1;
	else if(cur.se+dy[dir]<1)
		y=C;
	else
		y=cur.se+dy[dir];
	return PII(x,y);
}

int main(){
	int test;
	cin>>test;
	for (int cas = 1; cas <=test ; ++cas)
	{
		init();
		
		cin>>S>>R>>C;
		for (int i = 0; i < S; ++i)
		{
			int x,c;
			cin>>x>>c;
			Turn[x]=c;
		}
		board[1][1]=-1;
		PII start,end;
		start=PII(1,1);
		end=PII(1,1);
		int direction=0;
		bool alive=1;
		int tim=0;
		int size=1;
		queue<PII> Snake;
		while(alive){
			// cout<<"tim "<<tim<<" start "<<start.fi<<" "<<start.se<<" end "<<end.fi<<" "<<end.se<<endl;	
			PII next=getNext(start,direction);
			// cout<<"next "<<next.fi<<" "<<next.se<<endl;
			if(board[next.fi][next.se]==-1){
				alive=0;
				break;
			}
			if(board[next.fi][next.se]==0 && Food.count(next)==0){
				start=next;
				Snake.push(next);
				board[next.fi][next.se]=-1;
				board[Snake.back().fi][Snake.back().se]=0;
				Snake.pop();
				end=Snake.back();	
			}
			else if(board[next.fi][next.se]==0 && Food.count(next)!=0){
				Food.erase(Food.find(next));
				board[next.fi][next.se]=-1;
				Snake.push(next);
				start=next;
				size++;
			}
			tim++;
			if(Turn.count(tim)) {
				if(Turn[tim]=='R')
					direction=(direction+1)%4;
				
				else
					direction=(direction+3)%4;
			}
		}
		printf("Case #%d: %d\n",cas,size);
	}
	return 0;	
}
