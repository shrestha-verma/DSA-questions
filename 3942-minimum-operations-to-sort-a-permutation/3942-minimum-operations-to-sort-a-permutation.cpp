class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

      
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }

       
        bool isInc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(idx + i) % n] != i) {
                isInc = false;
                break;
            }
        }

        if (isInc) {
           
            return min(idx, n - idx + 2);
        }

        
        bool isDec = true;
        for (int i = 0; i < n; i++) {
            if (nums[(idx - i + n) % n] != i) {
                isDec = false;
                break;
            }
        }

        if (isDec) {
            
            return min(n - idx, idx + 2);
        }

       
        return -1;
    }
};