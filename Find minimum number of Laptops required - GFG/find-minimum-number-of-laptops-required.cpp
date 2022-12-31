//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        multiset<int> st;
        int ans=0;
        vector<vector<int>> arr;
        for(int i=0;i<N;i++){
            arr.push_back({end[i],start[i]});
        }
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<N;i++){
            int start_time=arr[i][1];
            int end_time=arr[i][0];
            if(st.empty()){
                ans++;
                st.insert(end_time);
            }else{
                auto it=st.upper_bound(start_time);
                if(it==st.begin()){
                    ans++;
                    st.insert(end_time);
                }else{
                    it--;
                    st.erase(st.find(*it));
                    st.insert(end_time);
                }
            }
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
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends