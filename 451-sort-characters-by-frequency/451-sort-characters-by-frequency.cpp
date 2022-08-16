class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int , char>>q;
        unordered_map<char , int>mpp;
        
        for(int i=0 ; i<s.length() ; i++)
        {
           mpp[s[i]]++;
        }
        
        
        for(auto p: mpp)
        {
            q.push({p.second , p.first});
        }
        string ans = "";
        while(!q.empty())
        {
            int n = q.top().first;
            while(n--)
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
            
    }
};