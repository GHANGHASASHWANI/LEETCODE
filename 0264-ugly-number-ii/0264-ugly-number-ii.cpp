class Solution {
public:
    int nthUglyNumber(int n) {
        vector< int > arr(n+1);

        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        arr[1] = 1;

        for(int i = 2; i <= n; i++){
            int i2ugly = arr[i2]*2;
            int i3ugly = arr[i3]*3;
            int i5ugly = arr[i5]*5;
            int mini = min({i2ugly, i3ugly, i5ugly});
            arr[i] = mini;

            if(i2ugly == mini) i2++;
            if(i3ugly == mini) i3++;
            if(i5ugly == mini) i5++;
        }

        // for(auto i : arr){
        //     cout<<i<<endl;
        // }
        return arr[n];
    }
};