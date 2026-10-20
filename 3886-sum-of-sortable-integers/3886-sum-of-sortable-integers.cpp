class Solution {
    // checks if a subarray can be sorted via rotation
    bool canBeSortedByRotation(const vector<int>& nums, int start, int k) {
        if (k <= 1) return true;
        
        int drops = 0;
        for (int i = 0; i < k; i++) {
            int curr = nums[start + i];
            int next = nums[start + (i + 1) % k];
            if (curr > next) {
                drops++;
            }
        }
        return drops <= 1; 
    }

    bool isValid(const vector<int>& nums, const vector<int>& sorted_nums, int n, int k) {
        int m = n / k;
        
        for (int b = 0; b < m; b++) {
            int start = b * k;
            
            
            if (!canBeSortedByRotation(nums, start, k)) {
                return false;
            }
            
           
            vector<int> chunk(nums.begin() + start, nums.begin() + start + k);
            sort(chunk.begin(), chunk.end());
            
            for (int i = 0; i < k; i++) {
                if (chunk[i] != sorted_nums[start + i]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int ans = 0;

        
        for (int k = 1; k <= n; k++) {
            if (n % k == 0) { 
                if (isValid(nums, sorted_nums, n, k)) {
                    ans += k;
                }
            }
        }

        return ans;
    }
};