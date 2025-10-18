class Solution {
public:
    bool isvalid(vector<vector<int>>&grid,int i,int j,int k,vector<vector<vector<bool>>>&state){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==-1||k-grid[i][j]<0||state[i][j][k])return false;
        state[i][j][k]=true;
        return true;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<vector<bool>>>state(grid.size(),vector<vector<bool>>(grid[0].size(),vector<bool>(k+1,false)));
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{0,0},{k-grid[0][0],0}});
        int i,j,step,obs,x;
        while(!q.empty()){
            i=q.front().first.first;
            j=q.front().first.second;
            step=q.front().second.second;
            obs=q.front().second.first;
            if(i==grid.size()-1&&j==grid[0].size()-1)return step;
            if(isvalid(grid,i-1,j,obs,state) && (obs-x)>-1)q.push({{i-1,j},{obs-grid[i-1][j],step+1}});
            if(isvalid(grid,i+1,j,obs,state) && (obs-x)>-1)q.push({{i+1,j},{obs-grid[i+1][j],step+1}});
            if(isvalid(grid,i,j-1,obs,state) && (obs-x)>-1)q.push({{i,j-1},{obs-grid[i][j-1],step+1}});
            if(isvalid(grid,i,j+1,obs,state) && (obs-x)>-1)q.push({{i,j+1},{obs-grid[i][j+1],step+1}});
            q.pop();
        }
        return -1;
    }
};