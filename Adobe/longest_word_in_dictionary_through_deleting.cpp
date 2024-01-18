/*
Simple approach:
check if word in dictionary is a substring of the main string
if yes, check if it is the longest word

to check if it is a substring, use two pointers
*/

class Solution {
  bool isSubstr(string &s, string &str) {
    int n = s.size();
    int m = str.size();

    int a = 0, b = 0;

    while(b < m and a < n) {
      if(s[a] == str[b]) {
        b++;
      }
      a++;
    }

    return b == m;
  }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;

        for(string &str: dictionary) {
          if(isSubstr(s, str)) {
            if((str.size() > ans.size()) or (str.size() == ans.size() and str < ans)) {
              ans = str;
            }
          }
        }
        return ans;
    }
};