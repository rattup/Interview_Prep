class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            st.push(i);
            else
            {
                if(st.top()==-1 || s[st.top()]!='(')
                st.push(i);
                else
                {
                st.pop();
                maxi=max(maxi,i-st.top());
                }
            }
            
        }
        return maxi;
        
    }
};
