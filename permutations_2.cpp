class Solution {
    void permute(int index,vector<int>& nums,vector<vector<int>>& res)
    {
        if(index==nums.size())
        {
            res.push_back(nums);
            return ;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            permute(index+1,nums,res);
            swap(nums[index],nums[i]);
        }
        
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
       // vector<int> freq(nums.size(),0);
        permute(0,nums,res);
        return res;
        
    }
};
