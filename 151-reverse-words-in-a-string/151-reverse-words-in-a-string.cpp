class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0)return s;
        
        stack<string>st;
        
        for(int i=0 ; i<s.length() ; i++)
        {
            string temp = "";
            while(i<s.length() and s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            if(temp.length()!=0)
            st.push(temp);
        }
        
        string ans = "";
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            if(!st.empty())
            {
                ans+=" ";
            }
            
        }
        
        return ans;
        
    }
};