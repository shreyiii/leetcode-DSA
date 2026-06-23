class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;

        int m = r - l + 1;

        vector<long long> dp0(m, 1), dp1(m, 1);
        vector<long long> sum0(m + 1), sum1(m + 1);
        vector<long long> next_dp0(m), next_dp1(m);

        for (int step = 0; step < n - 1; step++) {

            fill(sum0.begin(), sum0.end(), 0);
            fill(sum1.begin(), sum1.end(), 0);

            for (int i = 0; i < m; i++) {
                sum0[i + 1] = (sum0[i] + dp0[i]) % MOD;
                sum1[i + 1] = (sum1[i] + dp1[i]) % MOD;
            }

            long long total0 = sum0[m];

            for (int i = 0; i < m; i++) {
                // Previous move was down, now go up
                next_dp0[i] = sum1[i];

                // Previous move was up, now go down
                next_dp1[i] = (total0 - sum0[i + 1] + MOD) % MOD;
            }

            swap(dp0, next_dp0);
            swap(dp1, next_dp1);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + dp0[i] + dp1[i]) % MOD;
        }

        return (int)ans;
    }
};