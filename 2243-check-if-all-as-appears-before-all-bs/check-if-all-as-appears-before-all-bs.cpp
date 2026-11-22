class Solution {
public:
    bool checkString(string s) {
        bool seenb=false;
        for(char c : s){
            if(c=='b'){
                seenb=true;
            } else if(seenb){
                return false;
            }
        }
        return true;
    }
};