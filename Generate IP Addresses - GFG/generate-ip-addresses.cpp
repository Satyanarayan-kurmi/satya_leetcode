//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int n;
    vector<string> ans;
    void solve(string s,string tmp,int id,int dot,int curr_num){
        if(id>=n){
            if(dot==4){
                tmp.pop_back();
                ans.push_back(tmp);
            }
            return ;
        }
        if(dot==4)return ;
        string curr="";
        for(int i=id;i<n and i<id+3;i++){
            curr_num*=10;
            curr_num+=s[i]-'0';
            curr+=s[i];
            if(curr.size()>1 and curr[0]=='0')return ;
            tmp+=s[i];
            if(curr_num<256){
                tmp.push_back('.');
                solve(s,tmp,i+1,dot+1,0);
                tmp.pop_back();
            }
        }
        return ;
    }
    vector<string> genIp(string &s) {
        // Your code here
        n=s.size();
        solve(s,"",0,0,0);
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends