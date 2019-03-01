import java.util.*;

public class aa {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] thing = new char[3][5];
        for(int i = 0; i < 3; i++) {
            thing[i] = sc.next().toCharArray();
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 5; j++) {
                System.out.print(thing[i][j] + " ");
            }
            System.out.println();
        }
    }
}
