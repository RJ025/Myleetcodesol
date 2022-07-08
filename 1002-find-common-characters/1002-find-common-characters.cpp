class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        
        unordered_map<char , int>mpp1;
        
        for(auto it : words[0])
        {
            mpp1[it]++;
        }
        
        unordered_map<char , int>mpp2;
        
        for(auto it : words)
        {
            mpp2.clear();
            
            for(auto x : it)
            {
                mpp2[x]++;
            }
            
            for(auto & x:mpp1){
            x.second=min(x.second,mpp2[x.first]);
        }
        }
        
        string s;
        
        for(auto x:mpp1)
        {
            while(x.second!=0)
            {
                s=x.first;
                ans.push_back(s);
                x.second--;
            }
        }
        
        return ans;
        
    }
};