class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int streak = 0;

        for (int i : st) {
            //checking whetehr the current number i part of any streak
            if (st.find(i - 1) == st.end()) {
                int curr = i;
                int currstreak = 1;

                //if the next consecutiven umber is part of strak. 
                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    currstreak++;
                }

                // Global maximum streak update
                streak = max(streak, currstreak);
            }
        }

        return streak;
    }
};