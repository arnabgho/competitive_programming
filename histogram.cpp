#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct histo{
    int mini,area;
};
int miniim(int a,int b){return a<b ? a:b;}
int mini [1001][1001];
int area [1001][1001];

int opt_mini[100001];
int prev_opt_mini[100001];
class Solution {
public:
    void copy(int size){
        for(int i=0;i<size;i++){
            prev_opt_mini[i]=opt_mini[i];
        }
    }

    int largestRectangleArea(vector<int> &height) {
        int i,j,size,max,off;
        size=(height).size();
        cout<<"size: "<<size<<endl;
        //cout<<"HIST "<<hist[i][j].mini<<endl;
        max=0;

        for(i=0;i<size;i++){
            //cout<<"Error1\n";
            //mini[i][i]=(height)[i];
            //area[i][i]=(height)[i];

            opt_mini[i]=height[i];
            if(opt_mini[i]>max)
                    max=opt_mini[i];
            //cout<<"Error\n";    
        }    
        
        copy(size);

        for(off=1;off<size;off++){
            for(i=0;i<size-off;i++){
                j=i+off;
               // mini[i][j]=miniim(mini[i][j-1],(height)[j]);
               // area[i][j]=mini[i][j]*(j-i+1);

                opt_mini[i]=miniim(opt_mini[i],height[j]);
                

                if(opt_mini[i]*(off+1)>max)
                    max=opt_mini[i]*(off+1);
            }
            copy(size);
        }
        return max;
    }
    
};

int main(){
    vector<int> myvec;
    Solution s;
    int n,t;
    cout<<"Enter the no. numbers\n";
    cin>>t;
    while(t--){
        cin>>n;
        myvec.push_back(n);
    }

    cout<<s.largestRectangleArea(myvec);
    cout<<endl;
    return 0;
}