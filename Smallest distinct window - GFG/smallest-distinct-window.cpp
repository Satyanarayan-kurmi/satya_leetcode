//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int> mp;
        for(auto it:str)mp[it]++;
        int total_char=mp.size();
        
        mp.clear();
        int start=0,end=0,curr_char=0,ans=INT_MAX;
        for(;end<str.size();end++){
            mp[str[end]]++;
            if(mp[str[end]]==1)
                curr_char++;
            while(mp[str[start]]>1){
                mp[str[start]]--;
                start++;
            }   
            if(curr_char==total_char)
                ans=min(ans,end-start+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends