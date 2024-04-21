class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dp(10,0);
        
        for(int j=0;j<m;j++){
            vector<int> dt(10,0);
            for(int i=0;i<n;i++){
                dt[grid[i][j]]--;
            }
            for(auto &nx : dt){nx+=n;}
            vector<int> ndp(10,2e9);
            
            for(int u=0;u<10;u++){
                for(int v=0;v<10;v++){
                    if(u==v){continue;}
                    ndp[v]=min(ndp[v],dp[u]+dt[v]);
                }
            }
            dp=ndp;
        }
        return (*min_element(dp.begin(),dp.end()));
    }
};