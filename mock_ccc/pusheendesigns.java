import java.util.*;

public class pusheendesigns {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] count = new int[1005];
        for(int i = 0; i < n; i++) {
            int num = sc.nextInt();
            count[num]++;
        }

        long[][] dp = new long[1005][1005];
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for(int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i-1][j] % 998244353 + (count[i] * dp[i-1][j-1]) % 998244353) % 998244353;
            }
        }
        
        System.out.println(dp[n][k]);
    }
}

