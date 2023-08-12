/*
    Since the robot can only go right or down,
    the total numbers for paths to reach a grip
    would be the sum of its top and left grip.
    If the current grip is an obstacle, then there
    will be no paths can access this grip, therefore
    zero. By repeating this process, we will get the
    final answer at the destination. 
*/ 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int paths[n][m];
        paths[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) {
                    paths[i][j] = 0;
                } else {
                    int total = 0;
                    if (i - 1 >= 0) {
                        total += paths[i - 1][j];
                    }
                    if (j - 1 >= 0) {
                        total += paths[i][j - 1];
                    }
                    paths[i][j] = total;
                }
            }
        }
        return paths[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};