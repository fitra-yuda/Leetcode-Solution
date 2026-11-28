class Node {
private:
    int index;
    int value;
public:
    Node(int index, int value) {
        this -> index = index;
        this -> value = value;
    }

    int getIndex() {
        return this -> index;
    }

    int getValue() {
        return this -> value;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<Node*> dq;        
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            while (dq.size() > 0 && dq.back() -> getValue() < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(new Node(i, nums[i]));

            if (i >= k - 1) {
                while (dq.front() -> getIndex() <= i - k) {
                    dq.pop_front();
                }

                result.push_back(dq.front() -> getValue());
            }
        }

        return result;
    }
};
