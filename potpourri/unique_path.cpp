#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int DP[111][111];
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m,n,i,j;
        n=obstacleGrid.size();
        if(n>0)
            m=obstacleGrid[0].size();
            
        cout<<"n "<<n<<" m "<<m<<endl;    
        if(obstacleGrid[0][0]==1 )
            return 0;
        DP[0][0]=1;
        for(i=1;i<n;i++){
            if(!obstacleGrid[i][0])
                DP[i][0]=DP[i-1][0];
        }
        for(i=1;i<m;i++){
            if(!obstacleGrid[0][i])
                DP[0][i]=DP[0][i-1];
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(!obstacleGrid[i][j]){
                    DP[i][j]=DP[i-1][j]+DP[i][j-1];
                }
            }
        }
        return DP[n-1][m-1];
    }
};

int main(){
    vector<vector<int> > grid(1);
    grid[0].push_back(0);grid[0].push_back(1);//grid[1].push_back(1);grid[1].push_back(0);        
    Solution* sol;
    sol=(Solution*)malloc(sizeof(Solution));
    cout<<sol->uniquePathsWithObstacles(grid);
    return 0;
}