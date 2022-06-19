class Solution {
public:
    string greatestLetter(string s) {
        if(s.length()==0)return s;
        
        sort(s.begin() , s.end());
        // reverse(s.begin() , s.end());
        string ans="";
        for(int i=0 ; i<s.length() ; i++)
        {
            if(s[i]>='A' and s[i]<='Z')
            {
                for(int j=i+1 ; j<s.length() ; j++)
                {
                    if(s[j] == (s[i]-'A'+'a'))ans+=s[i];
                }
            }
        }
        if(ans.length()==0)return ans;
        string p(1 , ans[ans.length()-1]);
        return p;
    }
};