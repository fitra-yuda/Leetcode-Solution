class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long answer = 0;
        int absVal = INT_MAX;
        int negativeNumber = 0;

        for(auto data : matrix){
            for(int number : data){
                answer += abs(number);

                if(number < 0){
                    negativeNumber++;
                }

                absVal = min(absVal, abs(number));
            }
        }

        if (negativeNumber % 2 != 0){
            return answer - (2 * absVal);
        }else{
            return answer;
        }
    }
};