#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

//Global file declaration
 int in = 0;
 bool found;

//Worker base salaries
int base[4] ={ 150000,120000,100000,80000 };
//Worker base categories
char cate[4] = { 'A','B','C','D' };

char categ[4] ={ 'a','b','c','d' };

class Employee{
 private:
     //Workers Names  Declaration
     char surname[20],name[20];
     //Worker Gender Declaration
     char gender[9];
     //Worker Category Declaration
     char cat;
     //Worker Base Salary Declaration
     long double salary;
     //Worker Id
     short int id;

 public:
     static int nextId;
     Employee( double salary){
      this->salary = salary;
      cat = '\0';
      id = nextId++;
     }
    void setBaseSalary ( double base ) {
     salary = base;
    }
    double getSalary( double shared ) {
      return salary * shared;
    }
    int getnextId(){
       return nextId++;
    }
    void set_id( ){
      id = getnextId();
    }
    int get_id(){
     return id;
    }
    void add_employee()  {
     cin.ignore();
     cout << "Enter worker surname: ";
     cin.getline(surname,20);
     cout << "Enter worker given names: ";
     cin.getline(name,20);
     cout << "Enter worker gender: ";
     cin.getline(gender,8);
     cout << "Enter worker category: ";
     cin >>cat;
       for(int x = 0; x < 4; x++){
          if(cat == cate[x] || cat == categ[x] ){
             salary = base[x];
          }    // End of If
       }   // End of For
      cout << "Id : " << id << endl;
     }  // End of  Read Function

    void show_employee(){
       cout << "Name: " << surname << "\t" << name << "\t" <<endl;
       cout << "Gender: " << gender <<endl;
       cout << "Category: " << cat << "\t" << "Id: " << id <<endl;
       cout << "Salary: " << salary <<endl;
       }
    void display_employees(){
      cout << " " <<surname<< " " <<name<< " " <<gender<< " " <<cat<< " " <<id<< " " <<salary<<endl;
    }
};
int Employee:: nextId = 1;
    void write_employee(){
      Employee emp(50000);
       ofstream outfile;
       outfile.open("Employee.record",ios::binary | ios::out | ios::app);
       emp.add_employee();
       outfile.write(reinterpret_cast<char*>(&emp),sizeof(emp));
       outfile.close();
    }
    //View all employees in file
    void view_employees(){
      Employee emp(50000);
      ifstream infile;
      infile.open("Employee.record",ios::in | ios::binary);
      while(infile.read(reinterpret_cast<char*>(&emp),sizeof(emp))){
        emp.display_employees();
      }
      infile.close();
    }
    //Delete an Employeee
    void delete_employee( int id){
       found = false;
        Employee emp(50000);
        ifstream infile;
        infile.open("Employee.record",ios::binary | ios::in);
        ofstream outfile;
        outfile.open("Temp.record",ios::binary | ios::out);
        while(infile.read(reinterpret_cast<char*>(&emp),sizeof(emp)) && found == false){
          if( id != emp.get_id()){
              outfile.write(reinterpret_cast<char*>(&emp),sizeof(emp));
              found = true;
          }
        }
        remove("Employee.record");
        rename("Temp.record","Employee.record");
        infile.close();
        outfile.close();

        if( found == false){
          cout << "Could not find Record" <<endl;
        }
    }
    //modify /make changes to employee information 
    void modify_employee(int id){
      found = false;
       Employee emp(50000);
        fstream iofile;
        iofile.open("Employee.record",ios::binary | ios::in | ios::out );
        while(iofile.read(reinterpret_cast<char*>(&emp),sizeof(emp)) && found == false){
           if(id == emp.get_id()){
            emp.show_employee();
            cout << "\n\n" << "***************CHANGES*********************" << endl;
            emp.add_employee();
            int pos = -1 * sizeof(emp);
            iofile.seekp(pos,ios::cur);
            iofile.write(reinterpret_cast<char*>(&emp),sizeof(emp));
            found = true;
           }
        }
        iofile.close();
        if( found == false){
          cout << "Could not find Record" << endl;
        }
    }
//search for an employee
void search_employee( int id ){
       found = false;
       Employee emp(0.0);
       ifstream infile;
       infile.open("Employee.record",ios::binary | ios::in);
       while(infile.read(reinterpret_cast<char*>(&emp),sizeof(emp)) && found == false){
           if(id == emp.get_id()){
            emp.show_employee();
            found = true;
            //What to do to worker
            cout << "1. Change Information" << "\t" << "2. Delete Worker" << "\t" << "3. Back" <<endl;
            cout << "Ente Chioce: ";
            cin >>in;
            switch(in){
              case 1:
              modify_employee(id);
             break;
             case 2:
             delete_employee(id);
             break;
             case 3:
             //call main
             break; 
            }//end of switch
           }//end of if
       }
       infile.close();
       if(found == false)
        cout << "Could not find record" <<endl;
    }   

