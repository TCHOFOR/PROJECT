#include <iostream>
#include <vector>

using namespace std;

template <class s,class n, class g, class a>

class Student{
private:
    vector <s> surname;
    vector <n> name;
    vector <g> gen;
    vector <a> age;
public:
    Student(){}

    /*void ReadStudent(){
     cout << "Enter student surname: ";
    }*/

    void AddStudent(s surnames, n names, g genders, a ages ){
    surname.push_back(surnames);
    name.push_back(names);
    gen.push_back(genders);
    age.push_back(ages);
    }

    void DisplayStudent(){
     for ( int i = 0; i < name.size(); i++ ){
        cout << surname[i] << " " << name[i] << " " << age[i] << " " << gen[i] << endl;
     }
    }
};

int main(){

    Student < string, string ,string , int > stud;

    //stud.ReadStudent();
    stud.AddStudent("Enow","Good","Male",18);
   stud.DisplayStudent();


    cout << "Hello world!" << endl;
    return 0;
}
