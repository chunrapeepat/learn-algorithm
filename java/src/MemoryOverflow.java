import java.util.Scanner;

// 12583 - Memory Overflow
public class MemoryOverflow {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        for (int t = 1; t <= T; ++t) {
            int N = scanner.nextInt();
            int K = scanner.nextInt();
            String names = scanner.next();

            int[] result = new int[26];
            int count = 0;

            for (int i = 0; i < names.length(); ++i) {
                if (result[names.charAt(i) - 'A'] > 0) {
                    ++count;
                }
                result[names.charAt(i) - 'A'] += 1;
                if (i - K >= 0 && result[names.charAt(i - K) - 'A'] > 0) {
                    result[names.charAt(i - K) - 'A'] -= 1;
                }
            }

            System.out.printf("Case %d: %d\n", t, count);
        }
    }
}
