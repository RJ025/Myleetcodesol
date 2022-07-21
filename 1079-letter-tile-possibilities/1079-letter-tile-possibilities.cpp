class Solution {
public:
    // int ans=0;
    int code(vector<int>&freq)
    {
        int ans=0;
        for(int i=0 ; i<26 ; i++)
        {
            if(freq[i]>0)
            {
                freq[i]--;
               ans+=code(freq)+1;
                freq[i]++;
            }
        }
        
        return ans;
    }
    
    int numTilePossibilities(string tiles) {
        if(tiles.size()==0)return 0;
        
        vector<int>freq(26 , 0);
        
        for(int i=0 ; i<tiles.length() ; i++)
        {
            char ch = tiles[i];
            int idx = ch-'A';
             freq[idx]++;
        }
        // int ans=0;
        
        return code(freq);
        
        // return ans;
    }
};