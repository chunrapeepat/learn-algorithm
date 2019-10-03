import java.util.Scanner;

// 13275 - Leap Birthdays
public class LeapBirthdays {
    private static final int FIRST_LEAP = 1852;
    private static final int LAST_YEAR = 3000;
    private static int dp[] = new int[400];

    public static boolean isLeap(int year) {
        if (year % 400 == 0) return true;
        else if(year % 100 == 0) return false;
        else if(year % 4 == 0) return true;
        else return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        // pre-processing leap year
        int prev = 0;
        for (int i = FIRST_LEAP; i < LAST_YEAR; i += 4) {
            if (isLeap(i)) {
                prev += 1;
                dp[(i - FIRST_LEAP) / 4] = prev;
            }
        }

        for (int t = 1; t <= T; ++t) {
            int D = scanner.nextInt();
            int M = scanner.nextInt();
            int Y = scanner.nextInt();
            int QY = scanner.nextInt();

            if (D == 29 && M == 2) {
                while (!isLeap(QY)) {
                    --QY;
                }
                System.out.printf("Case %d: %d\n", t, dp[(QY - FIRST_LEAP) / 4] - dp[(Y - FIRST_LEAP) / 4]);
            } else {
                System.out.printf("Case %d: %d\n", t, QY - Y);
            }
        }
    }
}
