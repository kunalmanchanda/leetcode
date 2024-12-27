class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        priority_queue<int> q;
        int res = -1;
        q.push(values[0] + 0);

        for(int i = 1; i < values.size(); i++) {
            res = max(res, q.top() + values[i] - i);
            q.push(values[i] + i);
        }

        return res;
    }
};