int Solution::solve(string s) {
    int m=s.size();

    string str=s;
    reverse(str.begin(),str.end());
    string temp=s+"$"+str;
    
    int n=2*m+1;
    vector<int> pi(n);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && temp[i]!=temp[j])
        j=pi[j-1];
        if(temp[i]==temp[j])
        j++;
        pi[i]=j;
    }
    return m-pi[n-1];
}
