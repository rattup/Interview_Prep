int Solution::braces(string A) {
    stack<char> st;
    int n=A.size();
    for(auto it:A)
    {
        if(it==')')
        {
            int top=st.top();
            st.pop();
            int flag=true;
            while(!st.empty() && top!='(')
            {
                if(top=='+' || top=='-' || top=='*' || top=='/')
                flag=0;
                top=st.top();
                st.pop();
            }
            if(flag==1)
            return 1;

        }
        else
        st.push(it);
    }
    return 0;
}

