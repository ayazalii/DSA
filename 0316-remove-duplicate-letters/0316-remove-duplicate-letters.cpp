class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<char> seen;
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(seen.find(ch) != seen.end()) {
                continue;
            }

            while(!ans.empty() && ans.back() > ch) {
                bool found = false;

                for(int j = i + 1; j < s.length(); j++) {
                    if(s[j] == ans.back()) {
                        found = true;
                        break;
                    }
                }

                if(found) {
                    seen.erase(ans.back());
                    ans.pop_back();
                }
                else {
                    break;
                }
            }

            ans += ch;
            seen.insert(ch);
        }

        return ans;
    }
};