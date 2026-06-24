class Solution {
    static const long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int sz = A.size();
        Matrix res(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;

                    res[i][j] = (res[i][j] +
                                A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix matrixPower(Matrix base, long long exp) {
        int sz = base.size();

        Matrix result(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) {
            result[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                result = multiply(result, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int values = r - l + 1;

        if (n == 1) {
            return values;
        }

        int states = 2 * values;

        // state [0 ... values-1]      -> last move was down
        // state [values ... 2*values-1] -> last move was up
        Matrix transition(states, vector<long long>(states, 0));

        for (int curr = 0; curr < values; curr++) {

            // up -> down
            for (int next = 0; next < curr; next++) {
                transition[next][values + curr] = 1;
            }

            // down -> up
            for (int next = curr + 1; next < values; next++) {
                transition[values + next][curr] = 1;
            }
        }

        // DP for arrays of length 2
        vector<long long> start(states, 0);

        for (int x = 0; x < values; x++) {
            start[x] = values - x - 1; // down states
            start[values + x] = x;     // up states
        }

        Matrix powerMatrix = matrixPower(transition, n - 2);

        vector<long long> dp(states, 0);

        for (int i = 0; i < states; i++) {
            for (int j = 0; j < states; j++) {
                dp[i] = (dp[i] +
                        powerMatrix[i][j] * start[j]) % MOD;
            }
        }

        long long answer = 0;

        for (long long ways : dp) {
            answer = (answer + ways) % MOD;
        }


        return (int)answer;
    }
};