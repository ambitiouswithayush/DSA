class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest_sum=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            largest_sum=max(largest_sum,sum);
            if(sum<0)
            sum=0;
        }
        return largest_sum;
    }
};