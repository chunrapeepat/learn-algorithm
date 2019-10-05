package ICPCSG18;

import java.util.Scanner;

public class KnightSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int length = N * N;
        String G = scanner.next();

        if (N <= 3) {
            System.out.println("NO");
            return;
        }

        boolean[] visited = new boolean[length];
        int[] countTable = new int[26];

        for (int i = 0; i < length; ++i) {
            if (G.charAt(i) != 'I') continue;
            knightMove(i, G, visited, countTable, N);
        }

        if (countTable['I' - 'A'] == 2 && countTable['C' - 'A'] == 2 && countTable['P' - 'A'] == 1 && countTable['A' - 'A'] == 2 && countTable['S' - 'A'] == 2 && countTable['G' - 'A'] == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static void knightMove(int i, String G, boolean[] visited, int[] countTable, int N) {
        if (i < 0 || i >= N * N) {
            return;
        }
        if (visited[i]) {
            return;
        }
        ++countTable[G.charAt(i) - 'A'];
        visited[i] = true;

        int a = 0;
        int b = 0;
        if (i != 0) {
            a = i / N;
            b = i % N;
        }

//        System.out.println(i + " -> " + a + " " + b + " Count: " + G.charAt(i));

        knightMove((a - 1) * N + (b - 2), G, visited, countTable, N);
        knightMove((a + 1) * N + (b - 2), G, visited, countTable, N);
        knightMove((a - 2) * N + (b - 1), G, visited, countTable, N);
        knightMove((a + 2) * N + (b - 1), G, visited, countTable, N);
        knightMove((a - 1) * N + (b + 2), G, visited, countTable, N);
        knightMove((a + 1) * N + (b + 2), G, visited, countTable, N);
        knightMove((a - 2) * N + (b + 1), G, visited, countTable, N);
        knightMove((a + 2) * N + (b + 1), G, visited, countTable, N);
    }
}
