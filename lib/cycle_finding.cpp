
enum states{VISITED,EXPLORING,NOT_VISITED};

class Solution {
public:
    vector<states> status;
    bool is_cycle;
    void dfs(vector<vector<int> >&G,int cur){
        if(status[cur]==VISITED) return ;
        if(status[cur]==EXPLORING){
            is_cycle=true;
            return ;
        }
        status[cur]=EXPLORING;
        
        for(auto next:G[cur]){
            dfs(G,next);
        }
        status[cur]=VISITED;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > G(numCourses);
        is_cycle=false;
        for(int i=0;i<numCourses;i++){
            status.push_back(NOT_VISITED);
        }
        for(auto p:prerequisites){
            int v=p.first;
            int u=p.second;
            G[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
            dfs(G,i);
        return !is_cycle;    
    }
};