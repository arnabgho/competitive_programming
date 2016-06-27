#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int DP_horiz[1001][1001];
int DP_vert[1001][1001];
int DP_rect_horiz[1001][1001];
int DP_rect_vert[1001][1001];
class Solution {
public:
    
    int maximalRectangle(vector< string > &matrix,int n,int m) {
        int i,j;
        //m=matrix[0].size();
        //n=matrix.size();
        cout<<"HI n: "<<n<<" m: "<<m<<endl;
        if(m==0 && n==0)
            return 0;
        int maxim=0;
        maxim=DP_rect_horiz[0][0]=DP_rect_vert[0][0]=matrix[0][0]-'0';
        for(i=1;i<n;i++){
            if(matrix[i][0]=='1'){
                DP_rect_vert[i][0]=DP_rect_vert[i-1][0]+1;
                DP_horiz[i][0]=1;
                DP_rect_horiz[i][0]=1;
                DP_vert[i][0]=DP_rect_vert[i][0];
                maxim=max(maxim,DP_rect_horiz[i][0]*DP_rect_vert[i][0]);
            }
        }
        for(i=1;i<m;i++){
            if(matrix[0][i]=='1'){
                DP_rect_horiz[0][i]=DP_rect_horiz[0][i-1]+1;
                DP_vert[0][i]=1;
                DP_horiz[0][i]=DP_rect_horiz[0][i];
                DP_rect_vert[0][i]=1;
                maxim=max(maxim,DP_rect_horiz[0][i]*DP_rect_vert[0][i]);
            }
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    DP_vert[i][j]=DP_vert[i-1][j]+1;
                    DP_horiz[i][j]=DP_horiz[i][j-1]+1;
                    if(DP_rect_horiz[i-1][j]>0)
                      DP_rect_horiz[i][j]=min(1+DP_rect_horiz[i][j-1],DP_rect_horiz[i-1][j]);
                    else
                        DP_rect_horiz[i][j]=1+DP_rect_horiz[i][j-1];
                    if(DP_rect_vert[i][j-1]>0)
                        DP_rect_vert[i][j]=min(1+DP_rect_vert[i-1][j],DP_rect_vert[i][j-1]);
                    else
                        DP_rect_vert[i][j]=1+DP_rect_vert[i-1][j];

                    if(DP_horiz[i][j]>DP_vert[i][j]){
                        if(DP_horiz[i][j]>DP_rect_vert[i][j]*DP_rect_horiz[i][j]){
                            DP_rect_vert[i][j]=1;
                            DP_rect_horiz[i][j]=DP_horiz[i][j];
                        }
                    }
                    else{
                        if(DP_vert[i][j]>DP_rect_vert[i][j]*DP_rect_horiz[i][j]){
                            DP_rect_horiz[i][j]=1;
                            DP_rect_vert[i][j]=DP_vert[i][j];
                        }
                    }
                    maxim=max(maxim,DP_rect_horiz[i][j]*DP_rect_vert[i][j]);
                }
            }
        }
        return maxim;
    }
};
int main(){
    int i,j;
    std::vector< string > matrix(10);
    /*
    matrix[0].push_back('0');
    matrix[0].push_back('0');
    matrix[0].push_back('0');
    matrix[1].push_back('0');
    matrix[1].push_back('0');
    matrix[1].push_back('0');
    matrix[2].push_back('1');
    matrix[2].push_back('1');
    matrix[2].push_back('1');
    */
    matrix[0]="000011101";
    matrix[1]="001111101";
    matrix[2]="000111110";
    //matrix[3]="11110";
    //matrix[4]="11111";
    //matrix[5]="00000";
    Solution *s;
    s=(Solution *)malloc(sizeof(Solution));
    int res=s->maximalRectangle(matrix,6,5);
    cout<<res<<endl;
    cout<<"DP_horiz:\n";
    for(i=0;i<3;i++){
        for(j=0;j<9;j++)
            cout<<DP_rect_horiz[i][j]<<" ";
        cout<<endl;
    }

    cout<<"DP_vert:\n";
    for(i=0;i<3;i++){
        for(j=0;j<9;j++)
            cout<<DP_rect_vert[i][j]<<" ";
        cout<<endl;
    }

    
    return 0;
}