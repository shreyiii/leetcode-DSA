class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        int res=0;
        long long tot=0;
        while(r<nums.size()){
            tot+=nums[r];
        while(1LL * nums[r]*(r-l+1)>tot + k){
            tot-=nums[l];
            l++;
        }
        res=max(res,r-l+1);
        r++;
        }
        
        return res;
    }
};