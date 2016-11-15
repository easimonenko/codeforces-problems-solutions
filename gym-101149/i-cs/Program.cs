using System;
using System.Collections.Generic;

namespace ics
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int n, m;
            var line1 = Console.ReadLine().Split();
            n = Int32.Parse(line1[0]);
            m = Int32.Parse(line1[1]);
            var graph = new List<int>[n];
            for (int u = 0; u < n; u++) {
                graph[u] = new List<int>();
            }
            for (int i = 0; i < m; i++) {
                var linei = Console.ReadLine().Split();
                var u = Int32.Parse(linei[0]) - 1;
                var v = Int32.Parse(linei[1]) - 1;
                graph[u].Add(v);
                graph[v].Add(u);
            }

            var degplus = new long[n];
            for (int u = 0; u < n; u++) {
                foreach (var v in graph[u]) {
                    degplus[u] += graph[v].Count;
                }
            }
                
            int idx = 0;
            for (int u = 1; u < n; u++) {
                if (degplus[u] < degplus[idx]) {
                    idx = u;
                }
            }

            var answer = new int[n];
            for (int u = 0; u < n; u++) {
                answer[u] = 1;
            }
            answer[idx] = 0;
            foreach (var v in graph[idx]) {
                answer[v] = 0;
            }

            Console.WriteLine(String.Join(" ", answer));
        }
    }
}
