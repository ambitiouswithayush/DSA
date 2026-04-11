class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>last(256,-1);
        int l=0,ans=0;
        for(int r=0;r<n;r++){
            if(last[s[r]]>=l){
                l=last[s[r]]+1;
            }
            last[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};