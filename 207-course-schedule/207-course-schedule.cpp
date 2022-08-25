class Solution {
public:
    
    void make_graph(vector<vector<int>>& pre , map<int , list<int>>&adjlist)
    {
        for(auto v : pre)
            adjlist[v[1]].push_back(v[0]);
    }
    
    bool iscyclic(int node , unordered_map<int , bool>&visited , unordered_map<int , bool>&instack , map<int , list<int>>&adjlist)
    {
        visited[node] = true;
        instack[node] = true;
        
        for(auto child : adjlist[node])
        {
            if(!visited[child])
            {
                if(iscyclic(child , visited , instack , adjlist))return true;
            }
            else if(instack[child]==true)
                return true;
        }
        instack[node]= false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        if(!pre.size())return true;
        
        map<int , list<int>>adjlist;
        
        make_graph(pre , adjlist);
        
        unordered_map<int , bool>visited;
        unordered_map<int , bool>instack;
        
        for(auto p : adjlist)
        {
            if(!visited[p.first])
            {
                if(iscyclic(p.first , visited , instack , adjlist))return false;
            }
        }
        
        return true;
    }
};