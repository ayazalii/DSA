class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0 , j=0;
        int n1=word1.size(), n2=word2.size();
        string ans;
        ans.reserve(n1+n2);
        while(i<n1 && j<n2){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        while(i<n1) ans+=word1[i++];
        while(j<n2) ans+=word2[j++];
        return ans;
    }
};