//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int N=1e5;
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        vector<int> prime(N+1,0);
        prime[0]=1,prime[1]=1;
        for(int i=2;i<=N;i++){
            if(prime[i]==0){
                for(int j=i+i;j<=N;j+=i)
                    prime[j]=1;
            }
        }
        
        vector<int> vis(N,0);
        string src=to_string(Num1);
        string dest=to_string(Num2);
        queue<string> q;
        q.push(src);
        int level=0;
        while(!q.empty()){
            int len=q.size();
            level++;
            while(len--){
                string curr=q.front();
                if(curr==dest)
                    return level-1;
                q.pop();
                for(int i=0;i<curr.size();i++){
                    for(int j=0;j<=9;j++){
                        if(i==0 and j==0)
                            continue;
                        string tmp=curr;
                        tmp[i]=('0'+j);
                        int t=stoi(tmp);
                        if(prime[t]==0 and vis[t]==0){
                            q.push(tmp);
                            vis[t]=1;
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends