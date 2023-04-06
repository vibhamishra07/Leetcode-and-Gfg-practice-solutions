class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int ans=0;
        
        for(int i=1; i<grid.size(); i++){
            for(int j=1; j<grid[i].size(); j++){
                if(grid[i][j]==0 && isClosed(grid , i, j)) ++ans;
            }
        }
        return ans;
        
    }
    
    bool isClosed(vector<vector<int>>& grid, int i, int j){
        
        if(i<0 || j<0 || i >= grid.size() || j >= grid[i].size()) return 0;
        
        if(grid[i][j]==1 || grid[i][j]==-1) return 1;
        
        grid[i][j] = -1;
        bool isLeftClosed = isClosed(grid, i, j - 1);
        bool isRightClosed = isClosed(grid, i, j + 1);
        bool isTopClosed = isClosed(grid, i + 1, j);
        bool isBottomClosed = isClosed(grid, i - 1, j);
        return isLeftClosed && isRightClosed && isTopClosed && isBottomClosed;
    }
};