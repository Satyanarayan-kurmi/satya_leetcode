//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string us="",ls="";
        for(auto it:str){
            if(it>='a' and it<='z')ls+=it;
            else us+=it;
        }
        string ans="";
        sort(ls.begin(),ls.end());
        sort(us.begin(),us.end());
        
        int i=0,j=0;
        for(auto it:str){
            if(it>='a' and it<='z')ans+=ls[i++];
            else ans+=us[j++];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends