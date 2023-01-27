//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int n,mod=1e9+7;
	    vector<int> dp;
	    int solve(string str,int id){
	        if(id>=n)return 1;
	        if(str[id]=='0')
	            return 0;
	        if(dp[id]!=-1)
	            return dp[id];
	        int curr_ans=0;
	        curr_ans+=solve(str,id+1);
	        if(id<n-1){
	            int tmp=(str[id]-'0')*10+(str[id+1]-'0');
	            if(tmp<27)
	                curr_ans+=solve(str,id+2)%mod;
	        }
	        return dp[id]=curr_ans%mod;
	        
	    }
		int CountWays(string str){
		    // Code here
		    n=str.size();
		    dp.resize(n,-1);
		    return solve(str,0)%mod;;
		}
// 36671106
// 12519
// 1 2 5 1 9
// 1 2 5 19
// 1 25 1 9
// 1 25 19
// 12 5 1 9
// 12 5 19
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends