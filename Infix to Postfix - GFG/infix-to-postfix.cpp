//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        int n=s.size();
        string postfix="";
        stack<pair<char, int>>st;

        for(int i=0; i<n; i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')){
                postfix+=s[i];
            }else{
                int prs=precedence(s[i]);
                if(!st.empty()){
                   pair<char, int> p=st.top();
                
                   if(p.second<prs || s[i]=='(') st.push({s[i], prs});
                   else{
                       if(s[i]==')'){
                           while(p.first!='('){
                               postfix+=p.first;
                               st.pop();
                               p=st.top();
                           }
                           st.pop();
                       }
                       else{
                           while(p.second>=prs){
                               postfix+=p.first;
                               st.pop();
                               if(st.empty()){
                                   break;
                               }
                               p=st.top();
                               
                           }
                           st.push({s[i], prs});
                           
                       }
                   }
                   
                }else{
                    st.push({s[i], prs});
                }
            }
        }
        pair<char, int> p1;
        while(!st.empty()){
            p1=st.top();
            postfix+=p1.first;
            st.pop();
        }
        return postfix;
    }
    int precedence(char op)
    {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
               return -1;
        }
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends