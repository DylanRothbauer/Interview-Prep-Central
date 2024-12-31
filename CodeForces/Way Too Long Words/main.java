import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //System.out.println("HELLO");
        Scanner scanner = new Scanner(System.in); // Read from standard input
        String testCases = scanner.nextLine();

        for (int i = 0; i < Integer.parseInt(testCases); i++) {
            String word = scanner.nextLine();

            if (word.length() > 10) { // Strickly greater than 10
                String tmp = "";
                char firstLetter;
                char lastLetter;

                // Get first letter
                firstLetter = word.charAt(0);

                // Get last letter
                lastLetter = word.charAt(word.length() - 1);

                // Get number of char's between them
                String subString = word.substring(1, word.length() - 1); // param: Inclusive, Exclusive
                int numChars = subString.length();
                tmp += firstLetter + String.valueOf(numChars) + lastLetter;
                System.out.println(tmp);

            } else {
                System.out.println(word);
            }
        }
    }
}