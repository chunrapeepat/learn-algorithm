package ACM2014;

import java.util.Scanner;

public class DecodingBabyBoos {
    private static int m(char c) {
        return c - 'A' + 1;
    }

    private static char r(int i) {
        char c = (char) (i + 'A' - 1);
        return c;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        for (int t = 0; t < T; ++t) {
            String message = scanner.next();
            int[] map = new int[27];

            int R = scanner.nextInt();
            for (int i = 0; i < R; ++i) {
                char replace = scanner.next().charAt(0);
                char old = scanner.next().charAt(0);

                if (map[m(old)] == 0) {
                    map[m(old)] = m(replace);
                }

                for (int k = 1; k < 27; ++k) {
                    if (map[k] == m(old)) {
                        map[k] = m(replace);
                    }
                }
            }

            for (int i = 0; i < message.length(); ++i) {
                char c = message.charAt(i);
                if (c == '_' || map[m(c)] == 0) {
                    System.out.print(message.charAt(i));
                    continue;
                }
                System.out.print(r(map[m(c)]));
            }

            System.out.println();
        }
    }
}
