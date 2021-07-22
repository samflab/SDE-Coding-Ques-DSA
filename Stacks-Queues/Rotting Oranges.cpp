/* You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. */
//CODE
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int days = 0, tot = 0, cnt = 0; //no. of days, total oranges, rotten oranges by us
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++; //counting the no. of oranges
                if(grid[i][j] == 2) rotten.push({i, j});    //counting the no. of rotten oranges and push the co-ordinates into queue
            }
        }
        
        //for checking the 4 directions: (0, 1), (0, -1), (1, 0), (-1, 0)
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();  //size of rotten queue
            cnt += k;               //increase in count of rotten oranges
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;    // (x,y) of the first rotten orange
                rotten.pop();   // pop it
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];     //finds the new coordinates
                    //checks the boundary and checks if already rotten or not
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) 
                        continue;   
                    grid[nx][ny] = 2;   //set it as rotten
                    rotten.push({nx, ny});  //push the same to the rotten queue
                }   
            }
            if(!rotten.empty()) days++;     //if the rotten queue contains something, increase the no. of days
        }
        
        return tot == cnt ? days : -1;  //if all the oranges have been covered then return days else -1
    }
};
