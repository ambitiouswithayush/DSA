class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        vector<int>prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];//counting prefixSum
        }
        unordered_map<int,int>mp;//ps,freq
        for(int j=0;j<n;j++){
            if(prefixSum[j]==k) count++;
            int val=prefixSum[j]-k;
            if(mp.find(val)!=mp.end()){//mil gya ps me
                count+=mp[val];
            }
            
            mp[prefixSum[j]]++;
        }
        return count;
    }
};