class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int cummulativesum=0;
        mp[0]=1;
        long long validleft=0;
        long long result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                validleft+=mp[cummulativesum];
                cummulativesum+=1;
            }else{
                cummulativesum-=1;
                validleft-=mp[cummulativesum];

            }
            mp[cummulativesum]+=1;
            result+=validleft;
            
        }
        return result;
    } 
};