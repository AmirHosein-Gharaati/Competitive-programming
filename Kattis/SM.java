import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SM {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        int num3 = scanner.nextInt();

        scanner.close();

        ArrayList<Integer> values = new ArrayList<>(16);
        for (int x : ops(num1, num2)) {
            values.addAll(ops(x, num3));
        }

        int smallest = Integer.MAX_VALUE;

        for (int num : values) {
            if (num >= 0 && num < smallest)
                smallest = num;
        }

        System.out.printf("%d", smallest);

        
    }

    public static List<Integer> ops(int x, int y) {
        ArrayList<Integer> res = new ArrayList<>(4);
        res.add(x + y);
        res.add(x - y);
        res.add(x * y);
        if (x % y == 0) res.add(x / y);
        return res;
    }
}
