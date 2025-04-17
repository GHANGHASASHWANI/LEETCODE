class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependency(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue< int > checkCourses;

        for(int i =0; i < prerequisites.size(); i++){
            int course1 = prerequisites[i][0], course2 = prerequisites[i][1];
            dependency[course2].push_back(course1);
            inDegree[course1]++;
        }

        for(int i =0;i < inDegree.size(); i++){
            if(inDegree[i] == 0) checkCourses.push(i);
        }

        vector<int> courseOrder;

        while(not checkCourses.empty()){
            int currCourse = checkCourses.front();
            checkCourses.pop();
            courseOrder.push_back(currCourse);

            for(auto& newCourse : dependency[currCourse]){
                inDegree[newCourse]--;
                if(inDegree[newCourse] == 0) checkCourses.push(newCourse);
            }
        }
        return courseOrder.size() == numCourses;
    }
};