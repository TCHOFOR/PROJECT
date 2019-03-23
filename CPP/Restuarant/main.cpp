#include <iostream>
#include <vector>
#include <string.h>
#include <string>
//#include <conio.h>

using namespace std;

class Restuarant{
  private:
      int totalAmountSold;
      string address;
      string email;
  protected:
     string name;
  public:
    Restuarant(string restoName,string restoAddress,string restoEmail,int amountSold){
      name = restoName;
      address = restoAddress;
      email = restoEmail;
      totalAmountSold = amountSold;
    }
    Restuarant(const Restuarant &Resto){
        name = Resto.name;
        address = Resto.address;
        email = Resto.email;
    }
    Restuarant( ){
      name = "Restaurant";
      address = "No Address";
      email = " No Email";
    }
    void setName( string restoName){
      name = restoName;
    }
    string getName(void){
      return name;
    }
    void setAddress(string restoAddress){
      address = restoAddress;
    }
    string getAddress(void){
       return address;
    }
    void setEmail(string restoEmail){
      email = restoEmail;
    }
    void addAmountSold(int amount){
      totalAmountSold +=amount;
    }
    int getTotalAmountSold(void){
      return totalAmountSold;
    }
};

class Menu{
  protected:
     string name;
     float price;
     int maximumPlate;
     int numberOfPlates;
  public:
      Restuarant Resto;
    Menu(string menuName,int menuPrice,int maxPlate,int numPlate){
     name = menuName;
     price = menuPrice;
     maximumPlate = maxPlate;
     numberOfPlates = numPlate;
    }
    Menu(){
     name = "";
     price = 2000;
     maximumPlate = 0;
     numberOfPlates = 0;
    }
    int addNumberOfPlates(int number){
      if(number > maximumPlate){
        cout << "Exceed maximum number!!!";
       return -1;
      }
      numberOfPlates+=number;
    }
    void setName(string menuName){
      name = menuName;
    }
    string getName(void){
      return name;
    }
    void add_or_reduce_price(int amount){
      price = amount;
    }
    int getNumberOfPlates(void){
      return numberOfPlates;
    }
    int getPrice(void){
      return price;
    }
    void setMaxplate(int number){
      maximumPlate = number;
    }
    int getMaxplate(void){
      return maximumPlate;
    }
    void addMenu(){
      cout << "Enter Menu Name: ";
      getline(cin,name);
      cout << "Enter Price: ";
      cin >>price;
      cout << "Enter Maximum Number Of Plates: ";
      cin >> maximumPlate;
    }

};

class Customer{
  private:
       string name;
      int expenditure;
      int totalExpenditure;
      vector<Menu>custMenus;
  public:
    Customer(string custName,int exp,int totalExp){
       name = custName;
       expenditure = exp;
       totalExpenditure = totalExp;
    }
    Customer( ){
      name = "Unnamed";
      expenditure = 1;
      totalExpenditure = 0;
    }
    void setName(string custName){
      name = custName;
    }
    string getName(void){
      return name;
    }
    int getTotalExpenditure(void){
      return totalExpenditure;
    }
    void Order( Menu menu,int numberOfPlates){
      menu.addNumberOfPlates(numberOfPlates);
      cout << "Menu: " << menu.getName() << "\t" << "Price: " << menu.getPrice() << endl;
      cout << "Number of Plates: " << menu.getNumberOfPlates() << endl;
      cout << "Restaurant: " << menu.Resto.getName() << endl;
      expenditure = menu.getNumberOfPlates() * menu.getPrice();
      totalExpenditure+=expenditure;
      cout << "Expenditure: " << expenditure << endl;
      cout << "========================================================="<<"\n\n";
      custMenus.push_back(menu);
    }
    void CustomerReceipt(){
         for (unsigned int i = 0; i < custMenus.size(); ++i){
           cout << custMenus[i].getName() << "\t" << custMenus[i].getPrice() << "\t" << custMenus[i].getNumberOfPlates();
           cout << "\t" << expenditure << endl;
         }
         cout << "Total Expenditure: " << totalExpenditure <<endl;
    }
};

