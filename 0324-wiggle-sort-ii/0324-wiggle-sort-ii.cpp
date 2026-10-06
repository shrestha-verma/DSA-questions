class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int k = n - 1; 
        // All odd positions have peak values (>)
        for (int i = 1; i < n; i += 2) {
            nums[i] = temp[k];
            k--; 
        }

        //  All even positions have small values (<)
        for (int i = 0; i < n; i += 2) {
            nums[i] = temp[k];
            k--;
        }
    }
};