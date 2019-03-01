class Subject:
	def __init__(self,name,code,teacher):
		self.name = name;
		self.code = code;
		self.teacher = teacher

	def Read(self):
	    name = input("Enter Subject Name: ")
	    code = input("Enter Subject Code: ")
	    teacher = input("Enter Teacher Name: ")

	def PrintTeacher(self):
	     print("Subject: ",self.name,"Code: ",self.code,"Teacher: ",self.teacher)   

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
	   self.dateOfBirth = input("Enter Student Date of Date: ")
	   self.matricule = int(input("Enter Student Matricule: "))

	def PrintStudent(self):
	   print("Name: ",self.firstName," ",self.lastName)
	   print("Gender:",self.gender)
	   print("Date Of Birth: ",self.dateOfBirth)
	   print("Enter Student Matricule: ",self.matricule)  

class Marks:
       #stud = Student("FirstName","LastName","Gender","01-January-19",0)
       #subj = Subject("Subject","Code","Teacher") 

    def __init__(self,mark1,mark2,avgMark):
           self.mark1 = mark1
           self.mark2 = mark2
           self.avgMark = self.mark1 + self.mark2

    def ReadMark(self):
  	   print("*****************************************************")
  	   print("Subject: ",subj.name,"Code: ",subj.code,"Teacher: ",subj.teacher)


 stud = Student("FirstName","LastName","Gender","01-January-19",0)
 subj = Student("Subject","Code","Teacher")

  stud.Read()
  stud.PrintStudent()

  subj.Read()
  subj.PrintStudent()	   

		