class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;

        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 1;
        int currend = pairs[0][1];

        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > currend) {
                ans++;
                currend = pairs[i][1];
            }
        }

        return ans;
    }
};