#include <iostream>
#include <queue>

using namespace std;

// Definition
class Student {
  private:
    int idNum;
    string name;
  public:
  	Student(int idNum, string name);
    void setName(string name);
    void setId(int idNum);
    string getName() const;
    int getId() const;
};

// Implementation
Student::Student(int idNum, string name){
	this->idNum = idNum;
	this->name = name;
}

void Student::setName(string name) {
  this->name = name;
}

string Student::getName() const{
	return name;
}

void Student::setId(int idNum) {
  this->idNum = idNum;
}

int Student::getId() const{
	return idNum;
}

int main () {
  Student frosh( 11111111,"Shin Kong");
  cout << "frosh name: " << frosh.getName();
  cout << "\nfrosh id: " << frosh.getId();
  queue<Student> q;
  q.push(Student(1112222, "Mark Kong"));
  cout << "\nfrosh name: " << q.back().getName();
  cout << "\nfrosh id: " << q.back().getId();
  return 0;
}

