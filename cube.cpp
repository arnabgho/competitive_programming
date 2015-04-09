#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int M,N;
int lps[200001];
void computeLPSArray(int *pat, int *lps);

int KMPSearch(int *pat, int *txt)
{
    //int M = strlen(pat);
    //int N = strlen(txt);
	int ans=0;
    // create lps[] that will hold the longest prefix suffix values for pattern
    //int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, lps);

    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
       // printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
        ans++;
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
    //free(lps); // to avoid memory leak
    return ans;
}

void computeLPSArray(int *pat, int *lps)
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



int eleph[200001];
int bear[200001];
int main(){
	int n,w,i,diffb,diffe,t,ans,j;
	cin>>n>>w;
	for(i=1;i<=n;i++){
		cin>>bear[i];
		if(i>=2)
			bear[i-2]=bear[i]-bear[i-1];
		//cout<<bear[i]<<endl;
	}
	bear[n-1]=bear[n]-bear[n-1];
	for(i=1;i<=w;i++){
		cin>>eleph[i];
		if(i>=2)
			eleph[i-2]=eleph[i]-eleph[i-1];
		//cout<<eleph[i]<<endl;
	}
	eleph[n-1]=eleph[n]-eleph[n-1];
	M=w-1;
	N=n-1;
	

	ans=KMPSearch(eleph,bear);

	cout<<ans<<endl;
	return 0;
}