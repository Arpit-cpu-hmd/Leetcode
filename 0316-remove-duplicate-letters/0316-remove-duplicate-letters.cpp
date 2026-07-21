class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> inResult(26, false); 
        for (char ch : s) {
            count[ch - 'a']++;
        }

        string result = ""; 

        for (char ch : s) {
            int idx = ch - 'a';

            count[idx]--;

            if (inResult[idx]) {
                continue;
            }
            while (!result.empty() && result.back() > ch && count[result.back() - 'a'] > 0) {
                inResult[result.back() - 'a'] = false; 
                result.pop_back();                    
            }

            result.push_back(ch);
            inResult[idx] = true;
        }

        return result;
    }
};