class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e,cnt;
        e=cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            e=nums[i];
            if(nums[i]==e)
            cnt++;
            else
            cnt--;
            
        }
        return e;
        
    }
};
