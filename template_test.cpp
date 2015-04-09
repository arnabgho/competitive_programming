#include<stdio.h>
#include<iostream>

using namespace std;

template <typename T>
T min(T a,T b)
{
	return (a<b ? a:b);
}

int main(){
	cout<<min(3,4)<<'\n';
	cout<<min(6.9,3.5)<<'\n';
	cout<<min('t','g')<<'\n';
	return 0;
}
