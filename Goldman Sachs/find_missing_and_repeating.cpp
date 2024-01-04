class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xorAll = 0;
        
        for(int i = 1; i <= n; i++) {
            xorAll ^= i;
        }
        
        for(int i = 0; i < n; i++) {
            xorAll ^= arr[i];    
        }
        
        // finally xorAll contains the xor of only  elements that occurs 2 times or 
        // not even once
        
        // bitmask contains the rightmost set bit in xorAll
        int bitmask = xorAll & ~(xorAll - 1);
        
        int x(0), y(0);
        // now we try to filter out the number based on who has that specific set bit
        
        for(int i = 0; i < n; i++) {
            if(arr[i] & bitmask) {
                x = x ^ arr[i];
            }
            else {
                y = y ^ arr[i];
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(i & bitmask) {
                x = x ^ i;
            }
            else {
                y = y ^ i;
            }
        }
        
        return {x, y};
    }
};
