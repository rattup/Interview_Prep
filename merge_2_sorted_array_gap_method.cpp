class Solution {
public:
    int findgap(int n)
 {
     if(n<=1)
     return 0;
     return n/2+n%2;
 }
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=m+n;
        int i,j;
        for(gap=findgap(gap);gap>0;gap=findgap(gap))
        {
        for( i=0;i+gap<m;i++)
        {
            if(nums1[i]>nums1[i+gap])
            swap(nums1[i],nums1[i+gap]);
        }
        
          
        for(j=gap>m?gap-m:0;i<m && j<n;i++,j++)
        if(nums1[i]>nums2[j])
        swap(nums1[i],nums2[j]);
        
        
        
            for(j=0;j+gap<n;j++)
            if(nums2[j]>nums2[j+gap])
            swap(nums2[j],nums2[j+gap]);
            
        
        
            
        }
        for(j=0;j<n;j++)
        nums1[m+j]=nums2[j];
        // for(auto it:nums1)
        // cout<<it<<" ";
        
        
        
    }
};
