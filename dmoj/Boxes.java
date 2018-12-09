import java.util.*;

public class Boxes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] boxes = new int[N][3];
        
        for(int r = 0; r < N; r++) {
            boxes[r][0] = sc.nextInt();
            boxes[r][1] = sc.nextInt();
            boxes[r][2] = sc.nextInt();
            Arrays.sort(boxes[r]);
        }

        int M = sc.nextInt();
        for(int i = 0; i < M; i++) {
            int minV = Integer.MAX_VALUE;
            int[] item = new int[3];
            for(int j = 0; j < 3; j++)
                item[j] = sc.nextInt();
            
            Arrays.sort(item);

            for(int r = 0; r < N; r ++)
                if(item[0] <= boxes[r][0] && item[1] <= boxes[r][1] && item[2] <= boxes[r][2]) {
                    int vol = boxes[r][0] * boxes[r][1] * boxes[r][2];
                    if(vol < minV)
                        minV = vol;
                }

            if(minV == Integer.MAX_VALUE)
                System.out.println("Item does not fit.");
            else
                System.out.println(minV);
        }

        sc.close();
    }
}
