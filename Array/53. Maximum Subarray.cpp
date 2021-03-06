/*
若当前和为负数，则从下一个数开始重新计数求和
author: ypz
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int max_num = INT_MIN;
        if(nums.size() == 0) return ans;
        for(int i = 0; i < nums.size(); i++) {
            if(ans < 0) ans = nums[i];
            else ans += nums[i];
            if(ans > max_num) max_num = ans;
        }
        return max_num;
    }
};


/*
            ztc  方法一致

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int count=INT_MIN;
        int tmpsum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(tmpsum<0) tmpsum=nums[i];
            else tmpsum+=nums[i];
                
            count=max(count,tmpsum);
        }
        
        return count; 
    }
};
