#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;

int base[4] ={ 150000,120000,100000,80000 };
char cate[4] = { 'A','B','C','D' };
char categ[4] ={ 'a','b','c','d' };


class Date{
 private:
     int day,month,year;
 public:
    /*Date( int d,int m,int y) {
     day = d;
     month = m;
     year = y;
    }*/
    friend class Worker;
  void setDay( int dy ) {
   day = dy;
  }
  int getDay(void) {
   return day;
  }
  void setMonth ( int mn ) {
   month = mn;
  }
  int getMonth ( void ) {
   return month;
  }
  int setYear( int yr ) {
   year = yr;
  }
  int getYear ( void ) {
   return year;
  }
};


class Worker{
 private:
     //Workers Names  Declaration
     string surname,name;
     //Worker Gender Declaration
     string gen;
     //Worker Category Declaration
     char cat;
     //Worker Base Salary Declaration
     long double salary;
     //Class of Worker Date of Employment

     Date date;

 public:
     Worker(){
      surname = name = " Unnamed";
      gen = " Unspecified ";
      cat = ' ';
      salary = 0.0;
     }
    void setName( string fname, string sname) {
       surname = fname;
       name = sname;
    }
    void setFname ( string fname ) {
       surname = fname;
    }
    void setLname( string lname ) {
      name = lname;
    }
    string getFname( void ) {
      return surname;
    }
    string getLname ( void ) {
      return name;
    }
    string getName( void  ){
      return surname +" "+ name;
    }
    void setGen( string g ) {
      gen = g;
    }
    string getGender ( void ) {
     return gen;
    }
    char getCat ( void ){
      return cat;
    }
    void setBaseSalary ( double base ) {
     salary = base;
    }
    void setCat ( char cat ) {
      this->cat = cat;
    }
    double getSalary( double &amountshared ){
      return amountshared * salary;
    }
    double getGrossPay( int hours ){
       return salary * hours;
    }
    void ReadWorker( void );
    void WriteWorker( void );
    void DisplayWorker( void );
    void EditWorker( void );
    void DeleteWorker( string name1,string name2);
    void PaySalary();
};
//Reading Worker Information
void Worker::ReadWorker(){
    cin.ignore();
 cout << "Enter worker surname: ";
 getline (cin,surname);
 cout << "Enter worker given names: ";
 getline(cin,name);
 cout << "Enter worker gender: ";
 cin >>gen;
 cout << "Enter worker category: ";
 cin >>cat;
 cout << "Enter Date Employed ( dd mm yy ):";
 cin>> date.day >> date.month >> date.year;
 for(int x=0; x<4; x++){
      if(cat == cate[x] || cat == categ[x]){
        salary=base[x];
      }
 }
}


//Displaying worker information
void Worker::DisplayWorker(){
  cout << "Worker Name: " << surname << " " << name << endl;
  cout << "Gender: " << gen <<endl;
  cout << "Date Employed: " << date.getDay() <<" / " << date.getMonth() << " /" << date.getYear() <<endl;
  cout << "Category: " << cat << endl;
  cout << "Salary: "<< salary << endl;
}
//deleting worker from database
void Worker::DeleteWorker( string name1,string name2) {

  string name = name1 + " " + name2;

    ofstream owork.open("Worker.record",ios::out | ios::binary );
    ifstream iwork.open("TempWorker.record",ios::in | ios::binary );
    Worker w;
    while ( iwork.read(reinterpret_cast < char * > (this)&w,sizeof(w)){
       if ( w.getFname() != name1 && w.getLname() !=name2 ) {
    /*setName(" "," ");
    setGen(" ");
    setBaseSalary(0.0);
    setCat('\0');
    date.setDay(0);
    date.setMonth(0);
    date.setYear(0);*/
    w.DisplayWorker();
    owork.write(reinterpret_cast< char
  }
   }
   owork.close();
   iwork.close();
   remove("Worker.record");
   rename("TempWorker.record","Worker.record");
}


class Article{
protected:
  string Articlename;
  string QuantityName;
  double Price1;
  double Quantity;
public:
    Article(){
       Articlename = QuantityName = " ";
       Price1 = 0.0;
       Quantity = 0.0;
    }
    void setArticleName( string Article ){
        Articlename = Article;
    }
    string getArticle(){
      return Articlename;
    }
    void setQuantityName( string QuantityName ){
      this->QuantityName = QuantityName;
    }
    string getQuanName(){
      return QuantityName;
    }
    void setQuantity( double Quantity ){
       this->Quantity = Quantity;
    }
    double getQuantity(){
       return Quantity;
    }
    void setPrice1( double price1 ){
      this->Price1 = price1;
    }
    double getPrice(){
      return Price1;
    }
    void ReadArticle();
    void DisplayArticle();
    void EditArticle( );
    void Delete_Article(string ArtName);
};

void Article::DisplayArticle(){
 cout << " " << Articlename << " " << Quantity << " " << QuantityName << " " << Price1 << endl;
}

void Article::ReadArticle(){
  cout << "Enter article name: ";
  cin >> Articlename;
  cout << "Enter quantity: ";
  cin >> Quantity;
  cout << "Enter quantity name: ";
  cin >>QuantityName;
  cout << "Enter price for one: ";
  cin >> Price1;
}
void Article::EditArticle() {
     string article;
      double quan = 0;
      double pric = 0.0;
      cout << "Enter Article Name: ";
      cin >>article;
      cout << "Enter Quantity: ";
      cin >> quan;
      cout << "Enter Price for One: ";
      cin >>pric;
      setArticleName( article );
      setQuantity( quan );
      setPrice1( pric );

}
void Article::Delete_Article(string ArtName) {
    if ( getArticle() == ArtName) {
        setArticleName(" ");
        setQuantity(0);
        setQuantityName(" ");
        setPrice1(0);
    }

}

class Customer : public Article{
 private:
     string name;
     double amount;
     double TotalAmount;
     int NumberOfItems;
 public:
  Customer():
      Article(){
      name = " ";
      amount = 0.0;
      TotalAmount = 0.0;
      NumberOfItems = 0;
  }
  string getCustomerName(){
    cout << "Enter customer name: ";
    getline(cin,name);
    return name;
  }
  void ReadCustomer(Article& Art);
  void PrintReciept();
};

void Customer::ReadCustomer( Article& Art ){
  cout << "\n\n" << "      CUSTOMER'S BILL          " <<endl;
  double sum=0.0;
  cin.ignore();
  getCustomerName();   //Getting customer's name from user

   int ans = 1;
    while( ans != 0 ){
    cout << "\n\n" << "*********Customer Article List**********" << endl;
    cout << "\n\n" << "Enter article  bought name: ";
    getline(cin,Articlename);

    if( Articlename != Art.getArticle() ){
         cout << "Article not found in stock.";
    }//end of first if
    else {
        cout << "Enter quantity demanded by customer: ";
        cin >>Quantity;
        cout << "Enter quantity name: ";
        cin >>QuantityName;
        double quan = Art.getQuantity();                    //Assign Quantity to a quantity variable
        amount = Art.getPrice() * Quantity ;               //Calculating the amount of customer items
        quan =( quan - Quantity );                        //Subtracting Quantity bought by customer from quantity in stock
        Art.setQuantity(quan);                           //setting  quantity of items
        sum += amount;                                  //Calculating the Total amount of items
        Art.setQuantity(quan);
   }//end of else
       cout << "Enter 1 to continue or 0 to stop: ";
       cin >>ans;
 }
  TotalAmount = sum;
}
//Printing Customer Receipt
void Customer::PrintReciept(){
 cout << "\n\n\n" << endl;
 cout << "          CUSTOMER RECIEPT            "  << "\n\n\n";
 cout << "CUSTOMER NAME:" << name << endl;
 cout << " " << " ARTICLE" << " " << "QUANTITY" << "    " <<  "AMOUNT" <<endl;
 cout << " " << " -------------------------------------------" <<endl;
 cout << Articlename << "    " << Quantity << "    " << QuantityName << "   " << amount << " FCFA" << endl;
 cout << "\n\n" << "                         TOTALAMOUNT:" << TotalAmount << "FCFA" << endl;
}


void Main_Worker ( Worker& Work );
void Main_Article ( Article& Art);

int main(){
    Worker Worker;
    Article *Articles = new Article;
    Article Article;
    Customer Cust;

     char ch='\0';

    cout << "           ABAS COMPANY LIMITED          " << endl;

    do{
    cout << "        WORKER " <<endl;
    cout << "        ARTICLE " <<endl;
    cout << "        CUSTOMER " <<endl;
    cout << "        EXIT" <<endl;
    cout << "        Enter first character to chose: ";
    cin >>ch;

    switch(ch){
 case 'W':
 case 'w':
     Main_Worker( Worker );
     break;
 case 'A':
 case 'a':
    Main_Article( Article );
    break;
 case 'C':
 case 'c':
    Cust.ReadCustomer( Article );
    Cust.PrintReciept();
    break;
  /*default:
    cout << "INVALID COMMAND" << endl; */
    }
 }while( ch != 'x' || ch != 'X' );

}

void Main_Worker( Worker& Work  ){

    char in = '\0';
     cout << "       ABAS WORKERS       " << "\n\n";
     cout << " Add Worker." <<endl;
     cout << " Show Workers." <<endl;
     cout << " Pay Salary." <<endl;
     cout << " Edit Worker." <<endl;
     cout << " Delete Worker." <<endl;
     cout << " Back." <<endl;
     cout << "Enter: " ;
     cin >> in;
    switch ( in ) {
    case 'A':
    case 'a':
        try{
        ofstream outwork.open("Worker.record",ios::app | ios::out | ios::binary);
        Work.ReadWorker();
        outworker.write(reinterpret_cast< char * >(this)&Work,sizeof(Work));
        outworker.close();
        }
        catch(exception& e) {
        cout << "An Error Occurred We Will Fix It. Check Later" << endl;
        }
        break;
    case 'S':
    case 's':
        ifstream inworker.open("Worker.record", ios::in | ios::binary );
        while ( inworker ){
        inworker.read(reinterpret_cast< char * > (this)&stud,sizeof(stud));
        Work.DisplayWorker();
        }
        inworker.close();
        break;
    case 'P':
    case 'p':
      int NumberOfWorkers = 2;
      cout << " " << "       WORKERS PAYMENTS      " <<endl;
      float profit = 0.0;
      cout << "Enter Profit Made By Company: ";
      cin >>profit;
      double share = 1; // Amount to be Distributed to all workers
      if ( profit != 0){
         float amount = (profit * 30) / 100;
         share = amount / NumberOfWorkers;
      }
      cout << "  WORKER      " << "  " << " CATEGORY " << "  " << " AMOUNT TO RECIEVE " << endl;
      cout << " -----------------------------------------------" << endl;
       fstream ioworker.open("Worker.record",ios::in | ios::out | ios::binary);
       while ( ioworker ) {
       ioworker.read(reinterpret_cast < char * >(this)&stud, sizeof(stud));
       cout << Work.getName() << " " << Work.getCat() << " " << Work.getSalary( share ) << endl;
       }
       ioworker.close();
        break;
   case 'B':
    case 'b':
        string fname,sname;
        cout << "Enter Worker First Name: ";
        cin >> fname;
        cout << "Enter Worker Second Name: ";
        cin >>sname;
        iowork.open("Worker.record",ios::out | ios::in | ios::binary );
        while ( iowork ) {
        if ( fname == Work.getFname() && sname == Work.getLname() ){
        Work.DisplayWorker();
        }
        }
        Work.DeleteWorker(fname,sname);
        break;
    /*case 'B':
    case 'b':
        //exit(1);
        break;*/
     }
}

void Main_Article( Article& Art ) {
  char en = '\0';
     cout << "       ABAS ARTICLES       " << "\n\n";
     cout << " Add Article." <<endl;
     cout << " Show Articles." <<endl;
     cout << " Edit Articles." <<endl;
     cout << " Delete Articles." <<endl;
     cout << " Back." <<endl;
     cout << "Enter: " ;
     cin >> en;
    switch ( en ) {
    case 'A':
    case 'a':
        try{
        Art.ReadArticle();
        }
        catch(exception& e ) {
        cout << "Sorry We can't Read Information Now" << endl;
        }
        break;
    case 'S':
    case 's':
       try{
        Art.DisplayArticle();
        }catch ( exception& e){
         cout << "Sorry We Could Not Open This File" << endl;
        }
        break;
    case 'E':
    case 'e':
        try{
        Art.EditArticle( );
        }
        catch( exception& e){
         cout << " This Program Have a Problem" <<endl;
        }
      break;
    case 'D':
    case 'd':
        try{
        cout << "Enter Article You Want To Delete : ";
        string Article;
        cin>>Article;
        Art.DisplayArticle();
        cout << "\n" << " Deleted";
        Art.Delete_Article(Article);
        }
        catch( exception& e) {
         cout << "Sorry Problem Encountered We Will Notify You Later" << endl;
        }
        break;
/*    case 'B':
    case 'b':
        //exit(1);
        break;*/
     }
}