class Article{
  protected:
    char article_name[20],article_type[20],quantity_name[20];
    float quantity;
    float price1;
  public:
    Article(float quan,float price){
      quantity = quan;
      price1 = price;
    }
    Article( ){
      quantity = 0.0;
      price1 = 0.0;
    }
    char* getarticle_name(){
      return article_name;
    }
    char* getarticle_type(){
      return article_type;
    }
    char* getquantity_name(){
      return quantity_name;
    }
    void setquantity( float quan){
      quantity = quan;
    }
    float getquantity(void){
     return quantity;
    }
    void setprice(float price){
      price1 = price;
    }
    float getprice(void){
      return price1;
    }
    void read_article(){
      cin.ignore();
      cout << "Enter Article Name: ";
      cin.getline(article_name,20);
      cout << "Enter Article Type: ";
      cin.getline(article_type,20);
      cout << "Enter Quantity: ";
      cin >>quantity;
      cin.ignore();
      cout << "Enter Quantity Name: ";
      cin.getline(quantity_name,20);
      cout << "Enter Price for One: ";
      cin >> price1;
      cin.ignore();
    }
  //Showing a single article  
 void show_article(){
   cout << "Article: "<< article_name << "\t" << "Type: " << article_type << endl;
   cout << "Quantity: " << quantity << "\t" << "Name: " << quantity_name << endl;
   cout << "Price For One: " << price1 << endl;
 }
 //Display All Articles
  void display_articles(){
   cout <<article_name<< " " <<article_type<< " " <<quantity<< " " <<quantity_name<< " " <<price1<<endl;
  }
};

//writing articles into file

void write_article(){
  Article art(-1,-1);
  ofstream outfile;
  outfile.open("Article.record",ios::binary | ios::out | ios::app);
  art.read_article();
  outfile.write(reinterpret_cast<char*>(&art),sizeof(art));
  outfile.close();
}
void view_articles(){
      Article article(-1,-1);
      ifstream infile;
      infile.open("Article.record",ios::in | ios::binary);
      while(infile.read(reinterpret_cast<char*>(&article),sizeof(article))){
        article.display_articles();
      }
      infile.close();
}

// Modify Articles
void modify_articles(){
  Article article(-1,-1);
  char artname[20];
  found = false;
  cout << "Enter Article Name: ";
  cin.getline(artname,20);
  fstream iofile;
  iofile.open("Article.record",ios::binary | ios::out | ios::in);
  while(iofile.read(reinterpret_cast<char*>(&article),sizeof(article)) && found == false){
     if( strcmp(artname,article.getarticle_name()) == 0){
       article.show_article();
       cout << "********************CHANGES*********************" <<endl;
       article.read_article();
       int pos = -1*sizeof(article);
       iofile.seekp(pos,ios::cur);
       iofile.write(reinterpret_cast<char*>(&article),sizeof(article));
       found = true;
     }
  }
  iofile.close();
  if( found == false){
    cout << "Could Not find Article" << endl;
  }
}

//function to delete article records

void delete_article(){
  Article article(-1,-1);
  found = false;
  ifstream infile;
  infile.open("Article.record",ios::binary | ios:: in);
  ofstream outfile;
  outfile.open("Temp.record",ios::binary | ios::out);
  char artname[20];
  cout << "Enter Article Name: ";
  cin.getline(artname,20);
  while(infile.read(reinterpret_cast<char*>(&article),sizeof(article)) && found == false){
    if(strcmp(artname,article.getarticle_name()) != 0){
      outfile.write(reinterpret_cast<char*>(&article),sizeof(article));
      found = true;
    }
  }
  rename("Temp.record","Article.record");
  remove("Temp.record");
  infile.close();
  outfile.close();
}

// search for articles

void Search_article(){
  Article article(-1,-1);
  cin.ignore();
  char artname[20];
  cout << "Enter Article Name: ";
  cin.getline(artname,20);
  ifstream infile;
  infile.open("Article.record",ios::binary| ios::in);
  found = false;
  while(infile.read(reinterpret_cast<char*>(&article),sizeof(article)) && found == false){
    if(strcmp(artname, article.getarticle_name()) == 0){
      article.show_article();
      found = true;
     //what to do
     while( in != 3){
     cout << "1. Change Information" << "\t" << "2. Delete Article" << "\t" << "3. Back" << endl;
     cout << "Enter: ";
     cin >> in;
     switch(in){
        case 1:
        cin.ignore();
        modify_articles();
        break;
        case 2:
        cin.ignore();
        delete_article();
        break;
     }//end of switch
   }
    }//end of of
  }//end of while
  infile.close();
  if( found == false){
    cout << "Article not Found" << endl;
  }
}


