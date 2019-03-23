#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

class Date{
 protected:
     int day,month,year;
 public:
    Date (  ) {
     day = 0;
     month = 0;
     year = 0;
    }
    Date ( int d, int m , int y ){
     day = d;
     month = m;
     year = y;
    }
    friend class Student;
};

class Student {
  protected:
      string surname,name;
      string gen;
  //Student Marks
    double mark1,mark2;
    double mark3,mark4;
    double mark5,mark6;
    double avgmark1,avgmark2,avgmark3;
 //Student Date Of  Birth
  Date date;
  public:
    Student(){
     surname = name = " ";
     gen = " ";

   mark1 = mark2 = mark3 = mark4 = mark5 = mark6 = 0.0;
   avgmark1 = avgmark2 = avgmark3 = 0.0;
  }
  void setName (string surname,string name){
   this->surname = surname;
   this->name = name;
  }
  string getName(){
   return surname + " " +name;
  }
  void setGender(string gen){
    this->gen = gen;
  }
  string getGender(){
    return gen;
  }

  void Read_Student();

};

class Teacher: public Student{
private:
    string subject;
    int NumberOfStudent;
public:
    Teacher(){
     subject = " ";
     NumberOfStudent = 1;
    }
    void setSubject(string subject){
     this->subject = subject;
    }
    void setNumber( int num){
     NumberOfStudent = num;
    }
    int getNumber(){
     return NumberOfStudent;
    }
   void Read_Teacher();
   void Reading_Student_Marks();
};

int main(){

    cout << "              ******** TEACHER REPORT SHEET**************             " << endl;

    Teacher *Teaches = new Teacher();
    Teacher Teach;
    Student Stud;
    cout << "****************CLASS REPORT SHEET*******************" << endl;
    ofstream Oteacher;
    Oteacher.open ( "Teacher.record" , ios::out | ios::app | ios::binary );
     Teaches = &Teach;
     Teaches->Read_Teacher();
     Oteacher.write(reinterpret_cast < char *>(&Teach) , sizeof(Teach));
     Oteacher.close();
     //cin.ignore('\n');
     cout << "  *************STUDENT REPORT INFORMATION ***************************" << endl;
     ofstream Ostudent;
     Ostudent.open("Student.record", ios::out | ios::app | ios::binary);
     //Teaches = &Stud;
     //Teaches->Read_Student();
     Stud.Read_Student();
     Ostudent.write(reinterpret_cast < char * > (&Stud), sizeof(Stud) );
     Ostudent.close();
    return 0;
}
void Teacher::Read_Teacher(){
 cout << "Enter teacher Name: ";
 getline(cin,name);
 cout << "Enter the Subject thought by the Teacher: ";
 getline(cin,subject);
 cout << "Enter Number of Student doing Subject: ";
 cin >>NumberOfStudent;
}
void Student::Read_Student(){
cout << "Enter Student Surname: ";
cin>>surname;
cout << "Enter Student Given Names: ";
cin>>name;
cout << "Enter Student Gender: ";
cin>>gen;
cout << "Enter student Date of Birth  ( DD MM YY ): ";
cin >> date.day >> date.month >> date.year;
}

void Teacher::Reading_Student_Marks(){
  cout << " ***************Student Marks************* " <<endl;
  cout << "Student Name: " << getName();
  cout << "     Gender:  " << getGender();
  cout << "\n" << "First Sequence Marks: ";
  cin >> mark1;
  cout << "\n" << "Second Sequence Marks: ";
  cin >> mark2;
}
