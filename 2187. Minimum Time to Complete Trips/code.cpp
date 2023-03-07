class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long L = 1, R = LONG_MAX;
        auto valid = [&](long long A) { 
            long long sum = 0;
            for (long long n : time) {
                sum += A / n;
                if (sum >= totalTrips) 
                return true; 
            }
            return false;
        };
        while (L <= R) {
            long long M = L + (R - L) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
