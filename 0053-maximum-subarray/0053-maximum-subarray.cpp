class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0,maxsum=INT_MIN;
        for(int val:nums){
            cur+=val;
            maxsum=max(cur,maxsum);
            if(cur<0){
                cur=0;

            }
        }return maxsum;
    }
};