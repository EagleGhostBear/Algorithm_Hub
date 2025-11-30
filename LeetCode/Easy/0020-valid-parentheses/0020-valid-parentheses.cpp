class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c == ')'){
                if(st.size() && st.top() == '(') st.pop();
                else return false;
            }
            else if(c == ']'){
                if(st.size() && st.top() == '[') st.pop();
                else return false;
            }
            else if(c == '}'){
                if(st.size() && st.top() == '{') st.pop();
                else return false;
            }
            else st.push(c);
        }
        if(st.size()) return false;
        return true;
    }
};