class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        int pos = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                critical.push_back(pos);
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (critical.size() < 2) return {-1, -1};

        int minDist = INT_MAX;
        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i - 1]);
        }
        int maxDist = critical.back() - critical.front();

        return {minDist, maxDist};
    }
};