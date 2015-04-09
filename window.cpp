#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <stdlib.h>
#include <unordered_map>
#include <string>
using namespace std;

#define INF 10000;
class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char,int> T_map;
        unordered_map<char,int> F;
        string res="";
        int i,j,T_size,S_size,distinct=0;
        T_size=T.size();
        S_size=S.size();
        for(i=0;i<T_size;i++){
            if(T_map[T[i]]==0) distinct++;
            T_map[T[i]]++;
        }
        int left=0;int right=0;int found=0;int ans_left=0;int ans_right=0;
        int g_left=0;int g_right=0;int minim=INF;int pos=1;
        while(left<S_size && right<S_size){
            while(right<S_size && found!=distinct && left<=right){
                if(T_map[S[right]]>0){
                    F[S[right]]++;
                    if(F[S[right]]==T_map[S[right]])
                        found++;
                }
                if(found!=distinct)
                    right++;
            }        
            if(found!=distinct) pos=0;
            else pos=1;
            ans_right=right;
            cout<<"ans_right : "<<ans_right<<" found :"<<found<<endl;

            if(ans_right-ans_left<minim && pos){
                minim=ans_right-ans_left;
                g_left=ans_left;g_right=ans_right;
            }
            while(left<S_size && found==distinct){
                cout<<"S[left]: "<<S[left]<<" T_map: "<<T_map[S[left]]<<" found  : "<<found<< " distinct :"<<distinct<<endl;
                if(T_map[S[left]]>0){
                    F[S[left]]--;
                    if(F[S[left]]<T_map[S[left]])
                        found--;
                }
                if(found==distinct)
                    left++;               
            }
            ans_left=left;
            cout<<"ans_left : "<<ans_left<<" found :"<<found<<endl;
            if(ans_right-ans_left<minim && pos){
                minim=ans_right-ans_left;
                g_left=ans_left;g_right=ans_right;
            }
            left++;
            right++;
        }
        cout<<"minim: "<<minim<<endl;

        if(minim!=10000){
            for(i=g_left;i<=g_right;i++){
                res+=S[i];
            }    
        } 
        return res;   
    }
};

int main()
{
    Solution * sol;
    sol=(Solution *)malloc(sizeof(Solution));
    string S="abc";
    string T="ab";
    string res="";
    res=sol->minWindow(S,T);
    cout<<res<<endl;
    return 0;
}