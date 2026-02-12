class Solution {
private:
    bool isOpenBracket(char x) {
        return x == '(' || x == '[' || x == '{';
    }

    bool isValid(stack<char> &st, char x) {

        if (st.size() == 0) {
            return false;
        }

        if (st.top() == '(' && x == ')') {
            return true;
        } else if (st.top() == '[' && x == ']') {
            return true;
        } else if (st.top() == '{' && x == '}') {
            return true;
        }

        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        bool result = true;

        for (auto character : s) {
            
            if (isOpenBracket(character)) {
                st.push(character);
            } else if (isValid(st, character)) {
                st.pop();
            } else {
                result = false;
                break;
            }
        }

        if (st.size() != 0) {
            result = false;
        }

        return result;
    }
};