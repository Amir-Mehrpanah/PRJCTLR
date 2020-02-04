import java.math.BigInteger;

class Fib{
    public static void main(String[] args) {
        int index = 2;
        BigInteger c1 =new BigInteger("1");
        BigInteger c2 =new BigInteger("1");
        BigInteger temp = BigInteger.ZERO;
        do{
            temp = c1.add(c2);
            c1 = c2;
            c2 = temp;
            index++;
        }while(c2.toString().length() < 1000);
        System.out.println(index +" : "+c2 + " len : "+c2.toString().length());
    }
}