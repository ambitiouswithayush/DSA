class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int l=INT_MAX,sum=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                l=min(l,j-i+1);
                i++;
            }
        }
        if(l==INT_MAX) return 0;
        return l;
    }
};