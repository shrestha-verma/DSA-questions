class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int max_sum=INT_MIN;
      int cursum=0;
      for(int i=0;i<nums.size();i++){
        cursum+=nums[i];
        max_sum=max(max_sum,cursum);
        if(cursum<0){
            cursum=0;
        }
      }  
      return max_sum;
    }
};