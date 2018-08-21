int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        
        int pre = nums[0];
        int now = nums[1];
        int length = nums.size();
        
        for(int i = 2; i < length; ++i)
        {
            int tmp = now;
            now = max(pre + nums[i], now);
            pre = max(pre,tmp);
        }
        
        return now;
    }