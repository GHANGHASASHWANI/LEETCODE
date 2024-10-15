class Solution {
public:
    int tribonacci(int n) {
        if(n == 0 ){
            return 0;
        }
        else if( n <= 2){
            return 1;
        }
        vector< int > series(n+1);
        // Store the base case values
        series[0] = 0;
        series[1] = 1;
        series[2] = 1;

        // calculate the upcoming series upto nth value.
        for(int index = 3; index <= n; index++){
            series[index] = series[index - 1] + series[index - 2] + series[index - 3];
        }
        return series[n];
    }
};