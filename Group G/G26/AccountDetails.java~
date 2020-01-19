package bank;
import java.util.Scanner;

public class AccountDetails
  {
	private String acc_type;  //private variable is access within the same class through the member function only  
	private int id,validity;
	
	private void getData()	// private member function  is access within the same class through the public member function only  
	  {
		Scanner sc=new Scanner(System.in);
		
		System.out.print("\n\t Enter the account type......");
		acc_type=sc.next();
		System.out.print("\n\t Enter the account id......");
		id=sc.nextInt();
		System.out.print("\n\t Enter the account validity in months......");
		validity=sc.nextInt();
	  }

	protected void showData()	//   protected method is accessible in SUB CLASS of OTHER PACKAGE   
	  {
		getData();		//   private method is geting access through member function of same class    
		System.out.println("\n\t Account type is: "+acc_type);
		System.out.println("\n\t Account id is: "+id);
		System.out.println("\n\t Account validity is: "+validity+" month.");
	  }
	
  }

