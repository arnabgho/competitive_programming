using namespace std;
typedef pair<int,int> pi;
const int inf=1e9;
std::vector<pi> v(111111);
int main() {
int t;
cin>>t;
while(t--){
int n;
cin>>n;
for (int i = 0; i < n; ++i)
{
int a,b;
cin>>a>>b;
v[i]=make_pair(a,b);
}
sort(v.begin(),v.begin()+n);
int ans=0;
int min_right=inf;
for (int i = 0; i <n ; ++i)
{
min_right=v[i].second;
while(i<n && v[i].first<=min_right){
min_right=min(min_right,v[i].second);
i++;
}
min_right=inf;
ans++;i--;
}
cout<<ans<<endl;
}
return 0;
} 