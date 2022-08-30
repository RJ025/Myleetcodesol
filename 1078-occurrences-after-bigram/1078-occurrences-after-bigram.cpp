class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string>ans;
        vector<string>temp;
        string s = "";
        for(int i=0 ; i<text.length() ; i++)
        {
            if(text[i]!=' ')
            {
                s+=text[i];
            }
            else
            {
                temp.push_back(s);
                s="";
            }
        }
        temp.push_back(s);
        
        // for(int i=0 ; i<temp.size() ; i++)cout<<temp[i]<<" ";
        
        for(int i=0 ; i<temp.size() ; i++)
        { 
           if(i+2 < temp.size())
           {
               if(temp[i]==first and temp[i+1]==second)
               {
                   ans.push_back(temp[i+2]);
               }
           }
        }
        
        return ans;
    }
};