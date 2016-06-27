#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<ctype.h>
using namespace std;

char arr[101][101];
long long int arra[101][101];
long long int arrb[101][101];
long long int arrc[101][101];
long long int arrd[101][101];
long long int arre[101][101];
long long int arrf[101][101];
long long int arrg[101][101];
long long int arrh[101][101];
long long int arri[101][101];
long long int arrj[101][101];
long long int arrk[101][101];
long long int arrl[101][101];
long long int arrm[101][101];
long long int arrn[101][101];
long long int arro[101][101];
long long int arrp[101][101];
long long int arrq[101][101];
long long int arrr[101][101];
long long int arrs[101][101];
long long int arrt[101][101];
long long int arru[101][101];
long long int arrv[101][101];
long long int arrw[101][101];
long long int arrx[101][101];
long long int arry[101][101];
long long int arrz[101][101];




int main(){
	long long int i,j,n,q,x1,y1,x2,y2,k,p,flag=0,s1,s2,s3,s4,m,res;
	scanf("%lld %lld %lld\n",&m,&n,&k);
	for(i=1;i<=m;i++){	
		for(j=1;j<=n;j++){
		//	scanf("%c",&arr[i][j]);
			cin>>arr[i][j];
			arr[i][j]=tolower(arr[i][j]);
		}		
		//scanf("\n");
	}	
	//printf("%lld %lld %lld\n",m,n,k);
	if(arr[1][1]=='a')
		arra[1][1]=1;
	

	if(arr[1][1]=='b')
		arrb[1][1]=1;

	if(arr[1][1]=='c')
		arrc[1][1]=1;

	if(arr[1][1]=='d')
		arrd[1][1]=1;

	if(arr[1][1]=='e')
		arre[1][1]=1;

	if(arr[1][1]=='f')
		arrf[1][1]=1;

	if(arr[1][1]=='g')
		arrg[1][1]=1;

	if(arr[1][1]=='h')
		arrh[1][1]=1;

	if(arr[1][1]=='i')
		arri[1][1]=1;

	if(arr[1][1]=='j')
		arrj[1][1]=1;

	if(arr[1][1]=='k')
		arrk[1][1]=1;
	

	if(arr[1][1]=='l')
		arrl[1][1]=1;

	if(arr[1][1]=='m')
		arrm[1][1]=1;

	if(arr[1][1]=='n')
		arrn[1][1]=1;

	if(arr[1][1]=='o')
		arro[1][1]=1;

	if(arr[1][1]=='p')
		arrp[1][1]=1;

	if(arr[1][1]=='q')
		arrq[1][1]=1;

	if(arr[1][1]=='r')
		arrr[1][1]=1;

	if(arr[1][1]=='s')
		arrs[1][1]=1;

	if(arr[1][1]=='t')
		arrt[1][1]=1;

	if(arr[1][1]=='u')
		arru[1][1]=1;

	if(arr[1][1]=='v')
		arrv[1][1]=1;

	if(arr[1][1]=='w')
		arrw[1][1]=1;

	if(arr[1][1]=='x')
		arrx[1][1]=1;

	if(arr[1][1]=='y')
		arry[1][1]=1;

	if(arr[1][1]=='z')
		arrz[1][1]=1;

	for(i=2;i<=m;i++){
		arra[i][1]=arra[i-1][1]+(arr[i][1]=='a');
		arrb[i][1]=arrb[i-1][1]+(arr[i][1]=='b');		
		arrc[i][1]=arrc[i-1][1]+(arr[i][1]=='c');
		arrd[i][1]=arrd[i-1][1]+(arr[i][1]=='d');
		arre[i][1]=arre[i-1][1]+(arr[i][1]=='e');
		arrf[i][1]=arrf[i-1][1]+(arr[i][1]=='f');	
		arrg[i][1]=arrg[i-1][1]+(arr[i][1]=='g');	
		arrh[i][1]=arrh[i-1][1]+(arr[i][1]=='h');
		arri[i][1]=arri[i-1][1]+(arr[i][1]=='i');
		arrj[i][1]=arrj[i-1][1]+(arr[i][1]=='j');
		arrk[i][1]=arrk[i-1][1]+(arr[i][1]=='k');
		arrl[i][1]=arrl[i-1][1]+(arr[i][1]=='l');		
		arrm[i][1]=arrm[i-1][1]+(arr[i][1]=='m');
		arrn[i][1]=arrn[i-1][1]+(arr[i][1]=='n');
		arro[i][1]=arro[i-1][1]+(arr[i][1]=='o');
		arrp[i][1]=arrp[i-1][1]+(arr[i][1]=='p');	
		arrq[i][1]=arrq[i-1][1]+(arr[i][1]=='q');	
		arrr[i][1]=arrr[i-1][1]+(arr[i][1]=='r');
		arrs[i][1]=arrs[i-1][1]+(arr[i][1]=='s');
		arrt[i][1]=arrt[i-1][1]+(arr[i][1]=='t');
		arru[i][1]=arru[i-1][1]+(arr[i][1]=='u');
		arrv[i][1]=arrv[i-1][1]+(arr[i][1]=='v');	
		arrw[i][1]=arrw[i-1][1]+(arr[i][1]=='w');	
		arrx[i][1]=arrx[i-1][1]+(arr[i][1]=='x');
		arry[i][1]=arry[i-1][1]+(arr[i][1]=='y');
		arrz[i][1]=arrz[i-1][1]+(arr[i][1]=='z');
	}		

	for(i=2;i<=n;i++){
		arra[1][i]=arra[1][i-1]+(arr[1][i]=='a');
		arrb[1][i]=arrb[1][i-1]+(arr[1][i]=='b');		
		arrc[1][i]=arrc[1][i-1]+(arr[1][i]=='c');
		arrd[1][i]=arrd[1][i-1]+(arr[1][i]=='d');
		arre[1][i]=arre[1][i-1]+(arr[1][i]=='e');
		arrf[1][i]=arrf[1][i-1]+(arr[1][i]=='f');	
		arrg[1][i]=arrg[1][i-1]+(arr[1][i]=='g');	
		arrh[1][i]=arrh[1][i-1]+(arr[1][i]=='h');
		arri[1][i]=arri[1][i-1]+(arr[1][i]=='i');
		arrj[1][i]=arrj[1][i-1]+(arr[1][i]=='j');
		arrk[1][i]=arrk[1][i-1]+(arr[1][i]=='k');
		arrl[1][i]=arrl[1][i-1]+(arr[1][i]=='l');		
		arrm[1][i]=arrm[1][i-1]+(arr[1][i]=='m');
		arrn[1][i]=arrn[1][i-1]+(arr[1][i]=='n');
		arro[1][i]=arro[1][i-1]+(arr[1][i]=='o');
		arrp[1][i]=arrp[1][i-1]+(arr[1][i]=='p');	
		arrq[1][i]=arrq[1][i-1]+(arr[1][i]=='q');	
		arrr[1][i]=arrr[1][i-1]+(arr[1][i]=='r');
		arrs[1][i]=arrs[1][i-1]+(arr[1][i]=='s');
		arrt[1][i]=arrt[1][i-1]+(arr[1][i]=='t');
		arru[1][i]=arru[1][i-1]+(arr[1][i]=='u');
		arrv[1][i]=arrv[1][i-1]+(arr[1][i]=='v');	
		arrw[1][i]=arrw[1][i-1]+(arr[1][i]=='w');	
		arrx[1][i]=arrx[1][i-1]+(arr[1][i]=='x');
		arry[1][i]=arry[1][i-1]+(arr[1][i]=='y');
		arrz[1][i]=arrz[1][i-1]+(arr[1][i]=='z');
	}	
	res=0;
	for(i=2;i<=m;i++){
		for(j=2;j<=n;j++){
			arra[i][j]=arra[i][j-1]+arra[i-1][j]-arra[i-1][j-1] + (arr[i][j]=='a');
			arrb[i][j]=arrb[i][j-1]+arrb[i-1][j]-arrb[i-1][j-1] + (arr[i][j]=='b');
			arrc[i][j]=arrc[i][j-1]+arrc[i-1][j]-arrc[i-1][j-1] + (arr[i][j]=='c');
			arrd[i][j]=arrd[i][j-1]+arrd[i-1][j]-arrd[i-1][j-1] + (arr[i][j]=='d');
			arre[i][j]=arre[i][j-1]+arre[i-1][j]-arre[i-1][j-1] + (arr[i][j]=='e');
			arrf[i][j]=arrf[i][j-1]+arrf[i-1][j]-arrf[i-1][j-1] + (arr[i][j]=='f');
			arrg[i][j]=arrg[i][j-1]+arrg[i-1][j]-arrg[i-1][j-1] + (arr[i][j]=='g');
			arrh[i][j]=arrh[i][j-1]+arrh[i-1][j]-arrh[i-1][j-1] + (arr[i][j]=='h');
			arri[i][j]=arri[i][j-1]+arri[i-1][j]-arri[i-1][j-1] + (arr[i][j]=='i');
			arrj[i][j]=arrj[i][j-1]+arrj[i-1][j]-arrj[i-1][j-1] + (arr[i][j]=='j');
			arrk[i][j]=arrk[i][j-1]+arrk[i-1][j]-arrk[i-1][j-1] + (arr[i][j]=='k');
			arrl[i][j]=arrl[i][j-1]+arrl[i-1][j]-arrl[i-1][j-1] + (arr[i][j]=='l');
			arrm[i][j]=arrm[i][j-1]+arrm[i-1][j]-arrm[i-1][j-1] + (arr[i][j]=='m');
			arrn[i][j]=arrn[i][j-1]+arrn[i-1][j]-arrn[i-1][j-1] + (arr[i][j]=='n');
			arro[i][j]=arro[i][j-1]+arro[i-1][j]-arro[i-1][j-1] + (arr[i][j]=='o');
			arrp[i][j]=arrp[i][j-1]+arrp[i-1][j]-arrp[i-1][j-1] + (arr[i][j]=='p');
			arrq[i][j]=arrq[i][j-1]+arrq[i-1][j]-arrq[i-1][j-1] + (arr[i][j]=='q');
			arrr[i][j]=arrr[i][j-1]+arrr[i-1][j]-arrr[i-1][j-1] + (arr[i][j]=='r');
			arrs[i][j]=arrs[i][j-1]+arrs[i-1][j]-arrs[i-1][j-1] + (arr[i][j]=='s');
			arrt[i][j]=arrt[i][j-1]+arrt[i-1][j]-arrt[i-1][j-1] + (arr[i][j]=='t');
			arru[i][j]=arru[i][j-1]+arru[i-1][j]-arru[i-1][j-1] + (arr[i][j]=='u');
			arrv[i][j]=arrv[i][j-1]+arrv[i-1][j]-arrv[i-1][j-1] + (arr[i][j]=='v');
			arrw[i][j]=arrw[i][j-1]+arrw[i-1][j]-arrw[i-1][j-1] + (arr[i][j]=='w');
			arrx[i][j]=arrx[i][j-1]+arrx[i-1][j]-arrx[i-1][j-1] + (arr[i][j]=='x');
			arry[i][j]=arry[i][j-1]+arry[i-1][j]-arry[i-1][j-1] + (arr[i][j]=='y');
			arrz[i][j]=arrz[i][j-1]+arrz[i-1][j]-arrz[i-1][j-1] + (arr[i][j]=='z');
		}	
	}


	//

	for(x1=1;x1<=m;x1++){

	for(y1=1;y1<=n;y1++){

	for(x2=x1;x2<=m;x2++){

	for(y2=y1;y2<=n;y2++){

		p=0;
		//scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
			
		if(x1>1 && y1>1){
			s1=arra[x1-1][y1-1];
			s2=arra[x2][y2];
			s3=arra[x2][y1-1];
			s4=arra[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);
			if(s1+s2-s3-s4>0)
				p++;			
		}	

		if(x1>1 && y1>1 ){
			s1=arrb[x1-1][y1-1];
			s2=arrb[x2][y2];
			s3=arrb[x2][y1-1];
			s4=arrb[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}
		
		if(x1>1 && y1>1){
			s1=arrc[x1-1][y1-1];
			s2=arrc[x2][y2];
			s3=arrc[x2][y1-1];
			s4=arrc[x1-1][y2];
			
	//		printf("%lld %lld %lld %lld\n",s1,s2,s3,s4);

	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arrd[x1-1][y1-1];
			s2=arrd[x2][y2];
			s3=arrd[x2][y1-1];
			s4=arrd[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arre[x1-1][y1-1];
			s2=arre[x2][y2];
			s3=arre[x2][y1-1];
			s4=arre[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arrf[x1-1][y1-1];
			s2=arrf[x2][y2];
			s3=arrf[x2][y1-1];
			s4=arrf[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arrg[x1-1][y1-1];
			s2=arrg[x2][y2];
			s3=arrg[x2][y1-1];
			s4=arrg[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arrh[x1-1][y1-1];
			s2=arrh[x2][y2];
			s3=arrh[x2][y1-1];
			s4=arrh[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arri[x1-1][y1-1];
			s2=arri[x2][y2];
			s3=arri[x2][y1-1];
			s4=arri[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arrj[x1-1][y1-1];
			s2=arrj[x2][y2];
			s3=arrj[x2][y1-1];
			s4=arrj[x1-1][y2];
			
		//	printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arrk[x1-1][y1-1];
			s2=arrk[x2][y2];
			s3=arrk[x2][y1-1];
			s4=arrk[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);
			if(s1+s2-s3-s4>0)
				p++;			
		}	

		if(x1>1 && y1>1 ){
			s1=arrl[x1-1][y1-1];
			s2=arrl[x2][y2];
			s3=arrl[x2][y1-1];
			s4=arrl[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}
		
		if(x1>1 && y1>1){
			s1=arrm[x1-1][y1-1];
			s2=arrm[x2][y2];
			s3=arrm[x2][y1-1];
			s4=arrm[x1-1][y2];
			
	//		printf("%lld %lld %lld %lld\n",s1,s2,s3,s4);

	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arrn[x1-1][y1-1];
			s2=arrn[x2][y2];
			s3=arrn[x2][y1-1];
			s4=arrn[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arro[x1-1][y1-1];
			s2=arro[x2][y2];
			s3=arro[x2][y1-1];
			s4=arro[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arrp[x1-1][y1-1];
			s2=arrp[x2][y2];
			s3=arrp[x2][y1-1];
			s4=arrp[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arrq[x1-1][y1-1];
			s2=arrq[x2][y2];
			s3=arrq[x2][y1-1];
			s4=arrq[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arrr[x1-1][y1-1];
			s2=arrr[x2][y2];
			s3=arrr[x2][y1-1];
			s4=arrr[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arrs[x1-1][y1-1];
			s2=arrs[x2][y2];
			s3=arrs[x2][y1-1];
			s4=arrs[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arrt[x1-1][y1-1];
			s2=arrt[x2][y2];
			s3=arrt[x2][y1-1];
			s4=arrt[x1-1][y2];
			
		//	printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arru[x1-1][y1-1];
			s2=arru[x2][y2];
			s3=arru[x2][y1-1];
			s4=arru[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arrv[x1-1][y1-1];
			s2=arrv[x2][y2];
			s3=arrv[x2][y1-1];
			s4=arrv[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1){
			s1=arrw[x1-1][y1-1];
			s2=arrw[x2][y2];
			s3=arrw[x2][y1-1];
			s4=arrw[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arrx[x1-1][y1-1];
			s2=arrx[x2][y2];
			s3=arrx[x2][y1-1];
			s4=arrx[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1>1 && y1>1 ){
			s1=arry[x1-1][y1-1];
			s2=arry[x2][y2];
			s3=arry[x2][y1-1];
			s4=arry[x1-1][y2];
			
		//	printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}


		if(x1>1 && y1>1){
			s1=arrz[x1-1][y1-1];
			s2=arrz[x2][y2];
			s3=arrz[x2][y1-1];
			s4=arrz[x1-1][y2];
			
	//		printf("%lld\n",s1+s2-s3-s4);			
			if(s1+s2-s3-s4>0)
				p++;			
		}

		if(x1==1 && y1==1){

			s1=arra[x2][y2];
			//printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrb[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}		



		if(x1==1 && y1==1){

			s1=arrc[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrd[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arre[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrf[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrg[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arrh[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arri[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arrj[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrk[x2][y2];
			//printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrl[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}		



		if(x1==1 && y1==1){

			s1=arrm[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrn[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arro[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrp[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrq[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arrr[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrs[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arrt[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arru[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrv[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arrw[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arrx[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1==1){

			s1=arry[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}


		if(x1==1 && y1==1){

			s1=arrz[x2][y2];
		//	printf("%lld\n",s1);
			if(s1>0)
				p++;
		}

		if(x1==1 && y1>1){
			s1=arra[x2][y2];
			s2=arra[x2][y1-1];
		//	printf("%lld\n",s1-s2);
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arra[x2][y2];
			s2=arra[x1-1][y2];
		//	printf("%lld\n",s1-s2);			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrb[x2][y2];
			s2=arrb[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrb[x2][y2];
			s2=arrb[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}		

		if(x1==1 && y1>1){
			s1=arrc[x2][y2];
			s2=arrc[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrc[x2][y2];
			s2=arrc[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrd[x2][y2];
			s2=arrd[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrd[x2][y2];
			s2=arrd[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arre[x2][y2];
			s2=arre[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arre[x2][y2];
			s2=arre[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrf[x2][y2];
			s2=arrf[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrf[x2][y2];
			s2=arrf[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrg[x2][y2];
			s2=arrg[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrg[x2][y2];
			s2=arrg[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrh[x2][y2];
			s2=arrh[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrh[x2][y2];
			s2=arrh[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arri[x2][y2];
			s2=arri[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arri[x2][y2];
			s2=arri[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrj[x2][y2];
			s2=arrj[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrj[x2][y2];
			s2=arrj[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}


		if(x1==1 && y1>1){
			s1=arrk[x2][y2];
			s2=arrk[x2][y1-1];
		//	printf("%lld\n",s1-s2);
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrk[x2][y2];
			s2=arrk[x1-1][y2];
		//	printf("%lld\n",s1-s2);			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrl[x2][y2];
			s2=arrl[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrl[x2][y2];
			s2=arrl[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}		

		if(x1==1 && y1>1){
			s1=arrm[x2][y2];
			s2=arrm[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrm[x2][y2];
			s2=arrm[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrn[x2][y2];
			s2=arrn[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrn[x2][y2];
			s2=arrn[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arro[x2][y2];
			s2=arro[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arro[x2][y2];
			s2=arro[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrp[x2][y2];
			s2=arrp[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrp[x2][y2];
			s2=arrp[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrq[x2][y2];
			s2=arrq[x2][y1-1];

			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrq[x2][y2];
			s2=arrq[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrr[x2][y2];
			s2=arrr[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrr[x2][y2];
			s2=arrr[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrs[x2][y2];
			s2=arrs[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrs[x2][y2];
			s2=arrs[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrt[x2][y2];
			s2=arrt[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrt[x2][y2];
			s2=arrt[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arru[x2][y2];
			s2=arru[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arru[x2][y2];
			s2=arru[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrv[x2][y2];
			s2=arrv[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrv[x2][y2];
			s2=arrv[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrw[x2][y2];
			s2=arrw[x2][y1-1];

			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrw[x2][y2];
			s2=arrw[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrx[x2][y2];
			s2=arrx[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrx[x2][y2];
			s2=arrx[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arry[x2][y2];
			s2=arry[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arry[x2][y2];
			s2=arry[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(x1==1 && y1>1){
			s1=arrz[x2][y2];
			s2=arrz[x2][y1-1];
			
			if(s1-s2>0)
				p++;			
		}	

		if(x1>1 && y1==1){
			s1=arrz[x2][y2];
			s2=arrz[x1-1][y2];
			
			if(s1-s2>0)
				p++;			
		}

		if(p==k)	
			res++;
		//printf("%lld\n",p);

	}
	}
	}
	}
	printf("%lld\n",res);
	return 0;
}	
