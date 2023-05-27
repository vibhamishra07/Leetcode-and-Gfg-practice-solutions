//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        for(int i=0; i<=ceil(n/2)-1; i++){
            int leftChild=i*2+1;
            int rightChild=i*2+2;
            if(leftChild<n && a[i]<a[leftChild]) return false;
            if(rightChild<n && a[i]<a[rightChild]) return false;
        }
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends