
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef pair<long long, long long> pp;
// typedef long long pp;

#define ordered_set tree<pp, null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set st;
        long long ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            long long need = ceil((nums[i]*1.0) / (2*1.0));
            long long total = st.order_of_key({need, 0});
            ans += total;
            st.insert({nums[i], i});
        }
        return ans;
    }
};