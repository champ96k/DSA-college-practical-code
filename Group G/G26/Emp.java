package employee;
import java.util.Scanner;

public class Emp			/*   public class is accessible in all other packages also   */
  {
	private String name;		/*   private variable is access within the same class through the member function only   */
	private int id;
	
	public void accept()		/*   public method is accessible in all other packages also   */
	  {
		Scanner sc=new Scanner(System.in);
		
		System.out.print("\n\t Enter the employee name......");
		name=sc.next();
		System.out.print("\n\t Enter the employee id......");
		id=sc.nextInt();
	  }
	
	protected void display()	/*   protected method is accessible in SUB CLASS of OTHER PACKAGE   */
	  {
		System.out.print("\n\n\t From protected void display() method \n" );
		System.out.print("\n\t Employee name is: "+name);
		System.out.print("\n\t Employee id is: "+id);
	  }

	void displayForDefault()	/*   default method is accessible within same class and within other class of same package   */
	  {	
		System.out.print("\n\n\t From void displayForDefault() method \n" );
		System.out.print("\n\t Employee name is: "+name);
		System.out.print("\n\t Employee id is: "+id);
	  }
  }

