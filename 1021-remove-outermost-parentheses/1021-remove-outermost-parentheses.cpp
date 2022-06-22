class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        
        string ans = "";
        
        for(int i = 0; i < s.size(); i++){
             if(s[i] == '('){
                 if(st.empty()){
                     st.push(s[i]);
                 }else{
                     st.push(s[i]);
                     ans.push_back(s[i]);
                 }
             }else{
                    st.pop();
                    if(!st.empty()){
                         ans.push_back(s[i]);  
                }
             }
        }
        
        return ans;
    }
};