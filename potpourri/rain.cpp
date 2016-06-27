#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ob{
      int rank,height,pos;  
};
bool myfunc(ob a,ob b){
       return a.height>b.height;
}
class Solution {
public:
    
    
    int trap(int A[], int n) {
        int cap,inc,i,left,right,lind,rind,minim,j,k;
        vector<struct ob> myvec;
        int *taken;
        taken=(int *)malloc(n*sizeof(int));
        struct ob* newob;
        if(n==0 || n==1)
            return 0;
        for(i=0;i<n;i++){
            newob=(struct ob*)malloc(sizeof(struct ob));
            newob->height=A[i];
            newob->pos=i;
            myvec.push_back(*newob);
        }
        std::sort(myvec.begin(),myvec.end(),myfunc);
        myvec[0].rank=1;
        i=0;
        while(i<n-1){
            while(i<n-1 && myvec[i].height==myvec[i+1].height){
                myvec[i+1].rank=myvec[i].rank;
                i++;
            }
            i++;
            if(i<n)
                myvec[i].rank=myvec[i-1].rank+1;
        }
        cap=0;
        for(i=0;i<n;i++){
            cout<<"sorted: "<<endl;
            cout<<"Height "<<myvec[i].height<<" Rank :";
            cout<<myvec[i].rank<<endl;
        }

       for( i=0;i<n-1;i++){
           j=i+1;
           while(myvec[j].rank-myvec[i].rank<=1 && j<n){
               for(k=min(myvec[i].pos,myvec[j].pos);k<=max(myvec[i].pos,myvec[j].pos);k++){
                   if(!taken[k] && myvec[j].height>A[k]){
                       taken[k]=1;
                       cap+=myvec[j].height-A[k];
                       cout<<"k: "<<k<<" A[k] : "<<A[k]<<" myvec[j]: "<<myvec[j].height<<endl;
                   }
               }
               cout<<"Hello\n";
               j++;
           }
       }
        return cap;
    }
};

int main(){
    int A[4];
    A[0]=5;A[1]=4;A[2]=1;A[3]=2;
    Solution* sol;
    sol=(Solution*)malloc(sizeof(Solution));
    int res=sol->trap(A,4);
    cout<<res<<endl;
    return 0;
}