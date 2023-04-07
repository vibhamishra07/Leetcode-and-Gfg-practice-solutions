class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int total=0, count=0;
        for(int i=1; i<grid.size(); i++){
            for(int j=1; j<grid[i].size(); j++){
                count=0;
                if(grid[i][j]==1 && isClosedLand(grid , i, j, count)) total+=count;
            }
        }
        return total;
    }
    
    bool isClosedLand(vector<vector<int>>& grid, int i,int j,int& count){
        if(i<0 || j<0 || i >= grid.size() || j >= grid[i].size()) return 0;
        
        if(grid[i][j]==0 || grid[i][j]==-1) return 1;
        
        grid[i][j] = -1;
        count++;
        bool isLeftClosed = isClosedLand(grid, i, j - 1, count);
        bool isRightClosed = isClosedLand(grid, i, j + 1, count);
        bool isTopClosed = isClosedLand(grid, i + 1, j, count);
        bool isBottomClosed = isClosedLand(grid, i - 1, j, count);
        return isLeftClosed && isRightClosed && isTopClosed && isBottomClosed;
    }
};