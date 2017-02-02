using System;
using System.Collections.Generic;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            var graph = new HashSet<int>[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new HashSet<int>();
            }
            for (int i = 0; i < n - 1; i++) {
                var line = Console.ReadLine().Trim().Split();
                var u = Int32.Parse(line[0]) - 1;
                var v = Int32.Parse(line[1]) - 1;
                graph[u].Add(v);
                graph[v].Add(u);
            }
            var colors = new int[n];
            var colors_line = Console.ReadLine().Trim().Split();
            for (int i = 0; i < n; i++) {
                colors[i] = Int32.Parse(colors_line[i]);
            }

            var used = new bool[n];
            DFS(graph, 0, used, colors);

            if (IsStar(graph)) {
                Console.WriteLine("YES");
                Console.WriteLine(FindCenter(graph) + 1);
            }
            else {
                Console.WriteLine("NO");
            }
        }

        private static void DFS(HashSet<int>[] graph, int u, bool[] used, int[] colors)
        {
            used[u] = true;
            var new_vertex_set = new HashSet<int>(graph[u]);
            var vertex_for_remove = new HashSet<int>();
            foreach (var v in graph[u]) {
                if (!used[v]) {
                    DFS(graph, v, used, colors);
                    if (colors[v] == colors[u] && graph[v].Count <= 1) {
                        new_vertex_set.UnionWith(graph[v]);
                        vertex_for_remove.Add(v);
                        vertex_for_remove.Add(u);
                        graph[v].Clear();
                    }
                }
            }
            graph[u] = new_vertex_set;
            graph[u].ExceptWith(vertex_for_remove);
        }

        private static bool IsStar(HashSet<int>[] graph)
        {
            var count = 0;
            for (int i = 0; i < graph.Length; i++) {
                if (graph[i].Count > 1) {
                    count += 1;
                }
            }

            return count <= 1;
        }

        private static int FindCenter(HashSet<int>[] graph)
        {
            var center = 0;
            var count = graph[0].Count;

            for (int i = 1; i < graph.Length; i++) {
                var next_count = graph[i].Count;
                if (next_count > count) {
                    count = next_count;
                    center = i;
                }
            }

            return center;
        }
    }
}
