import java.util.*;
public class lfdkjdsfldjsfldsjfs {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T-->0) {
            String s = sc.nextLine();
            
            char prev = s.charAt(0);
            int l = 0;
            for(int i = 1; i < s.length(); i++) {                
                if(s.charAt(i) == prev) {
                    l++;
                } else {
                    System.out.print(l + " " + prev + " ");
                    l = 0;
                    prev = s.charAt(i);
                }
            }
        }
    }
}
