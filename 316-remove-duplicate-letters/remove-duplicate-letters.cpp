class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        for(char c:s) mp[c]++;

        stack<int>st;
        unordered_set<char>used;
        for(char c:s){
            mp[c]--;

            if(used.count(c)) continue;

            while(!st.empty() && st.top()>c && mp[st.top()]>0){
                used.erase(st.top());
                st.pop();
            }
            st.push(c);
            used.insert(c);
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};