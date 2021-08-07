// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long start,long long mid,long long end)
    {
      long long n=mid-start;
      long long m=end-mid+1;
      long long i,j,k;
      long long temp[n+m];
      i=start,j=mid,k=0;
      long long cnt=0;
      while(i<mid && j <=end)
      {
          if(arr[i]<=arr[j])
          {
              temp[k++]=arr[i];
              i++;
          }
          else 
          {
              temp[k++]=arr[j];
              j++;
              cnt+=mid-i; // inversion count
          }
        //   else
        //   {
        //       temp[k++]=arr[i];
        //       i++;
        //       j++;
        //   }
      
      }
      while(i<mid)
      temp[k++]=arr[i++];
      while(j<=end)
      temp[k++]=arr[j++];
      for(i=start;i<=end;i++)
      arr[i]=temp[i-start];
      return cnt;
    }
    long long merge_sort(long long arr[],long long start,long long end)
    {
        long long cnt=0;
        if(start<end)
        {
            
            long long mid=(start+end)/2;
            cnt+=merge_sort(arr,start,mid);
            cnt+=merge_sort(arr,mid+1,end);
            cnt+=merge(arr,start,mid+1,end);
            
        }
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return merge_sort(arr,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
