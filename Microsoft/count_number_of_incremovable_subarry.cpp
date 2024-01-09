// brute force check for all subarray
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                bool flag = true;
                int prev = -1;
                for(int k = 0; k < n; k++) {
                    // skip elements in the range i to j i.e. they 
                    // are in the removed subarray
                    if(k >= i and k <= j) continue;
                    if(prev >= nums[k]) {
                        flag = false;
                        break;
                    }
                    prev = nums[k];
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};