#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps);

int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
	int res,count,pos,start,end,x,y,prev;
    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    count=0;res=0;
    x=0;y=0;prev=-1;
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
      //  printf("Found pattern at index %d \n", i-j);
      	pos=i-j;
      	start=N-pos-3;
      	end=pos-count;
      	
      	if(prev==-1 ){
      		if(pos==0){
      			x=0;      			
      		}
      		else {
      			x=pos;
      		}
      	}
      	else{
      		y=pos-prev-1;
      		res+=x*y;
      		x=y;
      	}
      	prev=pos;
      	res=res+start+end;
      	count++;
        j = lps[j-1];
      }

      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    y=N-prev+1;
    res=res+x*y;
    cout<<res<<endl;
    return count;
    free(lps); // to avoid memory leak
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

char text[10000];
// Driver program to test above function
int main()
{
	int i,j,len,res,k;
	char * temp;
   //char *txt = "ABABDABACDABABCABAB";
   cin>>text;
   len=strlen(text);
   char *pat = "bear";
   KMPSearch(pat, text);
  
   return 0;
}
