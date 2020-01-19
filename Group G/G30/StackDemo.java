/*
The Stack class implements a last-in-first-out (LIFO) stack of elements.

You can think of a stack literally as a vertical stack of objects; when you add a new element, 
it gets stacked on top of the others.

When you pull an element off the stack, it comes off the top. 
In other words, the last element you added to the stack is the first one to come back off.
*/
import java.util.*;
public class StackDemo 
{

   static void showpush(Stack st, int a) 
	{
      st.push(new Integer(a));
      System.out.println("push(" + a + ")");
      System.out.println("stack: " + st);
     }
   static void showpop(Stack st) 
	{
      System.out.print("pop -> ");
      Integer a = (Integer) st.pop();
      System.out.println(a);
      System.out.println("stack: " + st);
   	}
   public static void main(String args[]) 
	{
      Stack st = new Stack();
      System.out.println("stack: " + st);
      showpush(st, 42);
      showpush(st, 66);
      showpush(st, 99);
      showpop(st);
      showpop(st);
      showpop(st);
      try 
	   {
         showpop(st);
        }
      catch (EmptyStackException e) 
        {
         System.out.println(e);
        }
   }
}
/*
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ javac StackDemo.java 
Note: StackDemo.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ java StackDemo
stack: []
push(42)
stack: [42]
push(66)
stack: [42, 66]
push(99)
stack: [42, 66, 99]
pop -> 99
stack: [42, 66]
pop -> 66
stack: [42]
pop -> 42
stack: []
pop -> java.util.EmptyStackException
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ 
*/
