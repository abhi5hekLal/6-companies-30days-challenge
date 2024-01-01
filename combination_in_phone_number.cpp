class Solution {
    void solve(const string &digits, string &temp, vector<string> &ans, int idx, vector<string> &mp) {
        if(idx == digits.size()) {
            if(temp.size() == 0) return; // to avoid empty string from being pushed
            ans.push_back(temp);
            return;
        }

        for(char ch: mp[digits[idx] - '0']) {
            temp.push_back(ch);
            solve(digits, temp, ans, idx + 1, mp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string temp;
        vector<string> ans;
        solve(digits, temp, ans, 0, mp);
        return ans;
        
    }
};