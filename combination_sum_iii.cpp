class Solution {
    void solve(int k, int n, int cur, vector<int> &temp, vector<vector<int>> &ans) {
        if(k == 0 and n == 0) {
            ans.push_back(temp);
            return;
        }
        if(k == 0) {
            return;
        }

        for(int i = cur; i <= 9; i++) {
            temp.push_back(i);
            solve(k-1, n - i, i + 1, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(k, n, 1, temp, ans);
        return ans;
    }
};