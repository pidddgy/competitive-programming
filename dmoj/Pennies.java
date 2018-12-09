import java.util.*;

public class Pennies {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(;;) {
            int rad = sc.nextInt(); if (rad == 0) break;
            int count = 0;
            for(int l = 0; l <= rad; l++) {
                double height = Math.sqrt( Math.pow(rad, 2) - Math.pow(l, 2) );
                count += (Math.floor(height)+1) * 4;
            }
           System.out.println(count - rad*4 - 3);
        }
        sc.close();
    }
}
