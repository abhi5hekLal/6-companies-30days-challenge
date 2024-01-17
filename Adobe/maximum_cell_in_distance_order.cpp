class Solution {
  
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c) {
        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++) {
          for(int j = 0; j < cols; j++) {
            ans.push_back({i, j});
          }
        }
        // custom comparator to sort on the basis of distance as given in question
        // also to keep in mind distance between two cell can be found by |r1 - r2| + |c1 - c2|
        // can also be solved using dfs but then extra space req to create a grid
        sort(ans.begin(), ans.end(), [&](auto &a, auto &b) {
          return abs(a[0] - r) + abs(a[1] - c) < abs(b[0] - r) + abs(b[1] - c);
        });
        return ans;
    }
};