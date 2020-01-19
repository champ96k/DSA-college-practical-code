import bank.AccountDetails;
import bank.ATM;
import java.util.Scanner;


class BankDB extends ATM
  {
       public static void main(String args[])
          {
	ATM atm=new ATM();

	System.out.println("\n\n\n\t ****** From AccountDetails Class ******");
	atm.showAccount();
	
	System.out.println("\n\n\n\t ****** From ATM Class ******");
	atm.accept();
	atm.display();
	atm.show();
          }
  }

