class Solution {
private:
    static constexpr int MOD = 1'000'000'007;

    unordered_set<int> computeDistances(const vector<int>& fences, int border) {
        vector<int> positions = fences;
        positions.push_back(1);
        positions.push_back(border);
        sort(positions.begin(), positions.end());

        unordered_set<int> distances;
        int sz = positions.size();

        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                distances.insert(positions[j] - positions[i]);
            }
        }
        return distances;
    }

public:
    int maximizeSquareArea(
        int m, int n,
        vector<int>& hFences,
        vector<int>& vFences
    ) {
        auto horizontal = computeDistances(hFences, m);
        auto vertical   = computeDistances(vFences, n);

        int maxSide = 0;
        for (int side : horizontal) {
            if (vertical.count(side)) {
                maxSide = max(maxSide, side);
            }
        }

        if (maxSide == 0) return -1;

        return static_cast<long long>(maxSide) * maxSide % MOD;
    }
};
