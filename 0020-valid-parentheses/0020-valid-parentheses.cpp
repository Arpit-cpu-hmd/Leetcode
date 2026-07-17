class Solution {
public:
    bool isValid(string s) {
        stack<char>str;

        for(int i=0; i< s.size(); i++){
            char ch= s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                str.push(ch);
            }else{
                if(str.empty()){
                    return false;
                }

                int top= str.top();
                if((top== '(' && ch== ')') ||
                    (top== '[' && ch== ']') ||
                    (top== '{' && ch== '}')){
                        str.pop();
                    }else{
                        return false;
                    }
            }
        }

        return str.empty();
    }
};