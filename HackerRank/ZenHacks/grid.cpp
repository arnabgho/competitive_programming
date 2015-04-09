#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long int c,r;
    cin>>r>>c;
    long long int k=(r-1)/2;
    long long int res=0;
    res=k*10;
    if(r%2==1){
        res+=2*(c-1);
    }    
    else{
        res+=2*c-1;   
    }
    cout<<res<<endl;
    return 0;
}