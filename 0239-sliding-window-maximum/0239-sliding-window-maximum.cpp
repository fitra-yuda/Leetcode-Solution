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

struct CompareMax {
    bool operator()(Node* a, Node* b) const {
        return a->getValue() < b->getValue();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<Node*, vector<Node*>, CompareMax> pq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(new Node(i, nums[i]));

            if (i >= k - 1) {
                while (pq.top() -> getIndex() <= i - k) {
                    pq.pop();
                }

                result.push_back(pq.top() -> getValue());
            }
        }

        return result;
    }
};