class Solution {
    void permute(vector<int>& nums,vector<int>& path,vector<vector<int>>& res,vector<int>& freq)
    {
        if(path.size()==nums.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                path.push_back(nums[i]);
                freq[i]=1;
                permute(nums,path,res,freq);
                freq[i]=0;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        vector<int> freq(nums.size(),0);
        permute(nums,path,res,freq);
        return res;
        
    }
};
