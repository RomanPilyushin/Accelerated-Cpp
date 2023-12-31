#include <iostream>
#include <vector>
// ctime is used for code runtime estimation
#include <ctime>
// include the simplified version of Student_info
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fails;
    vector<Student_info>::iterator it = students.begin();
    while (it != students.end()) {
        // we can access only the final grade from simplified version
        if (it->final_grade < 60) {
            fails.push_back(*it);
            it = students.erase(it);
        }
        else
            ++it;
    }

    return fails;
}

int main()
{
    vector<Student_info> students;
    Student_info student;

    // read all student data
    while (read(cin, student))
        students.push_back(student);

    // save the original size
    vector<Student_info>::size_type count = students.size();

    double begin = clock();
    vector<Student_info> fails = extract_fails(students);
    double end = clock();

    cout << "Extracting fails for " << count << " students took "
        << (end - begin) / CLOCKS_PER_SEC << " seconds." << endl;

    return 0;
}