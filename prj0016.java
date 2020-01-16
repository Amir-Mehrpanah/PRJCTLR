/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
  public static void main (String args[]) throws Exception
  {
    BigInteger n = new BigInteger ("1");
    BigInteger two = new BigInteger ("2");
    for (int i = 0; i < 1000; i++)
      {
	n = n.multiply (two);
      }
    System.out.println (n);
      System.out.println (digitsum (n));
  }

  private static BigInteger digitsum (BigInteger v) throws Exception
  {
    BigInteger ten = new BigInteger ("10");
    BigInteger r = v.mod (ten);
    do
      {
	v = v.divide (ten);
	r = r.add (v.mod (ten));
      }
    while (v.compareTo (BigInteger.ZERO) > 0);
    return r;
  }
}
