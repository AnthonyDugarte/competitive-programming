// Note: This one wasn't the one that was uploaded to the plataform

import java.math.BigInteger;
import java.util.Scanner;

class Main
{
  public static void main(String[] args)
  {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt(), m = scanner.nextInt(), k = scanner.nextInt();
    scanner.close();

     BigInteger score = BigInteger.valueOf(0);

     int doublesNeeded = m - (n - n / k);

     if(doublesNeeded > 0)
     {
       score = score.flipBit(doublesNeeded + 1);
       score = score.multiply(BigInteger.valueOf(k));
       score = score.add(BigInteger.valueOf(-2 * k));
     }

     if(m > 0 && doublesNeeded >= 0)
      score = score.add(BigInteger.valueOf(m - doublesNeeded * k));
    else if(doublesNeeded < 0)
      score = BigInteger.valueOf(m);

     System.out.println(score.mod(BigInteger.valueOf(1000000009)));
  }
}
