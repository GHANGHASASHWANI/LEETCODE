class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if (skill.empty()) {
            return -1;
        }

        long long answer = 0;
        int n = skill.size();
        if (n == 2) {
            return static_cast<long long>(skill[0]) * skill[1];
        }

        sort(skill.begin(), skill.end());
        int left = 0, right = n - 1;
        while (left < right) {
            if (skill[left] + skill[right] !=  (skill[left+1] + skill[right-1])) {
                return -1;
            }
            answer += static_cast<long long>(skill[left]) * skill[right];
            left++;
            right--;
        }

        return answer;
    }
};
