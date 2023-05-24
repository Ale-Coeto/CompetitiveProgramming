import java.util.*;

public class Java {
    public static void main(String[]args){
        Scanner scan = new Scanner(System.in);
        int n;
        n = Integer.parseInt(scan.nextLine());
        int nums[] = new int[n];

        for (int i = 0; i < n; i ++) {
            nums[i] = scan.nextInt();
            System.out.println(nums[i]);
        }

        scan.close();

    

    }
}
