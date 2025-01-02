import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        //System.out.println("Hello, World!");
        Scanner scanner = new Scanner(System.in);
        int tests = Integer.parseInt(scanner.nextLine());
        int result = 0;

        for (int i = 0; i < tests; i++) {
            String inputLine = scanner.nextLine();
            int count = countOnes(inputLine);
            if (count > 1) {
                result++;
            }
            
        }
        System.out.println(result);
    }

    public static int countOnes(String str) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '1') {
                count++;
            }
        }
        return count;
    }
}
