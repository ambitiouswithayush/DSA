class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({nums[i],i});
            }
            else{ 
            while(!st.empty() && nums[i]>=st.top().first){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top().second-i;
            }
            st.push({nums[i],i});
            }
            
        }
        return ans;
    }
};