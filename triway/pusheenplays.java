import java.util.*;

public class pusheenplays {
    public static class Food implements Comparable<Food>{
        public String name;
        public int amount;
        public int orderId;

        public Food(String name, int amount, int orderId) {
            this.name = name;
            this.amount = amount;
            this.orderId = orderId;
        }

        @Override
        public int compareTo(Food o) {
            if(this.amount > o.amount) {
                return -1;
            } else if (this.amount < o.amount) {
                return 1;
            } else {
                if(this.orderId < o.orderId) {
                    return -1;
                } else {
                    return 1;
                }
            }
        }
    }
    public static void main(String[] args) {
        Food[] food = new Food[4];
        food[0] = new Food("Deluxe Tuna Bitz", 0, 0);
        food[1] = new Food("Bonito Bitz", 0, 1);
        food[2] = new Food("Sashimi", 0, 2);
        food[3] = new Food("Ritzy Bitz", 0, 3);

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < N; i++) {
            String name = sc.nextLine();
            if(name.equals("Deluxe Tuna Bitz")) food[0].amount++;
            if(name.equals("Bonito Bitz")) food[1].amount++;
            if(name.equals("Sashimi")) food[2].amount++;
            if(name.equals("Ritzy Bitz")) food[3].amount++;
        }

        Arrays.sort(food);
        for(int i = 0; i < 4; i++) {
            if(food[i].amount != 0)
            System.out.println(food[i].name + " " + food[i].amount);
        }
    }
}
