
/*The Map interface maps unique keys to values. A key is an object that you use to retrieve a value at a later date.

   - Given a key and a value, you can store the value in a Map object. After the value is stored, you can retrieve it by using its key.

   - Several methods throw a NoSuchElementException when no items exist in the invoking map.

   - A ClassCastException is thrown when an object is incompatible with the elements in a map.

   - A NullPointerException is thrown if an attempt is made to use a null object and null is not allowed in the map.

   - An UnsupportedOperationException is thrown when an attempt is made to change an unmodifiable map.
*/
import java.util.*;
public class CollectionsDemo {

   public static void main(String[] args) {
      Map m1 = new HashMap(); 
      m1.put("Zara", "8");
      m1.put("Mahnaz", "31");
      m1.put("Ayan", "12");
      m1.put("Daisy", "14");

      System.out.println();
      System.out.println(" Map Elements");
      System.out.print("\t" + m1);
	
   }
}
/*
siem@siem-OptiPlex-3010:~$ cd Desktop/
siem@siem-OptiPlex-3010:~/Desktop$ cd ADSL
siem@siem-OptiPlex-3010:~/Desktop/ADSL$ cd G2
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ javac CollectionsDemo.java 
Note: CollectionsDemo.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ java CollectionsDemo 

 Map Elements
	{Daisy=14, Ayan=12, Zara=8, Mahnaz=31}
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$
*/


