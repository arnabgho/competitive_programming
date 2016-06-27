#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

long long int arr[301][301];
long long int arr1[301][301];
long long int arr2[301][301];
long long int arr3[301][301];
long long int arr4[301][301];
long long int arr5[301][301];
long long int arr6[301][301];
long long int arr7[301][301];
long long int arr8[301][301];
long long int arr9[301][301];
long long int arr10[301][301];

int main(){
	long long int i,j,n,q,x1,y1,x2,y2,k,p,flag=0,s1,s2,s3,s4;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){	
		for(j=1;j<=n;j++){
			scanf("%lld",&arr[i][j]);
		}		
	}	
	if(arr[1][1]==1)
		arr1[1][1]=1;
	

	if(arr[1][1]==2)
		arr2[1][1]=1;

	if(arr[1][1]==3)
		arr3[1][1]=1;

	if(arr[1][1]==4)
		arr4[1][1]=1;

	if(arr[1][1]==5)
		arr5[1][1]=1;

	if(arr[1][1]==6)
		arr6[1][1]=1;

	if(arr[1][1]==7)
		arr7[1][1]=1;

	if(arr[1][1]==8)
		arr8[1][1]=1;

	if(arr[1][1]==9)
		arr9[1][1]=1;

	if(arr[1][1]==10)
		arr10[1][1]=1;



	for(i=2;i<=n;i++){
		arr1[i][1]=arr1[i-1][1]+(arr[i][1]==1);
		arr2[i][1]=arr2[i-1][1]+(arr[i][1]==2);		
		arr3[i][1]=arr3[i-1][1]+(arr[i][1]==3);
		arr4[i][1]=arr4[i-1][1]+(arr[i][1]==4);
		arr5[i][1]=arr5[i-1][1]+(arr[i][1]==5);
		arr6[i][1]=arr6[i-1][1]+(arr[i][1]==6);	
		arr7[i][1]=arr7[i-1][1]+(arr[i][1]==7);	
		arr8[i][1]=arr8[i-1][1]+(arr[i][1]==8);
		arr9[i][1]=arr9[i-1][1]+(arr[i][1]==9);
		arr10[i][1]=arr10[i-1][1]+(arr[i][1]==10);
	}		

	for(i=2;i<=n;i++){
		arr1[1][i]=arr1[1][i-1]+(arr[1][i]==1);
		arr2[1][i]=arr2[1][i-1]+(arr[1][i]==2);		
		arr3[1][i]=arr3[1][i-1]+(arr[1][i]==3);
		arr4[1][i]=arr4[1][i-1]+(arr[1][i]==4);
		arr5[1][i]=arr5[1][i-1]+(arr[1][i]==5);
		arr6[1][i]=arr6[1][i-1]+(arr[1][i]==6);	
		arr7[1][i]=arr7[1][i-1]+(arr[1][i]==7);	
		arr8[1][i]=arr8[1][i-1]+(arr[1][i]==8);
		arr9[1][i]=arr9[1][i-1]+(arr[1][i]==9);
		arr10[1][i]=arr10[1][i-1]+(arr[1][i]==10);
	}	

	for(i=2;i<=n;i++){
		for(j=2;j<=n;j++){
			arr1[i][j]=arr1[i][j-1]+arr1[i-1][j]-arr1[i-1][j-1] + (arr[i][j]==1);
			arr2[i][j]=arr2[i][j-1]+arr2[i-1][j]-arr2[i-1][j-1] + (arr[i][j]==2);
			arr3[i][j]=arr3[i][j-1]+arr3[i-1][j]-arr3[i-1][j-1] + (arr[i][j]==3);
			arr4[i][j]=arr4[i][j-1]+arr4[i-1][j]-arr4[i-1][j-1] + (arr[i][j]==4);
			arr5[i][j]=arr5[i][j-1]+arr5[i-1][j]-arr5[i-1][j-1] + (arr[i][j]==5);
			arr6[i][j]=arr6[i][j-1]+arr6[i-1][j]-arr6[i-1][j-1] + (arr[i][j]==6);
			arr7[i][j]=arr7[i][j-1]+arr7[i-1][j]-arr7[i-1][j-1] + (arr[i][j]==7);
			arr8[i][j]=arr8[i][j-1]+arr8[i-1][j]-arr8[i-1][j-1] + (arr[i][j]==8);
			arr9[i][j]=arr9[i][j-1]+arr9[i-1][j]-arr9[i-1][j-1] + (arr[i][j]==9);
			arr10[i][j]=arr10[i][j-1]+arr10[i-1][j]-arr10[i-1][j-1] + (arr[i][j]==10);
		}	
	}

	scanf("%lld",&q);
	for(i=1;i<=q;i++){
		p=0;
		scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
			
		if(x1>1 && y1>1){
			s1=arr1[x1-1][y1-1];
			s2=arr1[x2][y2];
			s3=arr1[x2][y1-1];
			s4=arr1[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);
			if(s1+s2-s3-s4>0)
				p++;			
		}	

		if(x1>1 && y1>1 ){
			s1=arr2[x1-1][y1-1];
			s2=arr2[x2][y2];
			s3=arr2[x2][y1-1];
			s4=arr2[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}
		
		if(x1>1 && y1>1){
			s1=arr3[x1-1][y1-1];
			s2=arr3[x2][y2];
			s3=arr3[x2][y1-1];
			s4=arr3[x1-1][y2];
			
	//		printf("%lld %lld %lld %lld\n",s1,s2,s3,s4);

	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arr4[x1-1][y1-1];
			s2=arr4[x2][y2];
			s3=arr4[x2][y1-1];
			s4=arr4[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arr5[x1-1][y1-1];
			s2=arr5[x2][y2];
			s3=arr5[x2][y1-1];
			s4=arr5[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arr6[x1-1][y1-1];
			s2=arr6[x2][y2];
			s3=arr6[x2][y1-1];
			s4=arr6[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arr7[x1-1][y1-1];
			s2=arr7[x2][y2];
			s3=arr7[x2][y1-1];
			s4=arr7[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arr8[x1-1][y1-1];
			s2=arr8[x2][y2];
			s3=arr8[x2][y1-1];
			s4=arr8[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arr9[x1-1][y1-1];
			s2=arr9[x2][y2];
			s3=arr9[x2][y1-1];
			s4=arr9[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arr10[x1-1][y1-1];
			s2=arr10[x2][y2];
			s3=arr10[x2][y1-1];
			s4=arr10[x1-1][y2];
			
		//	printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1==1 && y1==1){

			s1=arr1[x2][y2];
			//printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arr2[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}		
		
		if(x1==1 && y1==1){

			s1=arr3[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arr4[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arr5[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arr6[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arr7[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arr8[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arr9[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arr10[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1>1){
			s1=arr1[x2][y2];
			s2=arr1[x2][y1-1];
		//	printf("%lld\n",s1-s2);
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr1[x2][y2];
			s2=arr1[x1-1][y2];
		//	printf("%lld\n",s1-s2);			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr2[x2][y2];
			s2=arr2[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr2[x2][y2];
			s2=arr2[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}		

		if(x1==1 && y1>1){
			s1=arr3[x2][y2];
			s2=arr3[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr3[x2][y2];
			s2=arr3[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr4[x2][y2];
			s2=arr4[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr4[x2][y2];
			s2=arr4[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr5[x2][y2];
			s2=arr5[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr5[x2][y2];
			s2=arr5[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr6[x2][y2];
			s2=arr6[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr6[x2][y2];
			s2=arr6[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr7[x2][y2];
			s2=arr7[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr7[x2][y2];
			s2=arr7[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr8[x2][y2];
			s2=arr8[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr8[x2][y2];
			s2=arr8[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr9[x2][y2];
			s2=arr9[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr9[x2][y2];
			s2=arr9[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arr10[x2][y2];
			s2=arr10[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arr10[x2][y2];
			s2=arr10[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		printf("%lld\n",p);

	}

	return 0;
}	
