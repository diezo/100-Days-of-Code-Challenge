package archive.graph_fundamentals;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BuildAdjacencyList {
    public static void main(String[] args) {
        int n = 5;
        int[][] edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}};

        List<List<Integer>> graph = buildGraph(n, edges);

        // printGraph(graph);

        // printNeighbors(0, graph);

        int[] degrees = graphDegrees(graph);

        System.out.println(Arrays.toString(degrees));
    }

    private static int[] graphDegrees(List<List<Integer>> graph) {
        int[] degrees = new int[graph.size()];

        for (int i = 0; i < graph.size(); i++) {
            degrees[i] = graph.get(i).size();
        }

        return degrees;
    }

    private static void printNeighbors(int x, List<List<Integer>> graph) {
        for (int i = 0; i < graph.get(x).size(); i++) {
            System.out.print(graph.get(x).get(i) + " ");
        }

        System.out.println();
    }

    private static List<List<Integer>> buildGraph(int n, int[][] edges) {
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

    private static void printGraph(List<List<Integer>> graph) {
        for (int i = 0; i < graph.size(); i++) {
            System.out.println(i + " -> " + graph.get(i));
        }
    }
}
