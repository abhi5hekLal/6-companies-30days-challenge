class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 1e9));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(mat[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int delX[] = {1, -1, 0, 0};
            int delY[] = {0, 0, -1, 1};

            int newX, newY;
            for(int i = 0; i < 4; i++) {
                newX = x + delX[i];
                newY = y + delY[i];

                if(newX < r and newY < c and newX >= 0 and newY >= 0 and ans[newX][newY] > 1 + ans[x][y]) {
                    ans[newX][newY] = ans[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return ans;
    }
};