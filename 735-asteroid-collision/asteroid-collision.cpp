class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            while(!st.empty() && ((arr[i]<0 && st.top()>0))){
                flag=false;
                if((abs(st.top())<abs(arr[i]))){
                    st.pop();
                    flag=true;
                }
                else if(!st.empty() && (abs(st.top())==abs(arr[i]))){
                    st.pop();
                    break;
                }
                else{
                    break;
                }
            }
            if(flag)st.push(arr[i]);
            
        }
        int k=st.size();
        vector<int> ans(k);
        while(!st.empty()){
            ans[--k]=st.top();
            st.pop();
        }
        return ans;
    }
};