// brute force :- simulation 

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q: queries) {
            priority_queue<pair<string,int>, vector<pair<string,int>>, greater<pair<string, int>>> pq;
            for(int i = 0; i < nums.size(); i++) {
                int n = nums[i].size();
                pq.push({nums[i].substr(n - q[1], q[1]), i});
            }

            for(int i = 1; i < q[0]; i++) {
                pq.pop();
            }
            ans.push_back(pq.top().second);
        }

        return ans;
    }
};