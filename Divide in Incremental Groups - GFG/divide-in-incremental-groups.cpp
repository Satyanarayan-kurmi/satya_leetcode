//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int solve(int n,int k,int pre){
        if(k==0 and n==0)
            return 1;
        if(k==0)
            return 0;
        if(dp[n][pre][k]!=-1)
            return dp[n][pre][k];
        int tmp=n/k,ans=0;
        
        for(int i=pre;i<=tmp;i++){
            ans+=solve(n-i,k-1,i);
        }
        return dp[n][pre][k]=ans;
    }
    int countWaystoDivide(int n, int k) {
        // Code here
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(n,k,1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends