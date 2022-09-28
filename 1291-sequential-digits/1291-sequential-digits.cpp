class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        
        vector<int>res;
        
        int lenmin = to_string(low).length();
        int lenmax = to_string(high).length();
        
        for(int i=lenmin ; i<=lenmax ; i++)
        {
            for(int j=0 ; j<10-i ; j++)
            {
                int ans = stoi(digits.substr(j , i));
                if(ans>=low and ans<=high)
                    res.push_back(ans);
            }
        }
        
        return res;
    }
};