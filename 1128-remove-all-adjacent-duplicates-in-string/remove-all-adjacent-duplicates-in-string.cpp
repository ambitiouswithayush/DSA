class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string result="";
        for(char ch:s){
            if(st.empty()||st.top()!=ch)
            st.push(ch);
            else
            st.pop();
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};