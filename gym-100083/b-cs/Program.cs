using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            StreamReader reader;
            StreamWriter writer;
            #if (ONLINE_JUDGE)
            reader = new StreamReader("cycle2.in");
            writer = new StreamWriter("cycle2.out");
            #else
            reader = new StreamReader(Console.OpenStandardInput());
            writer = new StreamWriter(Console.OpenStandardOutput());
            #endif
            var inputNM = reader.ReadLine().Trim().Split();
            var n = Int32.Parse(inputNM[0]);
            var m = Int32.Parse(inputNM[1]);
            var graph = new List<int>[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new List<int>();
            }
            for (int i = 0; i < m; i++) {
                var line = reader.ReadLine().Trim().Split();
                var u = Int32.Parse(line[0]);
                var v = Int32.Parse(line[1]);
                graph[u - 1].Add(v - 1);
            }

            var colors = new Color[n];
            var cicle = new List<int>();
            var cicleStart = -1;
            DFS(graph, colors, 0, ref cicle, ref cicleStart);
            if (cicle.Count > 0) {
                writer.WriteLine("YES");
                writer.WriteLine(String.Join(" ", cicle.Select(x=> x+1).Reverse()));
            }
            else {
                writer.WriteLine("NO");
            }

            writer.Close();
        }

        static bool DFS(List<int>[] graph, Color[] colors, int u, ref List<int> cicle, ref int cicleStart) {
            var cicleFound = false;

            colors[u] = Color.Gray;

            for (int k = 0; k < graph[u].Count; k++) {
                var v = graph[u][k];
                if (colors[v] == Color.Black || colors[v] == Color.Gray) {
                    cicleStart = v;
                    cicle.Add(u);
                    cicleFound = true;
                    break;
                }
                else if (colors[v] == Color.White) {
                    cicleFound = DFS(graph, colors, v, ref cicle, ref cicleStart);
                    if (cicleStart != -1) {
                        if (cicleStart != u) {
                            cicle.Add(u);
                        }
                        else {
                            cicle.Add(cicleStart);
                            cicleStart = -1;
                        }
                            
                        break;
                    }
                }
            }

            colors[u] = Color.Black;

            return cicleFound;
        }

        enum Color {
            White, Gray, Black
        }
    }
}
