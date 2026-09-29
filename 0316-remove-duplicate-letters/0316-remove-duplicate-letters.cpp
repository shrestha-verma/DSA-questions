class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0); 
        vector<bool> seen(26, false); 
        string st = "";             

      
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            
            if (seen[ch - 'a']) {
                continue;
            }

            
            while (!st.empty() && st.back() > ch && lastIndex[st.back() - 'a'] > i) {
                seen[st.back() - 'a'] = false; 
                st.pop_back();                
            }

           
            st.push_back(ch);
            seen[ch - 'a'] = true;
        }

        return st;
    }
};