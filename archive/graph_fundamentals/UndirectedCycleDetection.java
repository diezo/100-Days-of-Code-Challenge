import java.util.ArrayList;
import java.util.List;

public class UndirectedCycleDetection {
    public static void main(String[] args) {
        int V = 6;

        int[][] edges = {
            {0, 1},
            {1, 2},
            {2, 3},
            {3, 0},
            {3, 4},
            {4, 5}
        };

        List<List<Integer>> graph = adjacencyList(V, edges);

        boolean cycle = detectUndirectedCycle(graph);

        if (cycle) System.out.println("Cycle exists");
        else System.out.println("No cycle exists");
    }

    private static boolean detectUndirectedCycle(List<List<Integer>> graph) {
        boolean[] visited = new boolean[graph.size()];

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                if (dfs(i, -1, graph, visited)) return true;
            }
        }

        return false;
    }

    private static boolean dfs(
        int node,
        int parent,
        List<List<Integer>> graph,
        boolean[] visited
    ) {
        visited[node] = true;

        for (int neighbor : graph.get(node)) {
            if (visited[neighbor]) {
                if (neighbor != parent) return true;
                continue;
            }

            if (dfs(neighbor, node, graph, visited)) {
                return true;
            }
        }

        return false;
    }

    private static List<List<Integer>> adjacencyList(int V, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        return graph;
    }
}
