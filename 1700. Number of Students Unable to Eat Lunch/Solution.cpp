class Solution {
public:
   int countStudents(vector<int> &students, vector<int> &sandwiches) {
//    students = [1,1,0,0], sandwiches = [0,1,0,1]
// count the number of students unable to eat

    int round = 0;
    while (!students.empty()) {

        if (students[0] != sandwiches.front()) {
            students.push_back(students[0]);
            round++;
        } else {
            round = 0;
            //if he likes the sandwich than he will take it
            sandwiches.erase(sandwiches.begin());
        }
        students.erase(students.begin());
        if (round == students.size())return int(students.size());

        // none of the queue students want to take the top sandwich
    }

    return 0;

}

};
