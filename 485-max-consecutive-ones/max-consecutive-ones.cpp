class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counti =0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) 
            {    counti+=1;
                maxi=max(maxi,counti);}
            else
            counti=0;
        }
        return maxi;
    }
};