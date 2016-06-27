#include <bits/stdc++.h>
using namespace std;

// #define REMOVE_REDUNDANT

typedef double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

// #ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
// #endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
// #ifdef REMOVE_REDUNDANT
//   if (pts.size() <= 2) return;
//   dn.clear();
//   dn.push_back(pts[0]);
//   dn.push_back(pts[1]);
//   for (int i = 2; i < pts.size(); i++) {
//     if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
//     dn.push_back(pts[i]);
//   }
//   if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
//     dn[0] = dn.back();
//     dn.pop_back();
//   }
//   pts = dn;
// #endif
}

bool getBit(int n,int i){
    return (n & (1<<i)) !=0 ;
}

int countBits(int n){
    int ans=0;
    // cout<<"n "<<n<<endl;
    while(n>0){
        ans+=n%2;
        n/=2;
    }
    // cout<<"numBits "<<ans<<endl;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for (int cas = 1; cas <=t ; ++cas)
    {
        int n;
        cin>>n;
        std::vector<PT> v,ref,cnvx;
        for (int i = 0; i <n ; ++i)
        {
            double x,y;
            cin>>x>>y;
            PT p(x,y);
            v.push_back(p);
        }      

        ref=v;
        cnvx=v;
        // for(int i=0;i<cnvx.size();i++){
        //     cout<<cnvx[i].x<<" "<<cnvx[i].y<<endl;
        // }
        // cout<<"--------\n";
        ConvexHull(cnvx);
        // for(int i=0;i<cnvx.size();i++){
        //     cout<<cnvx[i].x<<" "<<cnvx[i].y<<endl;
        // }

        cout<<"Case #"<<cas<<":\n";
        for(int i=0;i<n;i++){
            v=ref;
            bool f=0;
            for (int j = 0; j < cnvx.size(); ++j)
            {
                if(v[i]==cnvx[j])
                    f=1;
            }
            if(f){
                cout<<"0\n";
                continue;
            }
            // cout<<"HI\n";
            v.erase(v.begin()+i);
            std::vector<PT> temp;
            PT p_ref=ref[i];
            int ans=1e9;
            for (int mask = 1; mask < (1<<(n-1) ) ; ++mask)
            {
                temp.clear();
                temp.push_back(p_ref);
                for (int i = 0; i < n-1 ; ++i)
                {
                    if(getBit(mask,i))
                        temp.push_back(v[i]);
                }
                ConvexHull(temp);
                f=0;
                for (int i = 0; i < temp.size(); ++i)
                {
                    if(p_ref==temp[i])
                        f=1;
                }
                if(f)
                    ans=min(ans,n-1-countBits(mask));
            }
            cout<<ans<<endl;
        }
    }  
    return 0;
}