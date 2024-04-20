class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int time = 0 ;
        vector <int> after ;
        for (int a : nums ) if (a != val) {after.push_back(a) ; time ++; } ;
        nums = after ;
        return time  ;
    }
};