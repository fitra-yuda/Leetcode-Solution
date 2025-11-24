class Solution {
private:

    bool isPalindrome(string &current) {
        
        for (int i = 0; i < current.size() / 2; i++) {
            if (current[i] != current[current.size() - 1 - i]) {
                return false;
            }
        }

        return true;
    }

    void construct(string &s, vector<vector<string>> &results, vector<string> &result, int index) {
        if (result.size() > 0 && isPalindrome(result[result.size() - 1]) == false) {
            return;
        }

        if (index >= s.length()) {
            results.push_back(result);
            return; 
        } 

        string current = "";
        for (int i = index; i < s.length(); i++) {
            current += s[i];
            result.push_back(current);
            construct(s, results, result, i + 1);
            result.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> result;

        construct(s, results, result, 0);

        return results;
    }
};