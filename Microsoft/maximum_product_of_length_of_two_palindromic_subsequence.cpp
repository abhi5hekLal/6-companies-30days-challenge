class Solution {
    int ans;

    bool isPalindrome(string &str) {
        int start = 0;
        int end = str.size() - 1;

        while(start < end) {
            if(str[start++] != str[end--]) return false;
        }
        return true;
    }

    void solve(string &s, string &s1, string &s2, int idx = 0) {

        /*
        on reaching the last index check if both s1 and s2 are palindrome
        if so find their length and store it in ans
        */
        if(idx == s.size()) {
            if(isPalindrome(s1) and isPalindrome(s2))
                ans = max(ans, (int)s1.size() * (int)s2.size());
            return;
        }

        // add current char to string 1
        s1.push_back(s[idx]);
        solve(s, s1, s2, idx+1);
        s1.pop_back();

        // add current char to string 2
        s2.push_back(s[idx]);
        solve(s, s1, s2, idx+1);
        s2.pop_back();

        // skip the current char
        solve(s, s1, s2, idx+1);

    }

public:
    int maxProduct(string s) {
        ans = 0;
        string s1, s2;
        solve(s, s1, s2);
        return ans;
    }
};