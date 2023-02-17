class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mn = INT_MAX;
        int l = nums.size();
        int ans ;
        sort(nums.begin(),nums.end());
        for(int i=0;i<l;i++){
            int lo = i+1;
            int hi = l-1;
            while(lo<hi){
                int sum = nums[i] + nums[lo] + nums[hi];
            if (abs(target-sum)<mn){
                ans = sum;
                mn = abs(target-sum);
            }
            if(sum>target){
                hi--;
            }
            else{
                lo++;
            }
            }
        }
        return ans;
    }
};