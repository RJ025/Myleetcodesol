class CustomStack {
public:
    vector<int>v;
    int size;
    
    CustomStack(int maxSize) {
       size = maxSize;
    }
    
    void push(int x) {
        if(v.size() < size)
        {
            v.push_back(x); 
        }
    }
    
    int pop() {
        if(v.size()>0)
        {
            int y = v[v.size()-1];
            v.pop_back();
            return y ;
        }
        else return -1;
    }
    
    void increment(int k, int val) {
        int s = v.size();
        int last = min(s , k);
        
        for(int i=0 ; i<last ; i++)
        {
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */