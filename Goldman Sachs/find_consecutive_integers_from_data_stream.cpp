// keep a counter variable to maintain the latest number of elements that match 
// value in the current stream

class DataStream {
    int value;
    int k;
    int count;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        count = 0;
    }
    
    bool consec(int num) {
        if(num == value) count++;
        else count = 0;
        return count >= k;
    }
};