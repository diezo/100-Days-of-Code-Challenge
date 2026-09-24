import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class TopologicalSort {
    private static List<Integer> topologicalSort(int V, int[][] edges) {
        List<List<Integer>> graph = adjacencyList(V, edges);
        int[] indegrees = constructIndegrees(graph);

        Queue<Integer> queue = new ArrayDeque<>();

        for (int i = 0; i < indegrees.length; i++) {
            if (indegrees[i] == 0) queue.offer(i);
        }

        List<Integer> res = new ArrayList<>();

        while (!queue.isEmpty()) {
            int node = queue.poll();
            res.add(node);

            for (int neighbor : graph.get(node)) {
                if (--indegrees[neighbor] == 0) queue.offer(neighbor);
            }
        }

        return res;
    }

    private static int[] constructIndegrees(List<List<Integer>> graph) {
        int[] indegrees = new int[graph.size()];

        for (List<Integer> node : graph) {
            for (int neighbor : node) {
                indegrees[neighbor]++;
            }
        }

        return indegrees;
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

    public static void main(String[] args) {
        int V = 6;

        int[][] edges = {
            {0, 2},
            {0, 3},
            {1, 3},
            {1, 4},
            {2, 5},
            {3, 5},
            {4, 5}
        };

        List<Integer> res = topologicalSort(V, edges);

        if (res.size() != V) System.out.println("Cycle detected!");
        else System.out.println("Topological order: " + res);
    }
}
