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
  		string teacherName;
  public:
  	 Teacher teacher;
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
     	cout << "Enter Teacher Name: ";
     	cin >> teacherName;
     }
     void printSubject(Teacher teacher){
     	cout << name <<"\t"<< code <<"\t"<< teacher.getTeachName() <<endl;
     }
};

class Student{
private:
	string firstName,lastName,gender,dateOfBirth;
	int admisNumber;
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
};


 class StudentReport{
 private:
 	float mark1,mark2,avgMark;
 	Subject subj;
 	Student stud;
 public:
 	StudentReport(float mk1,float mk2){
 		mark1 = mk1;
 		mark2 = mk2;
 		avgMark = (mk1 + mk2)/2;
 	}
 	StudentReport(){
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
 	void showMarks( Student stud,Subject subj){
 		cout << "Subject: "<<subj.getSubjName()<< " Code: "<<subj.getSubjCode()<< " Teacher: "<<subj.teacher.getTeachName()<<endl;
 		cout <<stud.getName()<< " \t" << mark1 << " \t" << mark2 << "\t" << avgMark << endl;
 	}
 	/*void readMarks(Subject subj){
 	     cout << "Subject: " << subj.getSubjName() <<endl;
         cout << "Enter first Mark: ";
         cin >> mark1;
         cout << "Enter second Mark: ";
         cin >> mark2;
 	}*/
 	void readReport( Student stud,Subject subj){	
 	   cout << "Subject: " << subj.getSubjName() <<endl;	
 	   cout << "========================================" <<endl;	
	   cout << stud.getName() << " " << stud.getGender() <<endl;
	   cout << "--------------------------------------" <<endl;
       cout << "Enter first Mark: ";
       cin >> mark1;
       cout << "Enter second Mark: ";
       cin >> mark2;
       avgMark = (mark1+mark2)/20;
	}
 	void printReport(Subject subj,Student stud){
		stud.showStudent();
		cout << "_________________________________________________" << endl;
		cout << subj.getSubjName() <<"\t"<< teacher.getTeachName() <<"\t"<< mark1 << "\t";
		cout << mark2 <<"\t"<< avgMark <<endl; 
	}
 };

int main(){
	Teacher teach("Teacher");
	Subject subj("Subject","SUB203",teach);
	StudentReport report(0,0);
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
	report.readReport(stud,subj);
	cout << "***********SUBJECT AND TEACHERS**********************" <<endl;
	subj.printSubject(teach);
	cout << "\n\n";
	cout << "**********STUDENT AND MARKS**************************" << endl;
	report.printReport(subj,stud);
	cout << "\n\n";
	return 0;
}