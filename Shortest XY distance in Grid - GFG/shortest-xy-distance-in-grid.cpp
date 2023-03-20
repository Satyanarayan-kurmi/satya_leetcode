//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        queue<vector<int>> q;
        vector<vector<int>> vis(N,vector<int>(M,0));
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(grid[i][j]=='X'){
                    q.push({i,j,0});
                    vis[i][j]=1;
                 }   
                 
        vector<vector<int>> arr={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int ii=curr[0],jj=curr[1],dis=curr[2];
            if(grid[ii][jj]=='Y')
                return dis;
            for(auto it:arr){
                int x=it[0]+ii,y=it[1]+jj;
                if(x>=0 and x<N and y>=0 and y<M and vis[x][y]==0){
                    q.push({x,y,dis+1});
                    vis[x][y]=1;
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends