#include<iostream>
#include<algorithm>
#include<string>
using std::endl;
using std::cout;

class Student {
	std::string name;
	int score;
public:
	Student(std::string _name, int _score) :name(_name), score(_score) {}
	std::string getName() const{ return name; }
	bool operator<(const Student& stu) {
		return score < stu.score;
	}
};

int main() {
	Student students[] = {
		Student("±èÁöÀÏ", 100),
		Student("µ¿ºû³ª", 90),
		Student("°­ÇÏ´Ã",19),
		Student("ÀÌ¹ÎÁö",23)
	};
	std::sort(students, students+4); 
	for (int i = 0; i < 4; i++) {
		cout << students[i].getName() << " ";
	}

	return 0;
}