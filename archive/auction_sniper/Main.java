import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class Result {
    int[] flag;
    int[] smallest;
}

public class Main {
    private static Result solve(int N, int M, int K, int t[], int[] b) {
        int[] flag = new int[N];
        int[] smallest = new int[N];

        HashMap<Integer, Integer> bids = new HashMap<>();

        int i = 0;

        for (int j = 0; j < N; j++) {
            int uid = b[j];

            int user_bids = (bids.get(uid) == null ? 0 : bids.get(uid));
            bids.put(uid, ++user_bids);

            while ((t[j] - t[i]) > M) {
                bids.put(b[i], bids.get(b[i]) - 1);
                i++;
            }

            int user_flag = 0;
            Integer min = null;

            for (Map.Entry<Integer, Integer> entry : bids.entrySet()) {
                int cur_uid = entry.getKey();
                int cur_bids = entry.getValue();

                if (cur_bids >= K) {
                    if (cur_uid == uid) user_flag = 1;
                    min = (min == null ? cur_uid : Math.min(min, cur_uid));
                }
            }

            flag[j] = user_flag;
            smallest[j] = (min == null ? -1 : min);
        }

        // Return result
        Result result = new Result();
        result.flag = flag;
        result.smallest = smallest;

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N, M, K;

        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();

        int[] t = new int[N];
        int[] b = new int[N];

        for (int i = 0; i < N; i++) {
            t[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }

        sc.close();

        Result result = solve(N, M, K, t, b);

        // Print output
        for (int i = 0; i < N; i++) {
            System.out.println(result.flag[i] + " " + result.smallest[i]);
        }
    }
}