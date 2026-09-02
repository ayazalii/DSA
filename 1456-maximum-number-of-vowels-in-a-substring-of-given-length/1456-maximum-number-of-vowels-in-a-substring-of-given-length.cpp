class Solution {
public:
    bool vowel(char ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int maxVowels(string s, int k) 
    {
        int l=0;
        int r=0; 
        int vcnt=0;
        int ans=0;
        while(r<s.size())
        {
            if(vowel(s[r]))
            {
                vcnt++;
            } 
            if(r-l+1>k)
            {
                if(vowel(s[l])) vcnt--;
                l++;
            }
            ans=max(ans,vcnt);
            r++;
        }
        return ans;
    }
//please upvote...
};