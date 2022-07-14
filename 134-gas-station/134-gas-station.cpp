class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit=0, balance=0, start=0, n=gas.size();
    
    for(int i=0;i<n;i++){
        balance+= gas[i]-cost[i];
        
        if(balance<0){
            deficit += balance;
            start=i+1;
            balance=0;
        }
    }
    
    if(balance + deficit >= 0){
        return start;
    }
    return -1;
    }
};