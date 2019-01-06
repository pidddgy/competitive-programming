import java.util.Scanner;

import javax.lang.model.util.ElementScanner6;

public class topyodeller {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int[] scores = new int[N];
        int[] worstRanks = new int[N];

        for(int i = 0; i < K; i++) {
            for(int j = 0; j < N; j++) {
                int score = sc.nextInt();
                scores[j] += score;
            }

            // Get rank
            for(int j = 0; j < N; j++) {
                int rank = 1;
                for(int c = 0; c < N; c++) {
                    if(scores[c] > scores[j]) rank++;
                }
                if(rank > worstRanks[j]) worstRanks[j] = rank;
            }

        }

        int bestScore = Integer.MIN_VALUE;

        for(int i = 0; i < N; i++) {
            if(scores[i] > bestScore) {
                bestScore = scores[i];
            }
        }
        for(int i = 0; i < N; i++) {
            if(scores[i] == bestScore) {
                System.out.println("Yodeller " + (i+1) +" is the TopYodeller: score " + bestScore + ", worst rank " +worstRanks[i]);
            }
        }
        
    }
}

