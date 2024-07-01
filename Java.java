import java.math.BigInteger;
import java.util.*;

public class Java {
    public static void main(String[]args){
        
        // General
        ArrayList<Integer> uno = new ArrayList<>();
        uno.add(21);
        uno.add(1);
        Collections.sort(uno, Collections.reverseOrder());

        // Double ended queue
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addFirst(0);
        dq.addLast(1);
        dq.removeFirst();
        dq.removeLast();
        
        //Read input
        Scanner scan = new Scanner(System.in);
        int n;
        // n = Integer.parseInt(scan.nextLine());
        // int nums[] = new int[n];

        // for (int i = 0; i < n; i ++) {
        //     nums[i] = scan.nextInt();
        //     System.out.println(nums[i]);
        // }

        //Big Integer operations
        BigInteger sum = BigInteger.ZERO;
        BigInteger V = scan.nextBigInteger(); // To read the next big int
        sum = sum.add(V);
        sum = sum.divide(V);
        sum = sum.pow(2);
        sum = sum.multiply(V);
        sum = sum.remainder(V);
        sum = sum.mod(V);

        // Transform types
        String m = sum.toString(10);
        System.out.println(V);
        int F = 2;
        sum.divide(BigInteger.valueOf(F));
        
        // Other operations
        if (V.isProbablePrime(10))
            System.out.println("is prime");
        
        V = V.gcd(BigInteger.valueOf(1000));


        scan.close();


    }
}
