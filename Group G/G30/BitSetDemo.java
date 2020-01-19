/*The BitSet class creates a special type of array that holds bit values. 
The BitSet array can increase in size as needed. 
This makes it similar to a vector of bits. 
This is a legacy class but it has been completely re-engineered in Java 2, version 1.4.*/

import java.util.BitSet;
public class BitSetDemo 
{
  public static void main(String args[]) 
	{
      BitSet bits1 = new BitSet(16);
      BitSet bits2 = new BitSet(16);
      
      // set some bits
      for(int i = 0; i < 16; i++) 
	  {
         if((i % 2) == 0) 
			bits1.set(i);
         if((i % 5) != 0) 
			bits2.set(i);
       }
     
      System.out.println("Initial pattern in bits1: ");
      System.out.println(bits1);
      System.out.println("\nInitial pattern in bits2: ");
      System.out.println(bits2);

      // AND bits
      bits2.and(bits1);
      System.out.println("\nbits2 AND bits1: ");
      System.out.println(bits2);

      // OR bits
      bits2.or(bits1);
      System.out.println("\nbits2 OR bits1: ");
      System.out.println(bits2);

      // XOR bits
      bits2.xor(bits1);
      System.out.println("\nbits2 XOR bits1: ");
      System.out.println(bits2);
   }
}
/*
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ javac BitSetDemo.java 
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ java BitSetDemo 
Initial pattern in bits1: 
{0, 2, 4, 6, 8, 10, 12, 14}

Initial pattern in bits2: 
{1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14}

bits2 AND bits1: 
{2, 4, 6, 8, 12, 14}

bits2 OR bits1: 
{0, 2, 4, 6, 8, 10, 12, 14}

bits2 XOR bits1: 
{}
siem@siem-OptiPlex-3010:~/Desktop/ADSL/G2$ 

*/