class Day{
  private:
      vector<Menu>menus;
      string name;
  public:
    string getDayName(void){
      return name;
    }
    void addMenuOfTheDay(Menu menu){
       menus.push_back(menu);
    }
    void displayMenusOfDay(){
     for(unsigned int i = 0; i < menus.size(); i++){
        cout << i + 1 << "     " << menus[i].getName() << "           ";
        cout << menus[i].getPrice() << "     " << menus[i].getMaxplate() <<endl;
     }
    }
};

class User{
   string name;
 public:
     User(){
       name = "User";
     }
      void setName(string name){
        this->name = name;
      }
      string getName(void){
        return name;
      }
};

class Administrator {
  private:
   string password;
      void setPassword(){
       password = "resto@4one";
      }
};

int main(){
    Restuarant restuarant("ModernResto","Commercial Avenue","modernresto@gmail.com",0);
    Menu menu("Menu",500,1,1);
    Customer customer("customer",0,0);
    Day days[7];

    /*
    cout << "Customer: " << customer.getName() <<endl;
    customer.Order(menu1);
    customer.Order(menu2);
    cout << "Total Expenditure: " << customer.getTotalExpenditure() << endl;
    cout << "---------------------------------------------------------" << endl;
    days[0].addMenuOfTheDay(menu1);
    days[0].addMenuOfTheDay(menu2);
    cout << "RESTAURANT" <<"     "<< "MENU" <<"        "<< "PRICE(FCFA)" <<"   "<< "MAXIMUM PLATE" <<endl;
    cout << "********************************************************"<<endl;
     */
    for(int i = 0; i < 7; i++){
    cout << "-------------------" << days[i].getDayName() << "------------------" <<endl;
    days[0].displayMenusOfDay();
    }
    cout << "*********************STATISTICS OF THE DAY**********************" <<endl;
    cout << "\n\n";
    restuarant.addAmountSold(customer.getTotalExpenditure());
    cout << "RESTUARANT" << "\t" << "TOTAL AMOUNT SOLD" << endl;
    cout << restuarant.getName() << "\t" << restuarant.getTotalAmountSold() <<endl;

    //////////////////////////////////////////////////////////////////////////
    /*
    *RESSTUARANT MANAGEMENT PROJECT
    */
    /////////////////////////////////////////////////////////////////////////////

     int ch;

    cout << "*******************RESTUARANT MANAGEMENT SYSTEM********************" <<endl;
    while( ch != 5){
      int num = 1;
    cout << "1. Add Menu For a Day"<<endl;
    cout << "2. Create Customer Bill"<<endl;
    cout << "3. Display Customer Receipt"<<endl;
    cout << "4. Display Statics For a Day" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter Choice: ";
    cin >>ch;
    switch(ch){
  case 1:
    cout << "*********************DAYS********************" <<endl;
    for( int i = 0; i < 7; i++){
      cout << i+1 <<". "<<days[i].getDayName() << "\t"; 
    }
    cout <<endl;
    int day;
    cout << "Enter Day: ";
    cin >>day;
    switch(day){
       case 1:
        cin.ignore();
        menu.addMenu();
        days[0].addMenuOfTheDay(menu);
        break;
       case 2:
         cin.ignore();
         menu.addMenu();
         days[1].addMenuOfTheDay(menu);
         break; 
      case 3:
       cin.ignore();
       menu.addMenu();
       days[2].addMenuOfTheDay(menu);
       break;
    }// End of second switch of the day
      break;
    case 2:
      days[0].displayMenusOfDay();
      cout << "Menu: "<< endl;
      cout << "Number of Plates: ";
      cin >> num;
      customer.Order(menu,num);
    break;
    case 3:
     customer.CustomerReceipt();
     restuarant.addAmountSold(customer.getTotalExpenditure());
     break;
    case 4:
    cout << "RESTUARANT" << "\t" << "TOTAL AMOUNT SOLD" << endl;
    cout << restuarant.getName() << "\t" << restuarant.getTotalAmountSold() <<endl;
  default:
    cout << "Unknown Input" << endl;
    } // End of switch
     
 }//end of while

    return 0;
}
