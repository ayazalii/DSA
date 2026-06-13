class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (auto& word : words) {
            int sum = 0;

            for (char c : word)
                sum = (sum + weights[c - 'a']) % 26;

            ans += char('z' - sum);
        }

        return ans;
    }
};