import java.util.ArrayList;
import java.util.List;

public class DirectedCycleDetection {
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

        boolean cycle = detectDirectedCycle(graph);

        if (cycle) System.out.println("Cycle exists");
        else System.out.println("No cycle exists");
    }

    private static boolean detectDirectedCycle(List<List<Integer>> graph) {
        int[] state = new int[graph.size()];

        for (int i = 0; i < graph.size(); i++) {
            if (state[i] == 0) {
                if (dfs(i, graph, state)) return true;
            }
        }

        return false;
    }

    private static boolean dfs(
        int node,
        List<List<Integer>> graph,
        int[] state
    ) {
        state[node] = 1;

        for (int neighbor : graph.get(node)) {
            if (state[neighbor] == 1) return true;
            if (state[neighbor] == 2) continue;

            if (dfs(neighbor, graph, state)) {
                return true;
            }
        }

        state[node] = 2;

        return false;
    }

    private static List<List<Integer>> adjacencyList(int V, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
        }

        return graph;
    }
}
