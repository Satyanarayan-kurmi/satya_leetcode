//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int root_to_target_sum=0;
    int flag=0;int ans=INT_MIN;
    Node* target_node=NULL;
    void find_sum(Node* root,int target,int curr_sum){
        if(!root || flag)return ;
        if(target==root->data){
            flag=1;
            root_to_target_sum=curr_sum;
            target_node=root;
            return ;
        }
        find_sum(root->left,target,curr_sum+root->data);
        find_sum(root->right,target,curr_sum+root->data);
        
        return ;
        
    }
    void solve(Node* root,int curr_sum,int target){
        if(!root)return ;
        
        curr_sum+=root->data;
        if(!root->left and !root->right){
            curr_sum-=target;
            ans=max(ans,(root_to_target_sum-curr_sum));
            return ;
        }
        solve(root->left,curr_sum,target);
        solve(root->right,curr_sum,target);
        
        return ;
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        // if(target==root->data)
        //     return -1;
        find_sum(root,target,0);
        if(flag==0)
            return -1;
           
        // cout<< root_to_target_sum<<endl;
        solve(target_node,0,target);
        return ans;
    }
};

// 7
// 13 14 4 9 19 3 20
// 13
// 8
// 25 20 35 15 22 30 45 32
// 20


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends