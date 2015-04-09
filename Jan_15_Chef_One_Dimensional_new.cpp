    #include <bits/stdc++.h>
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);
     
    using namespace std;
    typedef pair<int,int> pi;
    const int inf=1e9;
    std::vector<pi> v(111111);
    vector<int> sort_help[2100];
    int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    for (int i = 0; i <= 2000; ++i)
    {
        sort_help[i].clear();
    }

    for (int i = 0; i < n; ++i)
    {
    int a,b;
    cin>>a>>b;
    sort_help[a].push_back(b);
    }
    // sort(v.begin(),v.begin()+n);
    int c=0;
    for (int i = 1; i <= 2000; ++i)
    {
        for (int j = 0; j <sort_help[i].size() ; ++j)
        {
            // cout<<"i "<<i<<" sort_help "<<sort_help[i][j]<<endl;
            v[c]=make_pair(i,sort_help[i][j]);c++;
        }
    }
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