class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        stack<int> s;
        int n = ass.size();
        for (int i = 0; i < n; ++i) {
            if (ass[i] > 0 || s.empty()) {
                s.push(ass[i]);
            }
            else {
                while (!s.empty() and s.top() > 0 and s.top() < abs(ass[i])) {
                    s.pop();
                }
                if (!s.empty() and s.top() == abs(ass[i])) {
                    s.pop();
                }
                else {
                    if (s.empty() || s.top() < 0) {
                        s.push(ass[i]);
                    }
                }
            }
        }
        vector<int> res(s.size());
        for (int i = int(s.size()) - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};