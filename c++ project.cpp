#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Student
{
  string name;
  int age;
  string address;
};

map<int, Student> students;

void add_student()
{
  int id;
  cout << "Enter student ID: ";
  cin >> id;
  Student s;
  cout << "Enter student name: ";
  cin >> s.name;
  cout << "Enter student age: ";
  cin >> s.age;
  cout << "Enter student address: ";
  cin >> s.address;
  students[id] = s;
  cout << "Student added successfully\n";
}

void view_student()
{
  int id;
  cout << "Enter student ID: ";
  cin >> id;
  if (students.count(id) == 0)
  {
    cout << "Student not found\n";
    return;
  }
  Student s = students[id];
  cout << "Name: " << s.name << endl;
  cout << "Age: " << s.age << endl;
  cout << "Address: " << s.address << endl;
}

int main()
{
  while (true)
  {
    cout << "1. Add student\n";
    cout << "2. View student\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
      add_student();
    }
    else if (choice == 2)
    {
      view_student();
    }
    else if (choice == 3)
    {
      break;
    }
    else
    {
      cout << "Invalid choice\n";
    }
  }
  return 0;
}

