import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;

public class Article extends ArticleNames implements Displays {
         public Article() {
        	super();
         }
	@Override
	public void Read() {
	BufferedReader read = new BufferedReader( new InputStreamReader (System.in)); 
	Scanner in = new Scanner (System.in);
    System.out.print("Enter Article Name: ");
    try {
    	ArticleName = read.readLine();
    }catch ( IOException e) {
    	System.out.print("An Error Occurred"+e.getMessage());
    }
    System.out.print("Enter Article Type: ");
    try {
    	ArticleType = read.readLine();
    }catch ( IOException e) {
    	System.out.print("An Error Occurred"+e.getMessage());
    }
    System.out.println("Enter Quantity Name: ");
    try {
    	QuantityName = read.readLine();
    }catch ( IOException e) {
    	System.out.print("An Error Occurred"+e.getMessage());
    }
    System.out.println("Enter Quantity: ");
    Quantity = in.nextDouble();
   
    System.out.print("Enter Price for One: ");
    Price1 = in.nextDouble();
   
	}

	@Override
	public void Print() {
		// TODO Auto-generated method stub
		System.out.print("   "+getArticle()+"  "+getType()+"   "+getQuantity()+"     "+getQuantityName()+"    "+getPrice());

	}

	@Override
	public void Write() {
		// TODO Auto-generated method stub

	}

}
