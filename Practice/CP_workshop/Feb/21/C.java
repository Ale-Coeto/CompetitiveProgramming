import java.math.BigInteger;
import java.util.*;

public class C {
    public static void main(String[]args){

        int t, n, m, a;
        String input;
        BigInteger mult;
        Deque<Integer> dq = new ArrayDeque<>();
        //Read input
        Scanner scan = new Scanner(System.in);
        t = scan.nextInt();

        for (int i = 0; i < t; i++) {
            n = scan.nextInt();
            m = scan.nextInt();

            mult = BigInteger.valueOf(1);

            dq.clear();

            for (int j = 0; j < n; j++) {
                a = scan.nextInt();
                mult = mult.multiply(BigInteger.valueOf(a));
                dq.addLast(a);
            }

            input = scan.next();

            
            System.out.print(mult.mod(BigInteger.valueOf(m)) + " ");

            for (int k = 0; k < input.length()-1; k++) {
                if (input.charAt(k) == 'R') {
                    mult = mult.divide(BigInteger.valueOf(dq.getLast()));
                    dq.removeLast();
                } else {
                    mult = mult.divide(BigInteger.valueOf(dq.getFirst()));
                    dq.removeFirst();
                }
                System.out.print(mult.mod(BigInteger.valueOf(m)) + " ");

            }
            System.out.println("");


        }

        scan.close();


    }
}
