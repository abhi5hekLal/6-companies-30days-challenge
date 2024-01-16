class Solution {
public:
    int longestString(int x, int y, int z) {
        /*
            AB doesn't effect the length all of it can be used at the
            beginning or the end depending upon the start or end
            of the string
            if string ends with A we put AB in the beginning
            if string ends with B we put AB at the end.
        */
        if(x == y) return ((x << 1) + z) << 1;
        int n = min(x, y);
        return (n + (n + 1) + z) << 1;
    }
};