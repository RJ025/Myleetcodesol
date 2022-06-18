class Solution {
public:
    bool checkpalindrome(string s , int i , int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if(s.length()==0)return true;
        
       int i=0 , j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return checkpalindrome(s , i , j-1)||checkpalindrome(s , i+1 , j);
            }
            i++;
            j--;
        }
        
        return true;
    }
};