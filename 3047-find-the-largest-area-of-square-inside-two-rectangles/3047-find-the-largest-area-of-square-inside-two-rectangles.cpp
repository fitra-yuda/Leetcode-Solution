class Solution {
private:    
    long long min(long long a, long long b) {
        if (a > b) {
            return b;
        }

        return a;
    }

    long long max(long long a, long long b) {
        if (a > b) {
            return a; 
        } else {
            return b;
        }
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long w = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                long long h = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                maxSide = max(maxSide, min(w, h));
            }
        }

        return maxSide * maxSide;
    }
};