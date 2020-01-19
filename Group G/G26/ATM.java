package bank;

import bank.AccountDetails;		/*   importing AccountDetails class of same package i.e bank   */
import employee.EmpSal;		/*   importing package employee in package bank   */
import java.util.Scanner;

/*   All methods are public in this class so we can use it outside the package and within external class of other packages   */

public class ATM extends AccountDetails	/*   inherit AccountDetails class to geting access of protected method in child class i.e in ATM class   */
  {
	private int pin;		/*   private variables which are only accessible through the member functions of same class only   */
	private String name,type;
	
	EmpSal e=new EmpSal();	/*   object of EmpSal class from employee package to access its member function which are public   */
	
	public void accept()		/*   public method so we can use it outside the package also   */
	  {
		Scanner sc=new Scanner(System.in);
		
		System.out.print("\n\t Enter the ATM card holder name......");
		name=sc.next();
		System.out.print("\n\t Enter the ATM card type......");
		type=sc.next();
		System.out.print("\n\t Enter the ATM pin......");
		pin=sc.nextInt();
	  }	

	public void display()		
	  {
		System.out.println("\n\t ATM card holder name: "+name);
		System.out.println("\n\t ATM card type: "+type);
		System.out.println("\n\t ATM pin: "+pin);
	  }

	public void showAccount()		
	  {
		super.showData();		/*   protected method in AccountDetails class   */
	  }

	public void show()		
	  {
		/*   These methods are public in employee package so we use it in bank package i.e. within external class of other package   */

		System.out.println("\n\n\n\t ****** From EmpSal Class ******");
		e.readSalary();
		e.printSalary();
		// e.print();
	  }
	 
  }
