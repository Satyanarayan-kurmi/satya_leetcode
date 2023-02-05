//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        Node* tmp=head1;
        int len1=0,len2=0;
        while(tmp){
            len1++;
            tmp=tmp->next;
        }
        tmp=head2;
        while(tmp){
            len2++;
            tmp=tmp->next;
        }
        
        Node*tmp1,*tmp2;
        tmp1=head1,tmp2=head2;
        if(len1>len2){
            int k=len1-len2;
            while(k--){
                tmp1=tmp1->next;
            }
        }else{
            int k=len2-len1;
            while(k--){
                tmp2=tmp2->next;
            }
        }
        
        while(tmp1!=tmp2){
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        if(tmp1==NULL)
            return -1;
        return tmp1->data;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends