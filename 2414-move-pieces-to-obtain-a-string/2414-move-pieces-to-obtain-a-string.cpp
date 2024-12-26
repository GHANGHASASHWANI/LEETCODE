class Solution {
public:
    bool canChange(string start, string target) {
        int startIndex = 0, targetIndex = 0;
        int length = start.size();
        while (startIndex < length || targetIndex < length) {
            while (startIndex < length && start[startIndex] == '_') {
                startIndex++;
            }
            while (targetIndex < length && target[targetIndex] == '_') {
                targetIndex++;
            }
            if ((startIndex == length) || (targetIndex == length)) {
                return (startIndex == length) && (targetIndex == length);
            }
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex)) {
                return false;
            }
            startIndex++;
            targetIndex++;
        }
        return true;
    }
};