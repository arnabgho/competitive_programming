#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <stdlib.h>
using namespace std;

struct ob{int pos,val;};

bool cmp(struct ob a,struct ob b){
	return a.val<b.val;
}



int main(){
	int n,k,s,m,val,diff,i;
	vector<struct ob> orig;
	vector<struct ob> manip;
	struct ob * newob1,*newob2;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		newob2=(struct ob *)malloc(sizeof(struct ob)); 
		newob1=(struct ob *)malloc(sizeof(struct ob)); 
		cin>>val;
		newob1->val=val;
		newob1->pos=i;
		newob2->val=val;
		newob2->pos=i;
		orig.push_back(*newob1);
		manip.push_back(*newob2);
	}

	sort(orig.begin(), orig.end(),cmp);
	sort(manip.begin(), manip.end(),cmp);

	diff=manip[n-1].val-manip[0].val;
	if(diff==0 || diff==1){
		s=diff;m=0;
		cout<<s<<" "<<m<<endl;
	}
	else{
		m=0;
		while(diff!=0 && diff!=1 && m<k){
			manip[0].val++;
			manip[n-1].val--;
			m++;
			sort(manip.begin(),manip.end(),cmp);
			diff=manip[n-1].val-manip[0].val;
		}
		s=diff;
		cout<<s<<" "<<m<<endl;
		for(i=1;i<=m;i++){
			cout<<orig[n-1].pos<<" "<<orig[0].pos<<endl;
			orig[0].val++;
			orig[n-1].val--;
			sort(orig.begin(),orig.end(),cmp);
			diff=orig[n-1].val-orig[0].val;
		}
	}
	return 0;
}