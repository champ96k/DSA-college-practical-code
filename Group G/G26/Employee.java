import employee.Emp;
import employee.EmpSal;

class Employee
  {
      public static void main(String args[])
        {
	EmpSal e=new EmpSal();
	
	System.out.println("\n\n\n\t ****** From Emp Class ******");
	e.accept();
	e.print();

	System.out.println("\n\n\n\t ****** From EmpSal Class ******");
	 e.readSalary();
	 e.printSalary();

        }
  }
