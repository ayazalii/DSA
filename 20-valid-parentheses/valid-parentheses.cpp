class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.size()==0) return false;
                char tp=st.top();
                st.pop();
                if(ch==')' && tp!='(') return false;
                if(ch=='}' && tp!='{') return false;
                if(ch==']' && tp!='[') return false;
            }
        }
        return st.empty();
    }
};