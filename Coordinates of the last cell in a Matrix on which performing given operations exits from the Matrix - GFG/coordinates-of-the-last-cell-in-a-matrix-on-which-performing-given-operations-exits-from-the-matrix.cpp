//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> mat){
        //code here
        int n=mat.size(),m=mat[0].size();
        pair<int,int> ans;
        unordered_map<string,string> mp;
        mp["up"]="right";
        mp["right"]="down";
        mp["down"]="left";
        mp["left"]="up";
        
        string dir="right";
        int i=0,j=0;
        while(i<n and j<m and i>=0 and j>=0 ){
            // cout<<i<<" "<<j<<endl;
            ans={i,j};
            if(mat[i][j]==0){
                if(dir=="up")i--;
                else if(dir=="down")i++;
                else if(dir=="right")j++;
                else j--;
            }else{
                mat[i][j]=0;
                dir=mp[dir];
            }
        }
        
        return ans;
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends