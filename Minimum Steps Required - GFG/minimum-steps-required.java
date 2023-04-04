//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG{
	public static void main(String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- > 0) {
			String str = br.readLine();
			Solution obj = new Solution();
			System.out.println(obj.minSteps(str));
		}
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution{
	int minSteps(String str) {
		//Write your code here
		char tar=str.charAt(0);
		int ans=0,n=str.length();
		for(int i=0;i<n;i++){
		    if(str.charAt(i)==tar){
		        ans++;
		        while(i<n && str.charAt(i)==tar)
		            i++;
		    }else{
		        while(i<n && str.charAt(i)==tar)
		            i++;
		    }
		}
		if(str.charAt(n-1)!=tar)
		    ans++;
		return ans;
	}
}