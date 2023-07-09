class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size(), left = 0, ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'F') {
                cnt++;
            }
            while (cnt > k) {
                if (s[left] == 'F') {
                    cnt--;
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        cnt = 0, left = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'T') {
                cnt++;
            }
            while (cnt > k) {
                if (s[left] == 'T') {
                    cnt--;
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};