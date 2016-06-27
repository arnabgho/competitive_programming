#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define INF 10000000;

using namespace std;

struct visitor{
	int people,spend,num,table;
};

 bool cmp(struct visitor a,struct visitor b){
 	return a.spend>b.spend;
 }
 bool cmp1(struct visitor  a,struct visitor b){
 	return a.num<b.num;
 }
int tables[1001];
int taken[1001];
int main()
{
	int j,n,k,i,min,min_pos,ans,acc;
	struct visitor* v;
	struct visitor* res;
	v=(visitor*)malloc(1001*sizeof(visitor));
	res=(visitor*)malloc(1001*sizeof(visitor));
	ans=0;
	acc=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>v[i].people;
		cin>>v[i].spend;
		v[i].num=i+1;
	}
	cin>>k;
	for(i=0;i<k;i++){
		cin>>tables[i];
	}

	sort(v,v+n,cmp);

	//cout<<"Test"<<endl;
	//for(i=0;i<n;i++)
	//	cout<<v[i].spend<<endl;

	for(i=0;i<n;i++){
		min=INF;
		min_pos=-1;
		for(j=0;j<k;j++){
			if(v[i].people>tables[j])
				continue;
			else {
				if(!taken[j]){
					if(tables[j]-v[i].people<min){
						min=tables[j]-v[i].people;
						min_pos=j+1;
					}
				}
			}
		}
		if(min_pos!=-1){
			taken[min_pos-1]=1;
			ans+=v[i].spend;
			
			res[acc].spend=v[i].spend;
			res[acc].num=v[i].num;
			res[acc].table=min_pos;
			//res.push_back(new_vis);
			//cout<<"Check: "<<min_pos<<endl;
			acc++;
		}
	}
	//for(i=0;i<acc;i++){
	//	cout<<res[i].num<<" "<<res[i].table<<endl;
	//}
	cout<<acc<<" "<<ans<<endl;
	sort(res,res+acc,cmp1);
	for(i=0;i<acc;i++){
		cout<<res[i].num<<" "<<res[i].table<<endl;
	}
	return 0;
}