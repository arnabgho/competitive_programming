#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct co{
	int cox,coy;
};

bool cmp (  co a , co b)											//an auxillary function used for the use of the library function 																					sort
{
	return b.coy < a.coy;
}

 class CatchTheBeatEasy{

public :



int mod (int x){
	return (x>=0) ? (x):(-x);
}



string ableToCatchAll(vector <int> x, vector <int> y){
 const	int  len =x.size();
 int i,ch;
 struct  co * cord;
 cord=(struct co*)calloc(len,sizeof(struct co));
 for(i=0;i<len;i++){
 	cord[i].cox=x[i];
 	cord[i].coy=y[i];
 }
 std::sort( cord, cord + len ,cmp);
 ch=1;
 for(i=1;i<len;i++){
 	if(mod(cord[i].cox-cord[i-1].cox)> mod(cord[i].coy-cord[i-1].coy)){
 		ch=0;
 		break;
 	}
 
 }
 
if(ch==1)
	return "Able to catch";
	
else
	return "Not able to catch";

}
};
