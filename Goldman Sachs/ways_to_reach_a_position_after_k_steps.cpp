/*
Memoization
Problem can be thought of as taking two paths at each point either going forward or backward
At the end when steps become 0 check if we have reached the target or not
*/  
const int MOD = 1e9 + 7;
int dp[4001][1001];
class Solution {
    int solve(int start, int end, int k) {
        if(k == 0 and start == end) {
            return 1;
        }
        else if(k == 0) {
            return 0;
        }

        if(dp[start + 1000][k] != -1) return dp[start + 1000][k];

        dp[start + 1000][k] = ((solve(start + 1, end, k - 1) % MOD) + (solve(start - 1, end, k - 1) % MOD)) % MOD;

        return dp[start + 1000][k];
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(startPos, endPos, k);
    }
};