import java.util.Iterator;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class AngryBirdsTransformers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int T = scanner.nextInt();
            if (T == 0) break;

            int[] startLine = new int[10501];
            int[] endLine = new int[10501];

            SortedSet<Integer> index = new TreeSet<>();

            for (int t = 0; t < T; ++t) {
                int X = scanner.nextInt();
                int Y = scanner.nextInt();

                int start = Math.max(X - Y, 0);
                int end = X + Y;

                startLine[start] += 1;
                endLine[end] += 1;

                index.add(start);
                index.add(end);
            }

            int count = 0;
            int max = 0;
            Iterator<Integer> itr = index.iterator();
            while (itr.hasNext()) {
                int i = itr.next();
                if (startLine[i] > 0 && endLine[i] > 0) {
                    count += startLine[i];
                    max = Math.max(max, count);
                    count -= endLine[i];
                    continue;
                }
                count += startLine[i];
                count -= endLine[i];
                max = Math.max(max, count);
            }
            System.out.println(max);
        }
    }
}
