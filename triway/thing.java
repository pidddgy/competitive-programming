import java.util.*;

public class thing {
    public static void main(String[] args) {
        // Scanner sc = new Scanner(System.in);
        // int N = sc.nextInt();
        
        int E = 5;
        int V = 4;
        boolean[][] map = new boolean[V][V];

        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 5; i++) {
            int bv = sc.nextInt();
            int ev = sc.nextInt();

            map[bv][ev] = true;
            map[ev][bv] = true;
        }

        int[] step = new int[V];
        Arrays.fill(step, Integer.MAX_VALUE);
        step[0] = 0;

        LinkedList<Integer> queue = new LinkedList<Integer>();
        queue.add(0);
        
        while(!queue.isEmpty()) {
            int curV = queue.poll();
            for(int i = 0; i < V; i++) {
                if(map[curV][i]) {
                    if(step[i] > step[curV]+1) {
                        step[i] = step[curV]+1;
                        queue.add(i);
                    }
                }
            }
        }

        for(int i = 0; i < V; i++) {
            System.out.println(step[i]);
        }
    }
}
