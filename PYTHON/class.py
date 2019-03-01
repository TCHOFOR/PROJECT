class Student:
	studCount = 0;
	def __init__(self,name,age,gender,studClass):
		self.name = name
		self.age = age
		self.gender = gender
		self.studClass = studClass
		Student.studCount+=1;
	def Print(self):
	  print("Name: ",self.name,"Age: ",self.age,"Gender: ",self.gender,"Class: ",self.studClass)
	def numberOfStudents(self):
	   print("Number of Students: ",Student.studCount)
	def Read(self):
		self.name = input("Enter Student Name: ")
		self.age = int(input("Enter Student Age: "))
		self.gender = input("Enter Student Gender: ")
		self.studClass = input("Enter Student Class: ")
	   	   

stud = Student("Che Bruno",23,"Male","Form 5")
#stud2 = Student("Enow Good",21,"Female","Form 3")
#stud3 = Student("Frank Delano",20,"Male","Form 1")
stud.Read()
infile = open("Student.record","wb")
infile.write(stud)
infile.close()
outfile = open("Student.record","rb")
#stud1.Print()  
#stud2.Print()
stud.Print()
outfile.close()

print("Total Number of Students = ",Student.studCount)
