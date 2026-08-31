class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int actualsum=0;
        int expected_sum=n*(n+1)/2;
        for(int i=0;i<n;i++){
            actualsum+=nums[i];
        }
        return expected_sum-actualsum;
    }
};