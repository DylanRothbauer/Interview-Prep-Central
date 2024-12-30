import java.util.Scanner;

public class main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in); // Read from standard input
        String input = scanner.nextLine();
        int number = Integer.parseInt(input);
        if (number == 2) {
            System.out.println("NO");
        } else {
            if (number % 2 == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
    
            }
        }

        
    }
}
