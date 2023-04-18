//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int n, vector<int> &a, vector<int> &b) {
        
        vector<int>a1[2] , b1[2];
        long long suma=0 , sumb=0;
        for(int i=0 ; i<n ; i++)
        {
            suma+=a[i];
            sumb+=b[i];
            if(a[i]%2==0)a1[0].push_back(a[i]);
            else a1[1].push_back(a[i]);
            if(b[i]%2==0)b1[0].push_back(b[i]);
            else b1[1].push_back(b[i]);
        }
        
        if(suma!=sumb || (a1[0].size()!=b1[0].size()))return -1;
        
        sort(a1[0].begin() , a1[0].end());
        sort(a1[1].begin() , a1[1].end());
        sort(b1[0].begin() , b1[0].end());
        sort(b1[1].begin() , b1[1].end());
        long long ans=0;
        for(int i=0 ; i<2 ; i++)
        {
            for(int j=0 ; j<a1[i].size() ; j++)
            {
                ans+=abs(a1[i][j]-b1[i][j]);
            }
        }
        return ans/4;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends