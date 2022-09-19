class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string , vector<string>>mpp;
        vector<vector<string>>ans;
        
        for(auto path : paths)
        {
            string dir;
            int i;
            for(i=0 ; i<path.size() and path[i]!=' ' ; i++)
            {
                dir+=path[i];
            }
            dir+='/';
            i++;
            
            while(i<path.size())
            {
                string file , data;
                
                while(i<path.size() and path[i] != '(')
                {
                    file+=path[i++];
                }
                while(i<path.size() and path[i]!=' ')
                {
                    data+=path[i++];
                }
                
                mpp[data].push_back(dir+file);
                i++;
            }
        }
        
        for(auto p : mpp)
        {
            if(p.second.size()>1)
                ans.push_back(p.second);
        }
        
        return ans;
        
    }
};