//Customer Classs

class Customer{
private:
  char customer_name[20];
public:
void read_customer_name(){
  cin.ignore();
  cout << "Enter Customer's Name: ";
  cin.getline(customer_name,20);
  }
  char* getCustomerName(void){
    return customer_name;
  }
void show_customer(){
  cout << "Customer Name: " << customer_name <<endl;
}  
};

//customer's articles class
 class CustomerArticles: public Article{
   private:
     float amount;
     float total_amount;
   public:
    CustomerArticles(float quan,float price):Article(quan,price){
    amount = 1;
    total_amount = 1;
   }
  void setAmount(float amount){
    this->amount = amount;
  }
  float getAmount(void){
    return amount;
  }
  void setTotalAmount(int total){
    total_amount+=total;
  }
  float getTotalAmount(void){
    return total_amount;
  }
  void put_article( ){
    Article art(1,1);
    cout << "Enter Article Name: ";
    cin.getline(article_name,20);
    cout << "Enter Article Type: ";
    cin.getline(article_type,20);
    cout << "Enter Quantity Demanded: ";
    cin>> quantity;
  } //End of Function
 };


 void writing_customer_Items(){
  Customer customer;
  CustomerArticles custArt(1,1);
  Article art(1,1);
  customer.read_customer_name();
  cout << "\n\n";
  cout << "*****************ADD ARTICLE************************" <<endl;
  custArt.put_article();
  int seen = 0;
  fstream iofile;
  iofile.open("Article.record",ios::binary | ios::in | ios::out);
  while(iofile.read(reinterpret_cast<char*>(&art),sizeof(art)) && seen == 0){
    if(strcmp(art.getarticle_name(),custArt.getarticle_name()) == 0){
      if(strcmp(art.getarticle_type(),custArt.getarticle_type()) == 0){
        art.show_article();
        //custArt.setAmount(art.getprice()*custArt.getquantity()); 
        //custArt.setTotalAmount(custArt.getAmount());
        seen = 1;
        break;
      }else{
        continue;
      }//end of else
    }else{
      cout << "Type not found" <<endl;
    }
   }//end of while

  iofile.write(reinterpret_cast<char*>(&art),sizeof(art));
  iofile.close();

   if(seen == 0)
    cout << "Not found" <<endl;
 }//end of function write customer

 void print(){
   Customer customer;
   customer.show_customer();
 } 


//The Main Function
int main(){
    char ch = '\0';
    int id = 0;
    do{
    //system("cls");
    cout << "\t\t" << "WORKER" << "\t\t" << "ARTICLE" << "\t\t" << "CUSTOMER" << "\t\t" << "Exit" << endl;
    cout <<"\n\n";
    cout <<"Enter: ( W , A , C or E ): " ;
    cin >> ch;
    ch = toupper(ch);
    switch(ch){
    case 'W':
         in = 0;
         while( in!= 4){
        cout <<  "*****************EMPLOYEE*****************************" <<endl;
        cout << "1. Add Employee" <<endl;
        cout << "2. Search Employee" <<endl;
        cout << "3. Display All Employees" <<endl;
        cout << "4. Back" <<endl;
        cout << "Enter chioce: ";
        cin >> in;
        switch(in){
          case 1:
          write_employee();
          break;

          case 2:
          cout << "Enter Employee Id: ";
          cin >>id;
          search_employee(id);
          break;

          case 3:
          cout << "****************ARTICLE LIST************************" <<endl;
          cout << "====================================================" <<endl;
          view_employees();
          break;  
        }
      }
        break;

    //Article page
    case 'A':
      in = 0;
      do{
      cout << "*******************ARTICLE******************************" <<endl;
      cout << "1. Add Article" <<endl;
      cout << "2. Search Article" <<endl;
      cout << "3. Display all Articles" <<endl;
      cout << "4. Back" <<endl;
      cout << "Enter chioce: ";
      cin >> in;
      switch(in){
           case 1:
           write_article();
           break;
           case 2:
           Search_article();
           break;
           case 3:
           view_articles();
           break;
      }//end of switch
    }while(in != 4);
      break;

//customers page
      case 'C':
         writing_customer_Items();
         cout << "-------------------------------------------------" <<endl;
         print();
      break;
    }//end of main switch
    }while(ch != 'E');
    return 0;
}



