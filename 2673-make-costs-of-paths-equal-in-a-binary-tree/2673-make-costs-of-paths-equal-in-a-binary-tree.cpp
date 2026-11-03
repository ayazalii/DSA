class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0, maxOfC;
        for (int i = ((n - 1) / 2) - 1; i >= 0 ; i--)
        {
            maxOfC = max(cost[2 * i + 1], cost[2 * i + 2]);
            res += (maxOfC -  min(cost[2 * i + 1], cost[2 * i + 2]));
            cost[i] = cost[i] + maxOfC;
        }
        return res;
    }
};