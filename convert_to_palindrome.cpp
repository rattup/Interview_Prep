int check1(string s,int index)
{
    int i=0;
    int j=s.size()-1;
    while(i<=j)
    {
        if(i==index)
        i=i+1;
        else
        {
            if(s[i]!=s[j])
            return 0;
            i++;
            j--;
        }
        
    }
    return 1;
}
int check2(string s,int index)
{
    int i=0;
    int j=s.size()-1;
    while(i<=j)
    {
        if(j==index)
        j=j-1;
        else
        {
            if(s[i]!=s[j])
            return 0;
            i++;
            j--;
        }
        
    }
    return 1;
}
int Solution::solve(string s) {
    int n= s.size();
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        break;
        i++;
        j--;
    }
    if(i>j)
    return 1;
    if(check1(s,i) || check2(s,j))
    return 1;
    return 0;


}

