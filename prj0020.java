/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.math.BigInteger;

public class Main
{
  public static void main (String[]args)
  {
    BigInteger b = factorial (new BigInteger ("100"));
    int sum = sumDigits (b);
      System.out.println (sum);
  }

  private static int sumDigits (BigInteger b)
  {
    BigInteger ten = new BigInteger ("10");
    int sum = 0;
    do
      {
	sum += b.mod (ten).intValue ();
	b = b.divide (ten);
      }
    while (b.compareTo (BigInteger.ZERO) != 0);

    return sum;
  }

  private static BigInteger factorial (BigInteger b)
  {
    BigInteger big = BigInteger.ONE;
    for (BigInteger i = new BigInteger ("2"); i.compareTo (b) <= 0;
	 i = i.add (BigInteger.ONE))
      {
	big = big.multiply (i);
      }
    return big;
  }
}
