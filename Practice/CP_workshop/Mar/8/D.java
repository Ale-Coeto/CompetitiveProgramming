import java.math.BigInteger;
import java.util.*;

public class D {
    public static void main(String[] args) {

        // Read input
        Scanner scan = new Scanner(System.in);
        int n, a, b;
        a = scan.nextInt();
        b = scan.nextInt();
        n = scan.nextInt();

        ArrayList<BigInteger> nums = new ArrayList<>();

        nums.add(BigInteger.valueOf(a));
        nums.add(BigInteger.valueOf(b));

        for (int i = 2; i < n; i++) {
            BigInteger res2 = nums.get(i - 1).multiply(nums.get(i - 1));
            BigInteger res = nums.get(i - 2).add(res2);
            nums.add(res);
        }

        BigInteger ans = nums.get(n-1);
        System.out.println(ans);

        scan.close();

    }
}
