#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool sync_with_stdio (bool sync = true);

bool isPal(string s,int n){
	int left=0,right=n-1,pos=1;
	while(left<=right && pos){
		if(s[left]!=s[right]){
			pos=0;
			break;
		}
		left++;right--;
	}
	return pos;
}

int main()
{
	
	string s="";
	int left,right,used,n,t,pos;
	cin>>t;
	while(t--){
		s="";
		cin>>s;
		n=s.size();
		pos=1;
		left=0;right=n-1;used=0;
		while(left<=right && pos){
			if(s[left]!=s[right] && pos && used){
				pos=0;
				break;
			}
			else if(s[left]!=s[right] && pos && !used){
				used=1;
				if(s[left+1]==s[right]){
					left+=2;right--;continue;
				}
				else if(s[left]==s[right-1]){
					left++;right-=2;continue;
				}
			}
			else if(s[left]==s[right]){left++;right--;}
		}
		if(pos && used) cout<<"YES\n";
		else if(pos && !used) {
			if(n%2==1) cout<<"YES\n";
			else{
				if(s[n/2]==s[n/2-1])
					cout<<"YES\n";
				else
					cout<<"NO\n";
			} 
		}
		else if(!pos) cout<<"NO\n";
	}

	return 0;
}