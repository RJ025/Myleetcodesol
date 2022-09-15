class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        if(changed.size()==1)return ans;
        unordered_map<int , int>mpp;
        sort(changed.begin() , changed.end());
        
        for(int i=0 ; i<changed.size() ; i++)
            mpp[changed[i]]++;
        
        for(auto x : changed)
        {
            if(mpp.find(x*2)!=mpp.end() and mpp[x]!=0 and mpp[x*2]!=0)
            {
                mpp[x]--;
                mpp[x*2]--;
                ans.push_back(x);
            }
        }
        
        for(auto p : mpp)
        {
            if(p.second != 0)
                ans.clear();
        }
        
        return ans;
    }
};