//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        long long int R[N],G[N],B[N];
        R[0]=r[0],G[0]=g[0],B[0]=b[0];
        for(int i=1;i<N;i++){
            R[i]=r[i]+min(G[i-1],B[i-1]);
            G[i]=g[i]+min(R[i-1],B[i-1]);
            B[i]=b[i]+min(G[i-1],R[i-1]);
        }
        return min(R[N-1],min(G[N-1],B[N-1]));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends