package employee;

import employee.Emp;			/*    importing Emp class of same package i.e employee package   */
import java. util.Scanner;

public class EmpSal extends Emp		/*   inherit Emp class to geting access of protected method   */
  {
	private float basic_sal,da,hra;	/*   private variables which are only accessible through the member functions of same class only   */
	
	public void readSalary()	/*   public method geting access outside the package also   */
	  {
		Scanner sc=new Scanner(System.in);
		
		System.out.print("\n \t Enter basic salary......");
		basic_sal=sc.nextFloat();
		System.out.print("\n \t Enter DA......");
		da=sc.nextFloat();
		System.out.print("\n \t Enter HRA......");
		hra=sc.nextFloat();
	  }

	public void printSalary()
	  {
		System.out.print("\n \t Basic salary is "+basic_sal);
		System.out.print("\n \t DA is "+da);
		System.out.print("\n \t HRA is "+hra);
	  }

	public void print()
	  {
		super.display();		/*   calling protected method of parent class(Emp class) using super keyword within same package   */
		super.displayForDefault();	/*   calling default method of parent class(Emp class) using super keyword within same package   */
	  }
	
  }


