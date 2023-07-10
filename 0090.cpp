class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> totalset = { {} };
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            int cnt = 0;
            while (cnt + i < nums.size() && nums[cnt + i] == nums[i]) cnt += 1;
            int pre = totalset.size();
            for (int j = 0; j < pre; ++j) {
                vector<int> temp = totalset[j];
                for (int k = 0; k < cnt; ++k) {
                    temp.push_back(nums[i]);
                    totalset.push_back(temp);
                }
            }
            i += cnt;

        }
        return totalset;
    }
};