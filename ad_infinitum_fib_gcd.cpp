#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int LL;
std::vector<LL> v;

LL MOD = 1e9+7LL;

LL gcd(LL a,LL b){
	if(b==0)
		return a;
	else return gcd(b,a%b);
}

LL getGCD(LL n){
	LL g=v[0];
	for (int i = 1; i < n; ++i)
	{
		g=gcd(v[i],g);
	}
	return g;
}


 
void multiply(LL F[2][2], LL M[2][2])
{
  LL x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0]);
  LL y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1]);
  LL z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0]);
  LL w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1]);
 
  F[0][0] = x<MOD ? x : x-MOD;
  F[0][1] = y<MOD ? y : y-MOD;
  F[1][0] = z<MOD ? z : z-MOD;
  F[1][1] = w<MOD ? w : w-MOD;
}
 
void power(LL F[2][2], LL n)
{
  LL i;
  LL M[2][2] = {{1LL,1LL},{1LL,0LL}};
 
  // n - 1 times multiply the matrix to {{1,0},{0,1}}
  for (i = 2; i <= n; i++)
      multiply(F, M);
}

LL getFib(LL n)h
{
  LL F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  power(F, n-1);
 
  return F[0][0]%MOD;
}

int main() {
	LL n,a,gcd,ans;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	gcd=getGCD(n);
	ans=getFib(gcd)%MOD;
	cout<<ans<<endl;
	return 0;
}