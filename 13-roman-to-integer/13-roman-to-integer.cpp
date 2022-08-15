class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        if(n==0)return 0;
        
        unordered_map<char , int>mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        int ans =0;
        // int i=0;
        
//         while(i<n)
//         {
//             if(s[i]=='I' and s[i+1]=='V'){
//                 ans=ans+(mpp['V']-mpp['I']);
//                 i+=2;
//             }
//             else if(s[i]=='I' and s[i+1]=='X'){
//                 ans=ans+(mpp['X']-mpp['I']);
//                 i+=2;
//             }
//             else if(s[i]=='X' and s[i+1]=='L'){
//                 ans=ans+(mpp['L']-mpp['X']);
//                 i+=2;
//             }
//             else if(s[i]=='X' and s[i+1]=='C'){
//                 ans=ans+(mpp['C']-mpp['X']);
//                 i+=2;
//             }
//             else if(s[i]=='C' and s[i+1]=='D'){
//                 ans=ans+(mpp['D']-mpp['C']);
//                 i+=2;
//             }
//             else if(s[i]=='C' and s[i+1]=='M'){
//                 ans=ans+(mpp['M']-mpp['C']);
//                 i+=2;
//             }
//             else{
//                 ans+=mpp[s[i]];
//                 i++;
//             }      

//         }
        
        for(int i=0 ; i<n ; i++)
        {
            if(mpp[s[i]] < mpp[s[i+1]])
                ans-=mpp[s[i]];
            else
                ans+=mpp[s[i]];
        }
        
        // cout<<ans;
        return ans;

    }
};