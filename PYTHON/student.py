class Teacher:
	def __init__(self, name,dateEmployed):
		self.name = name
		self.dateEmployed = dateEmployed
	def Read(self):
	   name = input("Enter Teacher Name: ")
	   dateEmployed = input("Date Employed: ")	 
	def PrintTeacher(self):
	   print("Name: ",self.name," Date Employed: ",self.dateEmployed)	

class Subject:
	teacher = Teacher("Chefor","24-march-26")
	def __init__(self,name,code,teacher):
		self.name = name;
		self.code = code;
		self.teacher = teacher;
	def Read(self,teacher):
	    name = input("Enter Subject Name: ")
	    code = input("Enter Subject Code: ")
	    print("Teacher is ",teacher.name);
	def PrintSubject(self):
	     print("Subject: ",self.name,"Code: ",self.code,"Teacher: ",teacher.name)  	      

class Student:
	def __init__(self,firstName,lastName,gender,dateOfBirth,matricule):
		    self.firstName = firstName
		    self.lastName = lastName
		    self.gender = gender
		    self.dateOfBirth = dateOfBirth
		    self.matricule = matricule

	def Read(self):
	   self.firstName = input("Enter Student First Name: ")
	   self.lastName = input("Enter Student Last Name: ")
	   self.gender = input("Enter Gender: ")
	   self.dateOfBirth = input("Enter Student Date of Date: ")
	   self.matricule = int(input("Enter Student Matricule: "))

	def PrintStudent(self):
	   print("Name: ",self.firstName," ",self.lastName)
	   print("Gender:",self.gender)
	   print("Date Of Birth: ",self.dateOfBirth)
	   print("Matricule: ",self.matricule) 
#Student mark classs	   
class Marks:
    stud = Student("FirstName","LastName","Gender","01-January-19",0)
    subj = Subject("Subject","Code",teacher) 

    def __init__(self,mark1,mark2,avgMark):
           self.mark1 = mark1
           self.mark2 = mark2
           self.avgMark = (self.mark1 + self.mark2) / 2

    def ReadMark(self,subj,stud):
  	   print("****************************SUBJECT**************************")
  	   print("Subject: ",subj.name,"Code: ",subj.code,"Teacher: ",subj.teacher.name)	
  	   print("==============================================================")
  	   print("*************************STUDENT******************************")
  	   print(stud.firstName," ",stud.lastName," ",stud.gender)
  	   print("--------------------------------------------------------------")
  	   self.mark1 = float(input("Enter Firs Sequence Mark: "))
  	   self.mark2 = float(input("Enter Second Sequence Mark: "))
  	   self.avgMark = (self.mark1 + self.mark2)/2;

    def PrintStudentReport(self):
       #print("\n\n***********************STUDENT REPORT***********************")	
  	   print(stud.firstName," ",stud.lastName,"Date of Birth: ",stud.dateOfBirth)
  	   print(stud.gender)
  	   print("Matricule: ",stud.matricule)
  	   print("---------------------------------------------------------------")
  	   print("===============================================================")
  	   print(subj.name," ",subj.teacher.name," ",subj.code,"  ",self.mark1,"  ",self.mark2," ",self.avgMark)


#Creating Teacher Object
teacher = Teacher("Chefor","24-03-29")
#Reading teachers information
teacher.Read()
#Printing Teachers Information
print("*********************TEACHER*********************")
teacher.PrintTeacher()

#Creating subject Object
subj = Subject("Subject","Code",teacher)
#Reading the subject information
subj.Read()
#Printing the subjects
subj.PrintSubject()	 
#Creating Student Object
stud = Student("FirstName","LastName","Gender","01-January-19",1)
#Reading students Information
stud.Read()
#print Students Information
stud.PrintStudent()

#Marks object
mark = Marks(1,1,0)  
#Reading Students marks
mark.ReadMark()
#Printing students Reports
print("\n\n***********************STUDENT REPORT*********************")
mark.PrintStudentReport()

		