/**********************************************************************************

	Convex Hull [ Graham-Andrew method, O(NlogN) ]
	Based on problem 638 from informatics.mccme.ru: 
	http://informatics.mccme.ru/mod/statements/view3.php?chapterid=638

	Tested on problem 290 from informatics.mccme.ru: 
	http://informatics.mccme.ru/mod/statements/view3.php?id=&chapterid=290

**********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define sqr(x) ((x) * (x))

const double pi = acos(-1.0);
struct point {
	double x, y;
	point(double x, double y) : x(x), y(y) {}
	bool operator==(const point &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};
typedef point PT;
int n;
vector <point> p, hull;
double ans;

bool cmp(point a, point b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool eq(point a, point b) {
	return (a.x == b.x && a.y == b.y);
}

bool isCCW(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void setConvexHull(vector <point> p, vector <point> &h) {
	sort(p.begin(), p.end(), cmp);
	p.erase(unique(p.begin(), p.end(), eq), p.end());

	vector <point> up, down;
	point head = p[0], tail = p.back();

	up.push_back(head); down.push_back(head);

	for (int i = 1; i < (int) p.size(); i++) {
		if (i == (int) p.size() - 1 || !isCCW(tail, head, p[i])) {
			while ( (int) up.size() >= 2 && isCCW(up[up.size() - 2], up.back(), p[i]) )
				up.pop_back();
			up.push_back(p[i]);
		}
		if (i == (int) p.size() - 1 || isCCW(tail, head, p[i])) {
			while ( (int) down.size() >= 2 && !isCCW(down[down.size() - 2], down.back(), p[i]) )
				down.pop_back();
			down.push_back(p[i]);
		}
	}

	h.clear();
	for (int i = 0; i < (int) up.size(); i++)
		h.push_back(up[i]);
	for (int i = (int) down.size() - 2; i > 0; i--)
		h.push_back(down[i]);

}

double dist(point a, point b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double getPerimeter(vector <point> p) {
	double per = 0;

	for (int i = 1; i < (int) p.size(); i++)
		per += dist(p[i - 1], p[i]);
	per += dist(p.back(), p[0]);

	return per;
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
        setConvexHull(v,cnvx);
        for(int i=0;i<cnvx.size();i++){
            cout<<cnvx[i].x<<" "<<cnvx[i].y<<endl;
        }

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
            cout<<"HI\n";
            v.erase(v.begin()+i);
            std::vector<PT> temp,temphull;
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
                setConvexHull(temp,temphull);
                f=0;
                for (int i = 0; i < temphull.size(); ++i)
                {
                    if(p_ref==temphull[i])
                        f=1;
                }
                if(f)
                    ans=min(ans,countBits(mask));
            }
            cout<<ans<<endl;
        }
    }  
    return 0;
}