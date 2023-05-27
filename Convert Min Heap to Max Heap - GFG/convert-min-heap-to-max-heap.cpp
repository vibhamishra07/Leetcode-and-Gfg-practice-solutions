//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
       for(int i=ceil(N/2)-1; i>=0; i--){
           max_heapify(arr, i, N);
       }
    }
    void max_heapify(vector<int> &arr, int i, int N){
        int maxElem=i;
        int leftChild=i*2+1;
        int rightChild=i*2+2;
        if(leftChild<N && arr[i]<arr[leftChild]){
            maxElem=leftChild;
        }
        if(rightChild<N && arr[maxElem]<arr[rightChild]){
            maxElem=rightChild;
        }
        if(maxElem!=i){
            swap(arr[maxElem], arr[i]);
            max_heapify(arr, maxElem, N);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends