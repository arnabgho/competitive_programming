class Solution {
public:
    vector<vector<int>> DP;
    int n,m;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    bool isValid(int i,int j){
        return 0<=i && i<n && 0<=j && j<m;
    }
    
    int dfs(int u,int v,vector<vector<int>>& matrix){
        if(DP[u][v]!=-1)
            return DP[u][v];
        int val=1;
        for(int i=0;i<4;i++){
            if(isValid(u+dx[i],v+dy[i])){
                if(matrix[u+dx[i]][v+dy[i]]>matrix[u][v]){
                    val=max(val,1+dfs(u+dx[i],v+dy[i],matrix));
                }
            }
        }
        return DP[u][v]=val;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        DP=matrix;
        n=matrix.size();
        m=matrix[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                DP[i][j]=-1;
        int ans=0;        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(i,j,matrix));
            }
        }        
        return ans;
    }
};