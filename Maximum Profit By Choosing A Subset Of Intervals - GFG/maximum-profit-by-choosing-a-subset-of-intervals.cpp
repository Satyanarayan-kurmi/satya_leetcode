//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> vec;
    // int find_index(int element,int id){
    //     int l=0,h=id-1;
    //     int ans=-1;
    //     while(l<=h){
    //         int mid=(l+h)/2;
    //         if(vec[mid][0]<=element){
    //             ans=mid;
    //             l=mid+1;
    //         }
    //         else h=mid-1;
            
    //     }
    //     return ans;
        
    // }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            vec.push_back({intervals[i][1],intervals[i][0],intervals[i][2]});
        }
        int ans=INT_MIN;
        sort(vec.begin(),vec.end());
        vector<int> arr;
        for(int i=0;i<n;i++){
            dp[i]=vec[i][2];
            int ele=vec[i][1];
            // int index=find_index(ele,i);
            int index=upper_bound(arr.begin(),arr.end(),ele)-arr.begin();
            index--;
            if(index>-1)
                dp[i]+=dp[index];
            if(i>0)
                dp[i]=max(dp[i],dp[i-1]);
            // cout<<dp[i]<<" ";
            arr.push_back(vec[i][0]);
            ans=max(ans,dp[i]);
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends