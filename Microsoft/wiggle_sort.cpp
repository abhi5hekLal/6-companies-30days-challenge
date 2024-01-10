class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 1; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        }

        for(int i = 0; i < n; i += 2) {
            nums[i] = pq.top();
            pq.pop();
        }
    }
};