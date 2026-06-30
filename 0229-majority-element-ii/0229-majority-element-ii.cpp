class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0;
        int maj1=0;
        int n=nums.size();
        int c2=0;
        int maj2=1;
        for(int i=0;i<n;i++){
            if (nums[i]==maj1){
                c1++;

            }else if(nums[i]==maj2){
                c2++;
            }else if(c1==0){
                maj1=nums[i];
                c1=1;

            }else if (c2==0){
                maj2=nums[i];
                c2=1;
           }else {
            c1--;
            c2--;
           }
        }

        vector<int>res;
        int freq1=0;
        int freq2=0;
        for(int&num:nums){
            if(num==maj1)
                freq1++;
            else if (num==maj2)
                freq2++;
            
        }
        if (freq1>floor(n/3)){
            res.push_back(maj1);
        }
        if (freq2>floor(n/3)){
            res.push_back(maj2);
        }
        return res;

    }
};