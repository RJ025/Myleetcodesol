class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if(income==0)return 0;
        int i=0;
        double sum=0;
        int prev=0;
        while(i<(brackets.size()))
        {
           int actual = min(brackets[i][0] , income);
           sum+=(((actual-prev)*brackets[i][1])/100.00000);
            if(brackets[i][0] > income)break;
            
            prev = actual;
            i++;
            
        }
        return sum;
    }
};