class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            cout<<"not valid anagram\n";
            return false;
        }
        int count[26] = {0};
        for(int i=0; i<s.length(); i++){
            int idx = s[i] - 'a';
            count[idx]++; 
        }
        for(int i = 0; i<t.length(); i++){
            int idx = t[i] - 'a';
            if(count[idx] == 0){
                cout<<"not valid anagram\n";
                return false;
            }
            count[idx]--;
        }
        cout<<"Valid anagram\n";
        return true;
    }
};