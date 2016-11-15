using System;
using System.Collections.Generic;

namespace ecs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            var color = new int[n];
            var line2 = Console.ReadLine().Trim().Split();
            for (int i = 0; i < n; i++) {
                color[i] = Int32.Parse(line2[i]);
            }
            var graph = new List<int>[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new List<int>();
            }
            for (int e = 1; e <= n - 1; e++) {
                var l = Console.ReadLine().Trim().Split();
                var u = Int32.Parse(l[0]) - 1;
                var v = Int32.Parse(l[1]) - 1;
                graph[u].Add(v);
                graph[v].Add(u);
            }

            int answer0 = 0;
            var color0 = (int[])color.Clone();
            for (int u = 0; u < n; u++) {
                if (color0[u] != 0) {
                    answer0 += 1;
                    BFS(graph, color0, u, 0);
                }
            }

            int answer1 = 0;
            var color1 = (int[])color.Clone();
            for (int u = 0; u < n; u++) {
                if (color1[u] != 1) {
                    answer1 += 1;
                    BFS(graph, color1, u, 1);
                }
            }

            Console.WriteLine(Math.Min(answer0, answer1));
        }

        static void BFS(List<int>[] graph, int[] color, int u, int c)
        {
            Queue<int> q = new Queue<int>();
            q.Enqueue(u);
            while (q.Count != 0) {
                int v = q.Dequeue();
                color[v] = c;
                foreach (var w in graph[v]) {
                    if (color[w] != c) {
                        q.Enqueue(w);
                    }
                }
            }
        }
    }
}
