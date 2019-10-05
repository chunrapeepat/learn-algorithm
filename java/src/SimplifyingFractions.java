import java.math.BigInteger;
import java.util.Scanner;

public class SimplifyingFractions {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        for (int i = 0; i < N; ++i) {
            BigInteger p = scanner.nextBigInteger();
            scanner.next();
            BigInteger q = scanner.nextBigInteger();

            BigInteger d = p.gcd(q);

            System.out.println("(" + p.divide(d) + ", " + q.divide(d) + ")");
        }
    }
}
