#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::begin;

// second try: correct but potentially slow
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;

	/*
	vector<Student_info>::size_type i = 0;
	*/
	decltype(fail)::size_type i = 0;

	// invariant: elements `[0,' `i)' of `students' represent passing grades
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(begin(students) + i);
		}
		else
			++i;
	}
	return fail;
}