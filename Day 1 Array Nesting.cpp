class Solution {
public:
    int vis[100005];
    int maxi = 0;
    void ok(int i, int total, vector<int> &nums){
        if(vis[i] == 1){
            maxi = max(maxi, total);
            return;
        }
        vis[i] = 1;
        ok(nums[i], total + 1, nums);
        return;
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i < nums.size(); i++)
        {
            if(vis[i] == 0) {
                ok(i, 0, nums);
            }
        }
        return maxi;
    }
};