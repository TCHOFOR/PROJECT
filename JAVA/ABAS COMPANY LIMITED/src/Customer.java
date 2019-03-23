import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.io.IOException;
public class Customer extends ArticleNames implements Displays {
	  String Name;
	  private double Amount;
	  private double TotalAmount;
	   public Customer() {
      	 super();
      	 Name = "Unnamed";
      	 Amount = TotalAmount = 0.0;
       }
	   String getName( ) {
		   return Name;
	   }
		public double getAmount() {
			return Amount;
		}

		public void setAmount(double amt) {
			Amount = amt;
		}
		public double getTotalAmount() {
			return TotalAmount;
		}
		public void setTotalAmount(double totalAmount) {
			TotalAmount = totalAmount;
		}

	@Override
	public void Read() {
		BufferedReader read = new BufferedReader (new InputStreamReader(System.in));
        Article art = new Article();
		Scanner in = new Scanner (System.in);
        System.out.print("Enter Customer Name: ");
        try {
        Name = read.readLine();
        }catch(IOException e) {
        	System.out.print("An Error Occurred,"+e.getMessage());
        }
        System.out.print("*********ITEM LIST**********");
        System.out.println("Enter Article Name: ");
        try {
        	ArticleName = read.readLine();
        }catch ( IOException e) {
        	System.out.print("An Error Occurred"+e.getMessage());
        }
        Article Art = new Article();
        if ( ArticleName == Art.getArticle() ) {
        
        System.out.println("Enter Article Type: ");
        try {
        	ArticleType = read.readLine();
        }catch ( IOException e) {
        	System.out.print("An Error Occurred"+e.getMessage());
        }
        System.out.println("Enter Article Quantity Demanded: ");
        Quantity = in.nextDouble();
        System.out.println("Enter Quantity Name: ");
        try {
        	QuantityName = read.readLine();
        }catch ( IOException e) {
        	System.out.print("An Error Occurred"+e.getMessage());
        }
        double quan = Art.getQuantity();
        Amount = Art.getPrice() * Quantity;
        TotalAmount += Amount;
        quan = quan - Quantity;
        Art.setQuantity(quan);
        }else {
        	System.out.print("Article not found");
        }
	}

	@Override
	public void Print() {
		// TODO Auto-generated method stub
        System.out.print("CUSTOMER NAME:"+getName());
        System.out.print("ARTICLE    TYPE    QUANTITY        NAME         AMOUNT(FCFA)  ");
        System.out.print(getArticle()+" "+getType()+" "+getQuantityName()+" "+getAmount());
        System.out.print("TOTAL AMOUNT: "+ getTotalAmount());
	}

	@Override
	public void Write() {
		// TODO Auto-generated method stub

	}


}
