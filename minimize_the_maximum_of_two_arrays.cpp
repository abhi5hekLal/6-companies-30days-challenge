class Solution {
    long long  lcm(long long a, long long b) {
        return  (a * b) / __gcd(a , b);
    }

public:
    int minimizeSet(long long d1, long long d2, long long uCnt1, long long uCnt2) {
        long long start = 1; 
        long long end = 1e10; // smaller range gives errors for large values 
        long long ans;
        while(start <= end) { // must be equal as well 
            long long mid = (start + end) / 2;

            long long a = mid - mid / d1; // count of elements that are in array 1
            long long b = mid - mid / d2; // count of elements that are in array 3
            // count of elements that are common in both. 
            long long c  = mid - (mid / d1) - (mid / d2) + mid / lcm(d1, d2); 
            if(a >= uCnt1 and b >= uCnt2 and a + b - c >= uCnt1 + uCnt2) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};