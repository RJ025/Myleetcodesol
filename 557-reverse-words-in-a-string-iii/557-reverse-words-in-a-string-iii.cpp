class Solution {
public:
    string reverseWords(string s) {
        
        for(int start=0 ,  end =0 ; end<=s.size() ; end++)
        {
            if(s[end]==' ' or s[end] == '\0')
            {
                reverse(start+s.begin() , end+s.begin());
                start = end+1;
            }
        }
        
        return s;
    }
};