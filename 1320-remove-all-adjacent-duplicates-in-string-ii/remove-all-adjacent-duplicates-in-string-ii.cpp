class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        string ans="";

        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first==s[i]){
                st.top().second++;
            }
            else{
                st.push({s[i],1});
            }
            if(st.top().second==k)
            st.pop();
        }
        while(!st.empty()){
           char ch=st.top().first;
           int count=st.top().second;
           st.pop();
           for(int i=0;i<count;i++){
            ans+=ch;
           }
        }
        reverse (ans.begin(),ans.end());
        return ans;
    }
};