#include <iostream>
#include <string>

using namespace std;

class Teacher{
private:
	string name;
public:
	Teacher(string teachName){
		name = teachName;
	}
	Teacher( ){
		name = " ";
	}
	void setTeachName(string teachName){
		name = teachName;
	}
	string getTeachName(void){
		return name;
	}
	void readTeacher( ){
		cout << "Enter teacher name: ";
		getline(cin,name);
	}
	void printTeacher(){
		cout << "Name: " << name;
	}
};

class Subject{
  private:
  		string name,code;
  		Teacher teacher;
  public:
     Subject( string subjName,string subjCode,Teacher teacher ){
     	name = subjName;
     	code = subjCode;
     	this->teacher = teacher;
     }	
     Subject(){
     	name = "Student Name";
     	code = "Subject Code";
     	this->teacher = teacher;
     }	
     string getSubjName(void){
     	return name;
     }
     string getSubjCode(void){
     	return code;
     }
     void readSubject(){
     	cout << "Enter Subject: ";
     	getline(cin,name);
     	cout << "Enter Code: ";
     	getline(cin,code);
     }
     void printSubject(Teacher teacher){
     	cout << name <<"\t"<< code <<"\t"<< teacher.getTeachName() <<endl;
     }
};

 class Marks{
 private:
 	float mark1,mark2,avgMark;
 	Subject subj;
 	Teacher teacher;
 public:
 	Marks(float mk1,float mk2){
 		mark1 = mk1;
 		mark2 = mk2;
 		avgMark = (mk1 + mk2)/2;
 	}
 	Marks(){
 		mark1 = 0.0;
 		mark2 = 0.0;
 		if( mark1==0 || mark2==0){
 			avgMark = 0;
 		}else{
 			 avgMark = (mark1 + mark2)/2;
         }
    }     
 	float getMark1(void){
 		return mark1;
 	}
 	float getMark2(void){
 		return mark2;
 	}
 	float getAverageMark(void){
 		return avgMark;
 	}
 	void readMarks(Subject subj){
 	     cout << "Subject: " << subj.getSubjName() <<endl;
         cout << "Enter first Mark: ";
         cin >> mark1;
         cout << "Enter second Mark: ";
         cin >> mark2;
 	}
 };

class Student{
private:
	string firstName,lastName,gender,dateOfBirth;
	int admisNumber;
protected:
	Teacher teacher;
	Marks mark;
	Subject subj;
public:
	Student(string fname,string lname,string gen,string DoB,int number){
         firstName = fname;
         lastName = lname;
         gender = gen;
         dateOfBirth = DoB;
         admisNumber = number;
	}
	Student(){
		firstName = "First Name";
		lastName = "Last Name";
		gender = "Gender";
		dateOfBirth = "01-January-19";
		admisNumber = 0;
	}
	string getName(void){
		return firstName+" "+lastName;
	}
	string getGender(void){
		return gender;
	}
	string getDatofBirth(void){
		return dateOfBirth;
	}
	int getAdminNumber(void){
		return admisNumber;
	}
	void studentInfo(){
		//cin.ignore();
		cout << "Enter First Name: ";
		getline(cin,firstName);
		cout << "Enter Last Name: ";
		getline(cin,lastName);
		cout << "Enter Gender: ";
		getline(cin,gender);
		cout << "Enter Date Of Birth: ";
		getline(cin,dateOfBirth);
		cout << "Enter Admission Number: ";
		cin >> admisNumber;
	}
	void showStudent(){
		cout << "Name: " << getName() <<"\t"<< "Gender: " << gender <<endl;
		cout << "Date of Birth: " << dateOfBirth <<"\t"<< "Admission Number: "<< admisNumber <<endl;
	}
	void printStudent(){
         cout << getName() <<"\t"<< gender <<"\t"<< dateOfBirth <<"\t"<< admisNumber << endl;
	}
	void readReport( Marks mark,Subject subj){	
	  cout << getName() << " " << getGender() <<endl;
	  mark.readMarks(subj);
	}
	void printReport(Subject subj,Teacher teacher,Marks mark){
		showStudent();
		cout << subj.getSubjName() <<"\t"<< teacher.getTeachName() <<"\t"<< mark.getMark1() << "\t";
		cout << mark.getMark2() <<"\t"<<mark.getAverageMark() <<endl; 
	}
};

int main(){
	Teacher teach("Teacher");
	Subject subj("Subject","SUB203",teach);
	Marks mark(0,0);
	Student stud("Student","Stude","Male","24-March-19",32552);
	cout << "*************TEACHER INFORMATION********************"<<endl;
	teach.readTeacher();
	cout <<"\n\n";
	cout << "******************SUBJECT INFORMATION*****************" <<endl;
	subj.readSubject();
	cout <<"\n\n";
	cout << "**************STUDENT INFORMATION*********************" <<endl;
	stud.studentInfo();
	cout <<"\n\n";
	stud.readReport(mark,subj);
	cout << "***********SUBJECT AND TEACHERS**********************" <<endl;
	subj.printSubject(teach);
	cout << "\n\n";
	cout << "**********STUDENT AND MARKS**************************" << endl;
	stud.printReport(subj,teach,mark);
	cout << "\n\n";
	return 0;
}