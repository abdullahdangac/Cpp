#include <iostream>
using namespace std;


class Student {
	int no;
	string name;
 
  public:
    Student(int, string);  // constructor
    ~Student();            // deconstructor
    void print()
		{ cout << no << " " << name << endl; }
};

Student::Student(int no, string name) {	
	this->no = no;
	this->name = name;
}

Student::~Student() {	
	cout << "Student deleted: " << no << " " << name << endl;
}


int main() {	
	Student student1(1001, "Ali");
	student1.print();
	
	Student* student2 = new Student(1002, "Oya");
	student2->print();
    
    delete student2;
   
  	return 0;
}
