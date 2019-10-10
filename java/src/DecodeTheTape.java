import java.util.Scanner;

public class DecodeTheTape {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();

        while (scanner.hasNext()) {
            String in = scanner.nextLine();

            if (in == "___________") break;

            int power = 1;
            int result = 0;
            for (int i = 9; i >= 1; --i) {
                if (in.charAt(i) == '.') continue;
                if (in.charAt(i) == 'o') {
                    result += power;
                }
                power *= 2;
            }

            char c = (char) result;
            System.out.print(c);
        }
    }
}
