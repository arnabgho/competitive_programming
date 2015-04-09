#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int arr[257];
    int lengthOfLongestSubstring(string s) {
        char ch;
        int i,maxim,size;
        int DP;
        size=s.size();
        if(size==0)
            return 0;
        for(i=0;i<=256;i++)
            arr[i]=-1;
        ch=s[0];
        arr[ch]=0;
        DP=1;
        maxim=1;
        for(i=1;i<size;i++){
            ch=s[i];
            if(s[i]!=s[i-1]){
                DP=min(DP+1,i-arr[ch]);
            }
            else
                DP=1;
            maxim=max(DP,maxim); 
            cout<<"i: "<<i<<" DP "<<DP<<" maxim: "<<maxim<<endl;
            arr[ch]=i;
        }
        return maxim;
    }
};

int main(){
    int res;
    string s="wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    Solution* sol;
    sol=(Solution*)malloc(sizeof(Solution));
    res=sol->lengthOfLongestSubstring(s);
    cout<<res<<endl;
    return 0;
}