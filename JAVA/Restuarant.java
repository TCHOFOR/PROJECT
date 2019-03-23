import java.io.*;
import java.util.Scanner;

public class Restuarant{
	private String name;
	private String address;
	private String email;
  public Restuarant(String newName,String newAddress,String newEmail){
    name = newName;
    address = newAddress;
    email = newEmail;
  }
	public Restuarant( ){
		name = "Restuarant";
		address = " ";
		email = "restuarang@gmail.com";
	}
	public void Resto(){
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      System.out.print("Name: ");
      try{
        name = br.readLine();
      }catch(IOException e){
      	System.out.println("An error occured"+e.getMessage());
      }
      System.out.print("Address: ");
      try{
      	address = br.readLine();
      }catch(IOException e){
      	System.out.println("An error occured"+e.getMessage());
      }
      System.out.print("Email: ");
      try{
      	email = br.readLine();
      }catch(IOException e){
      	System.out.println("An error occured"+e.getMessage());
      }
	}//End of function resto
  //Displaying information
  public void display(){
      System.out.println("  "+name+"  "+"  "+address+"  "+email);
  }//End of function display
	public static void main(String[] args) {
		Restuarant restuarant = new Restuarant();
		restuarant.Resto();
    System.out.println("*********************RESTUARANT***************************");
    restuarant.display();
		Menu menu = new Menu();
		//menu.addMenu();
		//Customer customer = new Customer();
		//customer.order(menu);
		//customer.displayReciept();
		
	}
	//Class menu of dishes sold in the Restuarant
	private class Menu{
	   private String name;	
     private float price;
     private int maximumPlate;
     private int numberOfPlates;
     public Menu(String menuName,float menuPrice,int maxPlate,int numPlates ){
     	name = menuName;
     	price = menuPrice;
     	maximumPlate = maxPlate;
     	numberOfPlates = numPlates; 
     }
     public Menu(){
     	name = " ";
     	price = 1;
     	maximumPlate = 0;
     	numberOfPlates = 1;
     }
     public void setName(String newName){
     	name = newName;
     }
     public String getName(){
     	return name;
     }
     public void setPrice(float newPrice){
     	price = newPrice;
     }
     public float getPrice(){
     	return price;
     }
     public void setMaximumPlates(int newMax){
     	maximumPlate = newMax;
     }
     public int getMaximumPlates(){
     	return maximumPlate;
     }
     public void addNumberOfPLates(int number){
     	if(number > maximumPlate){
     		System.out.println("You exceed maximum number of plates"+maximumPlate);
     		return;
     	}
     	numberOfPlates = number;
     }
     public int getNumberOfPlates(){
     	return numberOfPlates;
     }
     //Reading menu's
     public void addMenu(){
     	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     	Scanner in = new Scanner(System.in);
     	System.out.print("Name: ");
     	try{
     		name = br.readLine();
     	}catch(IOException e){
     		System.out.println("An erro occured"+e.getMessage());
     	}
     	System.out.print("Price: ");
     	price = in.nextFloat();
     	System.out.print("Maximum Number of Plates: ");
     	maximumPlate = in.nextInt();
     }
	}// End of Menu class

	class Customer{
		private String name;
		private float expenditure;
		private float totalExpenditure;
		private Menu menu;
		public Customer( Menu custMenu,String custName,float custExpenditure,float custTotalExpenditure){
           menu = custMenu;
           name = custName;
           expenditure = custExpenditure;
           totalExpenditure = custTotalExpenditure;
		}//end of constructor
		public Customer(){
      this.menu = menu;
			name = "";
			expenditure = 0;
			totalExpenditure+=expenditure;
		}
		public void setName(String newName){
			name = newName;
		}
		public String getName(){
			return name;
		}
		public void setExpenditure(int newExpenditure){
			expenditure = newExpenditure;
		}
		public float getExpenditure(){
			return expenditure;
		}
		public float getTotalExpenditure(){
			return totalExpenditure;
		}
		public void order(Menu menu){
			Scanner in = new Scanner(System.in);
			System.out.println(menu.getName()+"  "+menu.getPrice());
			int numPlates;
			System.out.print("Number of Plates: ");
			numPlates = in.nextInt();
			menu.addNumberOfPLates(numPlates);
			expenditure = menu.getPrice() * menu.getNumberOfPlates();
		}
		//Displaying customer receipt
		public void displayReciept(){
			System.out.print(menu.getName()+" "+menu.getPrice()+" "+menu.getNumberOfPlates()+" "+expenditure);
		}
	}//End of class customer
}