import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Scanner;
public class COMPANY {
           
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner( System.in );
		
		 Worker Work = new Worker();
		 Article Art = new Article();
		 Customer Cust = new Customer();
		int ans = 0;
		do {
		System.out.println(" ********ABAS COMPANY LIMITED************");
		System.out.println("1        WORKER ");
	    System.out.println("2        ARTICLE ");
	    System.out.println("3        CUSTOMER ");
	    System.out.println("4        EXIT ");
	    System.out.println("        Enter first character to chose: ");
	    ans = in.nextInt();
	    switch( ans ) {
	    case 1:
	    	Work.Read();
	  	    System.out.println("    ");
	  	    Work.Print();
		    System.out.println("    ");
		    Work.PaySalary();
	  	    break;
	  	case 2:
	  	  Art.Read();
		  System.out.println("    ");
		  Art.Print();
		  System.out.println("    ");
		    break;
	  	case 3:
	  	   Cust.Read();
		    System.out.println("    ");
		    Cust.Print();
	  		break;
	    }
		}while( ans != 4);
	}

}
