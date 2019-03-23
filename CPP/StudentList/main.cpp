#include <iostream>
#include <string>
#include <conio.h>
#include <cctype>

using namespace std;

typedef struct Student {
  string name;
  int age;
  char gen;
  struct Student *NextStudent;
}Student;
Student *First_Student = NULL;

void Insert( string Name, int Age,char Gen ) {
  Student *CurrentStudent = new Student;
  CurrentStudent->name = Name;
  CurrentStudent->age = Age;
  CurrentStudent->gen = Gen;
  CurrentStudent->NextStudent = First_Student;
  First_Student = CurrentStudent;
}

void Display( ) {
 Student *TheStudent = First_Student;
 if ( First_Student = NULL ) cout << " " << " No Student in the List." <<endl;
 else{
    while ( TheStudent != NULL ) {
        cout << " " << TheStudent->name << " " << TheStudent->age << " " << TheStudent->gen << endl;
        TheStudent = TheStudent->NextStudent;
    }
 }
}

int main(){

     Display();
     int ans = 1;
     while ( ans == 1) {
        string name;
        int age;
        char gen;
        cout << " Enter Students Name: ";
        cin >> name;
        cout << " Enter Student Age: ";
        cin >> age;
        cout << " Enter Student Gender: ";
        cin >> gen;
        Insert(name,age,gen);
        cout << " Continue 1 -> YES 0 -> NO: ";
        cin >> ans;
     }
     Display();
    return 0;
}
