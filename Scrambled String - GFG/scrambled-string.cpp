//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string,bool> mp;
    bool isScramble(string a, string b){
        //code here
        if(a.size()!=b.size())return false;
        if(a.size()==0 || a==b)return true;
        string atmp=a,btmp=b;
        sort(atmp.begin(),atmp.end());
        sort(btmp.begin(),btmp.end());
        if(atmp!=btmp)return false;
        
        string tmp=(a+" "+b);
        if(mp.find(tmp)!=mp.end())
            return mp[tmp];
        int n=a.size();
        for(int i=1;i<n;i++){
            if (isScramble(a.substr(0,i), b.substr(0,i))
                && isScramble(a.substr(i),b.substr(i))) 
                    return mp[tmp]=true;
        
 
        
            if (isScramble(a.substr(0,i),b.substr(n-i))
                && isScramble(a.substr(i, n-i),b.substr(0,n-i))) 
                    return mp[tmp]= true;
        
        }
        return mp[tmp]=false;
             
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends