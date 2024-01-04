// brute force O(n^3)
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int cnt = 0;
                vector<int> temp;

                for(int l = i; l <= j; l++) {
                    temp.push_back(nums[l]);
                    if(nums[l] % p == 0) cnt++;
                }

                if(cnt <= k) st.insert(temp);
            }
        }

        return st.size();
    }
};

// optimized O(n^2) by calculating as we iterate over each element no need for third for loop
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            vector<int> temp;
            for(int j = i; j < n; j++) {
                
                if(nums[j] % p == 0) {
                    cnt++;
                }

                if(cnt > k) break;

                temp.push_back(nums[j]);
                st.insert(temp);
            }
        }

        return st.size();
    }
};