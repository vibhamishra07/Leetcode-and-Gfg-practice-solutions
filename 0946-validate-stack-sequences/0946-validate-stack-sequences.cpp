class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int ps=pushed.size(), pos=popped.size();
        int j=0, i=0;
        stack<int>st;
        while(i<ps && j<pos){
            st.push(pushed[i++]);
            while(!st.empty() && j<pos && st.top()==popped[j]){
                st.pop();
                j++;
            }     
        }
        while(j<pos){
            if(!st.empty() &&  j<pos && st.top()==popped[j]){
          while(!st.empty() && j<pos && st.top()==popped[j]){
                st.pop();
              j++;
          }} 
          else j++;
        }
        
        return (!st.empty())? false:true;
    }
};