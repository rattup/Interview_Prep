class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high) // each time either left half is sorted or right half
        {
            int mid=(low+high)>>1;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>=nums[low] )
            {
                if(target>=nums[low] && target<=nums[mid])
                high=mid;
                else
                low=mid+1;
            }
            else
            {
                if(target>=nums[mid+1] && target<=nums[high])
                low=mid+1;
                else
                high=mid;
                
            }
        }
        return -1;
        
    }
};
