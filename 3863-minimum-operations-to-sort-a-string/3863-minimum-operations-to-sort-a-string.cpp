class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

       
        if (n <= 2) {
            return -1;
        }

        char min_ch = *min_element(s.begin(), s.end());
        char max_ch = *max_element(s.begin(), s.end());

        
        if (s[0] == min_ch || s[n - 1] == max_ch) {
            return 1;
        }

        
        bool min_only_at_end = (s[n - 1] == min_ch);
        if (min_only_at_end) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == min_ch) {
                    min_only_at_end = false;
                    break;
                }
            }
        }

        bool max_only_at_start = (s[0] == max_ch);
        if (max_only_at_start) {
            for (int i = 1; i < n; i++) {
                if (s[i] == max_ch) {
                    max_only_at_start = false;
                    break;
                }
            }
        }

        if (min_only_at_end && max_only_at_start) {
            return 3;
        }

        
        return 2;
    }
};