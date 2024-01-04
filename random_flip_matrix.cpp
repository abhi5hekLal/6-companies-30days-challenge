/* 
- no need to create any 2d array we don't need it
- generate random number b/w 0 and total number of elements and convert them
to rows and columns accordingly
- at the end remove elements that have already been repeated before to ensure 
everyone gets equal possilbilty of being called

*/
class Solution {
    int r, c;
    unordered_map<int, int> mp;
    int total;
public:
    Solution(int m, int n) {
        r = m;
        c = n;
        total = m * n;
    }
    
    vector<int> flip() {
        int randNum = rand() % total;

        int actual = mp.count(randNum) == 0 ? randNum : mp[randNum];

        int row = actual / c;
        int col = actual % c;

        mp[randNum] = mp.count(total - 1) == 0 ? total - 1 : mp[total - 1];
        total--;

        return {row, col};
    }
    
    void reset() {
        total = r * c;
        mp.clear();
    }
};
