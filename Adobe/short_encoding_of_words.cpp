class Solution {
  static bool comp(string &a, string &b) {
    return a.size() > b.size();
  }
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);

        string ans;

        ans += words[0] + "#";
        int n = words.size();

        for(int i = 1; i < n; i++) {
          string cur = words[i] + "#";
          int pos = ans.find(cur);

          if(pos != -1) continue;
          else ans += cur;
        }
        return ans.size();
    }
};