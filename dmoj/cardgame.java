import java.util.Scanner;

public class thingy {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int personA = 0;
        int personB = 0;
        String[] cards = new String[52];
        boolean[] isHigh = new boolean[52];
        
        for(int i = 0; i < 52; i++) {
            cards[i] = sc.next();
            if(cards[i].equals("ace") || cards[i].equals("king") || cards[i].equals("queen") || cards[i].equals("jack"))
                isHigh[i] = true;
        }

        for(int i = 0; i < 52; i++) {
            if(cards[i].equals("ace") && i < 52-4) {
                boolean good = true;
                for(int j = 1; j <= 4; j++) {
                    if(isHigh[i+j]) {
                        good = false;
                    }
                }
                if(good) {
                    if(i%2 == 0) {
                        personA += 4;
                        System.out.println("Player A scores 4 point(s).");
                    } else {
                        personB += 4;
                        System.out.println("Player B scores 4 point(s).");
                    }
                }
            }

            if(cards[i].equals("king") && i < 52-3) {
                boolean good = true;
                for(int j = 1; j <= 3; j++) {
                    if(isHigh[i+j]) {
                        good = false;
                    }
                }
                if(good) {
                    if(i%2 == 0) {
                        personA += 3;
                        System.out.println("Player A scores 3 point(s).");
                    } else {
                        personB += 3;
                        System.out.println("Player B scores 3 point(s).");
                    }
                }
            }

            if(cards[i].equals("queen") && i < 52-2) {
                boolean good = true;
                for(int j = 1; j <= 2; j++) {
                    if(isHigh[i+j]) {
                        good = false;
                    }
                }
                if(good) {
                    if(i%2 == 0) {
                        personA += 2;
                        System.out.println("Player A scores 2 point(s).");
                    } else {
                        personB += 2;
                        System.out.println("Player B scores 2 point(s).");
                    }
                }
            }

            if(cards[i].equals("jack") && i < 52-1) {
                boolean good = true;
                for(int j = 1; j <= 1; j++) {
                    if(isHigh[i+j]) {
                        good = false;
                    }
                }
                if(good) {
                    if(i%2 == 0) {
                        personA += 1;
                        System.out.println("Player A scores 1 point(s).");
                    } else {
                        personB += 1;
                        System.out.println("Player B scores 1 point(s).");
                    }
                }
            }
        }
        System.out.println("Player A: " + personA + " point(s).");
        System.out.println("Player B: " + personB + " point(s).");
        sc.close(); 
    }
}
