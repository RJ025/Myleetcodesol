class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length()==0)return s;
        stack<char>st;
        string ans = "";
        
        st.push(s[0]);
        int i;
            for(i=1 ; i<s.length() ; i++)
            {
                if(!st.empty() and s[i]==st.top())
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            while(!st.empty())
            {
                ans+=st.top();
                st.pop();
            }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};