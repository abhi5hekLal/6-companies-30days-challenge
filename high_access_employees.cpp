/*
convert time to seconds and compare neighbouring elements after sorting
since change is day is not accounted for so no need to worry about subtraction between times 
like 23:45 and 0015 
*/

class Solution {
    int timeInSeconds(string time) {
        return stoi(time.substr(0,2)) * 60 + stoi(time.substr(2,2));
    }

    bool isValid(vector<int> &accessTime) {
        int n = accessTime.size();

        if(n < 3) return false;

        for(int i = 0; i < n - 2; i++) {
            if(accessTime[i + 2] - accessTime[i] < 60) return true;
        }
        return false;
    }

public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& accessTimes) {
        vector<string> ans;
        unordered_map<string, vector<int>> mp;

        for(auto accessTime: accessTimes) {
            mp[accessTime[0]].push_back(timeInSeconds(accessTime[1]));
        }

        for(auto it: mp) {
            string emp = it.first;
            auto accessTime = it.second;

            sort(accessTime.begin(), accessTime.end());

            if(isValid(accessTime)) ans.push_back(emp);
        }

        return ans;
    }
};
