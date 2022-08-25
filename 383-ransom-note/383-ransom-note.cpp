class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
            
        unordered_map<char , int>mpp;
        
        for(auto ele : magazine)
        {
            mpp[ele]++;
        }
        
        int n = ransomNote.length();
        
        for(auto ele : ransomNote)
        {
            if(mpp[ele]==0)return false;
            else
            {
                mpp[ele]--;
                n--;
            }
               
        }
        return true;
        
    }
    
};