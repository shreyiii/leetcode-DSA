class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int ans = 0;
        map<long long, int> freqMap;

        for (auto el : nums) {
            freqMap[el]++;
        }

        for (auto [el, freq] : freqMap) {

            long long x = el;
            int count = 0;

            while (freqMap.find(x) != freqMap.end() && freqMap[x]) {

                if (x == 1) {
                    count += freqMap[1];
                }
                else if (freqMap[x] >= 2) {
                    count += 2;
                }
                else if (freqMap[x] == 1) {
                    count += 1;
                    break;
                }

                freqMap[x] = 0;

                if (x > 1000000)
                    break;

                x *= x;
            }

            ans = std::max(ans, count - (count % 2 == 0));
        }

        return ans;
    }
};