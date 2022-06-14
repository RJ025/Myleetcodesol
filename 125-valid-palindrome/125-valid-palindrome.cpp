class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i=0;i<n;i++)if(s[i]>=65 and s[i]<=90)s[i] += 32;//convert upper to lower case
        string r = "";
        for(int i=n-1;i>=0;i--){
            if((s[i]>=97 and s[i]<=122)or(s[i]>=48 and s[i]<=57))
                r += s[i];// add char to string, which are small letters or digits, only in reverse order  
        }
        string o="";
        for(int i=0;i<n;i++){
            if((s[i]>=97 and s[i]<=122)or(s[i]>=48 and s[i]<=57))
				 o += s[i];// add char to string, which are small letters or digits, only in forward order     
        }
        return (o==r); // check if reverse is equal to forward string and return
    }
};