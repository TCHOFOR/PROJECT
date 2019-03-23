#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct Student{
  string name;
  int age;
  char gen;
};

int main(){
    vector<Student>stud(2);
    /*stud[0].name = "Enow";
    stud[0].age = 23;
    stud[0].gen = 'M';

    stud[1].name = "Good";
    stud[1].age = 18;
    stud[1].gen = 'F';*/
    for (int i = 0; i < stud.size(); i++){
        printf("\nEnter Name: ");
        cin >> stud[i].name;
        printf("\nEnter student age: ");
        scanf("%d",&stud[i].age);
        cin.ignore();
        printf("\nEnter student Gender: ");
        scanf("%c",&stud[i].gen);
    }

    for ( int i = 0; i < stud.size(); i++){
        cout << stud[i].name << " " << stud[i].age  << " " << stud[i].gen << endl;
    }


    cout << "Hello world!" << endl;


    return 0;
}
