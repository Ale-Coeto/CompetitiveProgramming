import java.math.BigInteger;
import java.util.*;

public class L {
    public static void main(String[] args) {



        // Read input
        Scanner scan = new Scanner(System.in);
        int n;
        n = scan.nextInt();
        ArrayList<BigInteger> nums = new ArrayList<>();

        nums.add(BigInteger.valueOf(1));
        nums.add(BigInteger.valueOf(2));
        nums.add(BigInteger.valueOf(3));

        for (int i = 3; i <= n; i++) {
            BigInteger res = nums.get(i-1).multiply(BigInteger.valueOf(3)).add(nums.get(i-2).multiply(BigInteger.valueOf(2)));
            res = res.add(nums.get(i-3)).add(BigInteger.valueOf(3));
            nums.add(res);
        }
        
        BigInteger ans = nums.get(n);
        ans = ans.mod(BigInteger.valueOf(1000000007));
        System.out.println(ans);



        scan.close();

    }
}
