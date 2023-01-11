//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef long long int ll;
class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        ll ans=0;
        // for(auto it:arr)cout<<it<<" ";
        // cout<<endl;
        for(int i=0;i<N;i++){
            if(mp[arr[i]]){
                int j=arr[i];
                while(mp[j])j++;
                mp[j]++;
                ans+=j-arr[i];
            }else mp[arr[i]]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends