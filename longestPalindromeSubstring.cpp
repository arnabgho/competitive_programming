#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

int DP[1001];
class Solution {
public:
    int checkPal(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end])
                return 0;
            start++;
            end--;
        }
        return 1;
        
    }

    string longestPalindrome(string s) {
        int size=s.size();
        int i,max,max_pos;
        DP[0]=1;
        
        max=1;
        max_pos=0;
        string res="";
        if(size<2){
            res+=s[0];
            return res;
        }
        
        if(s[1]==s[0]){
            DP[1]=2;
            if(DP[1]>max){
                max=DP[1];
                max_pos=1;
            }
        }    
        else 
            DP[1]=1;
            
          
        for(i=2;i<size;i++){
            if(DP[i-1]>1){
                if(s[i-DP[i-1]-1]==s[i] && checkPal(s,i-DP[i-1],i-1))
                    DP[i]=DP[i-1]+2;
                else if(s[i-DP[i-1]]==s[i] && checkPal(s,i-DP[i-1]+1,i-1))
                    DP[i]=DP[i-1]+1;
                else if(s[i-DP[i-1]+1]==s[i] && checkPal(s,i-DP[i-1]+2,i-1))
                    DP[i]=DP[i-1];
                else{
                    //cout<<"Hello";
                    DP[i]=1;
                }
            }
            else if(DP[i-1]==1){
                if(s[i-2]==s[i])
                    DP[i]=3;
                else if(s[i-1]==s[i])
                    DP[i]=2;
                else
                    DP[i]=1;
            }
            if(DP[i]>max){
                max=DP[i];
                max_pos=i;
            }
        }    
        
        for(i=0;i<size;i++)
            cout<<DP[i]<<endl;
            cout<<"Max: "<<max<<" Maxpos: "<<max_pos<<endl;

        for(i=max_pos-max+1;i<=max_pos;i++)
            res+=s[i];
        return res;    
        
    }
};

int main(){
    Solution s;
   // string check="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string check="aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa";
    cout<<s.longestPalindrome(check);
    cout<<endl;
    return 0;
}

