
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;

public class Worker implements Displays {
	private String first_Name;
	private String last_Name;
	private String gender;
	private String category;
	private double salary;
	public Worker( ) {
		first_Name = last_Name = gender = " ";
		category = " ";
		salary = 0.0;
	}
	String getName( ) {
		return first_Name + " " + last_Name;
	}
	void setName(String name1, String name2 ) {
		first_Name = name1;
		last_Name = name2;
	}
	String getGender( ) {
		return gender;
	}
	String getCategory( ) {
		return category;
	}
	void setCategory( String cat ) {
		category = cat;
	}
   double getSalary( double shared ) {
	   return (salary + shared);
   }
   @Override
   public void Read() {
		
		String [] cat = new String[4];
		cat[0] = "A";
		cat[1] = "B";
		cat[2] = "C";
		cat[3] = "D";
		double []base = new double[] {150000,120000,100000,80000};
		BufferedReader read = new BufferedReader( new InputStreamReader (System.in)); 
		Scanner in = new Scanner (System.in);
		System.out.print("Enter Worker First Name: ");
		try {
		first_Name = read.readLine();
		}catch (IOException e) {
			System.out.print("An error occured,"+ e.getMessage());
		}
		System.out.print("Enter Worker Last Name: ");
		try {
		last_Name = read.readLine();
		}catch (IOException e) {
			System.out.print("An error occured,"+ e.getMessage());
		}
		System.out.print("Enter Worker Gender: ");
		try {
		gender = read.readLine();
		}catch (IOException e) {
			System.out.print("An error occured,"+ e.getMessage());
		}
		System.out.print("Enter Worker Category: ");
		try {
		category = read.readLine();
		for (int i = 0; i < cat.length; i++ ) {
			if ( cat[i].equalsIgnoreCase(category)) {
				salary = base[i];
			}
		}
		}catch (IOException e) {
			System.out.print("An error occured,"+ e.getMessage());
		}

	}
   @Override
   public void Print(){
      System.out.println(" "+getName()+" "+gender+" "+category+" "+salary);
   }
   public void PaySalary() {
	BufferedReader read = new BufferedReader( new InputStreamReader (System.in)); 
	Scanner in = new Scanner ( System.in);
	   double sh = 0.0;
	   double profit = 0.0;
	   double amount = ( profit * 30 ) / 100;
	   int num = 3;
	   sh = amount / num;
	 System.out.println("Enter Profit Made By Company: ");
	 sh = in.nextDouble();
     System.out.println(" "+getName()+" "+getGender()+" "+getCategory()+" "+getSalary(sh));
	}
   @Override
	public void Write() {

	}
}
