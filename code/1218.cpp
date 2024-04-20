class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int > m; int ans = 1;
        for (auto& i : arr) {
            ans = max(ans, m[i] = 1 + m[i - difference]);
        }
        return ans;
    }
};