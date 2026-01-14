class Logger {
private:
    unordered_map<string,int> bucket;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (bucket.count(message) == 0) {
            bucket[message] = timestamp + 10;
            return true;
        } else if (bucket[message] - timestamp > 0) {
            return false;
        } else {
            bucket[message] = timestamp += 10;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */