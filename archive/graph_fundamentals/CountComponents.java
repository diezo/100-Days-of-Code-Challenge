import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class CountComponents {
    public static void main(String[] args) {
        int n = 7;
        int[][] edges = {{0, 1}, {1, 2}, {3, 4}, {5, 6}};

        List<List<Integer>> graph = adjacencyList(n, edges);
        boolean[] visited = new boolean[graph.size()];

        int count = connectedComponents(graph, visited);

        System.out.println(count);
    }

    private static void dfs(int source, List<List<Integer>> graph, boolean[] visited) {
        Deque<Integer> stack = new ArrayDeque<>();

        stack.push(source);
        visited[source] = true;

        while (!stack.isEmpty()) {
            int node = stack.pop();

            for (int neighbor : graph.get(node)) {
                if (visited[neighbor]) continue;

                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    private static int connectedComponents(List<List<Integer>> graph, boolean[] visited) {
        int count = 0;

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                count++;
            }
        }

        return count;
    }

    private static List<List<Integer>> adjacencyList(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        return graph;
    }
}
