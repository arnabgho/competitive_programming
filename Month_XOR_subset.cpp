    #include <bits/stdc++.h>
    #define _ ios_base::sync_with_stdio(0);cin.tie(0);
     
    using namespace std;
    std::vector<int> num(1111);
    std::vector<int> DP(1111);
    int main() {
    int t,n,i,j,K,maxim,global_max;
    cin>>t;
    while(t--){
    cin>>n>>K;
    for(i=1;i<=n;i++){
    cin>>num[i];
    }
    sort(num.begin()+1,num.begin()+n+1);
    DP[0]=K;
    for (int i = 1; i <= n; ++i)
    {
    int maxim=DP[0]^num[i];
    for(j=1;j<i;j++){
    maxim=max(maxim,DP[j]^num[i]);
    }
    DP[i]=maxim;
    /* code */
    }
    global_max=0;
    for (int i = 0; i <=n; ++i)
    {
    // cout<<"DP[i]"<<DP[i]<<endl;
    global_max=max(DP[i],global_max);
    /* code */
    }
    cout<<global_max<<endl;
    fill(num.begin(),num.end(),0);
    }
    return 0;
    } 