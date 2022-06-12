class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int len = password.length();
        
        if(len<8)return false;
        
        for(int i=1 ; i<len ; i++)
        {
            if(password[i] == password[i-1])return false;
        }
        
        int c1=0 , c2=0 , c3=0 , c4=0;
        
        for(int i=0 ; i<len ; i++)
        {
            if(password[i]>=48 and password[i]<=57)
            {
                c1++;
            }
            else if(password[i]>=65 and password[i]<=90)
            {
                c2++;
            }
            else if(password[i] >= 97 and password[i] <= 122)
            {
                c3++;
            }
            else if(password[i]=='!' || password[i]=='@'||password[i]=='#'||password[i]=='$'||password[i]=='%'||password[i]=='^'||password[i]=='&'||password[i]=='*'||password[i]=='('||password[i]==')'||password[i]=='-'||password[i]=='+')
            {
                c4++;
            }
            
            
        }
        
        if(c1>0 and c2>0 and c3>0 and c4>0)return true;
                
            return false;
        
    }
};