/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;

public class Main
{
  public static void main (String[]args)
  {
    Calendar cs = new GregorianCalendar (1901, 0, 1, 00, 00, 00);
    Calendar ce = new GregorianCalendar (2000, 11, 31, 00, 00, 00);
    int count = 0;
    while (ce.compareTo (cs) >= 0)
      {
	if (cs.get (Calendar.DAY_OF_WEEK) == 1)
	  count++;

	cs.add (Calendar.MONTH, 1);
	System.out.print (cs.getTime ());
	System.out.print (" : ");
	System.out.println (count);
      }


  }
}
