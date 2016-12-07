// Problem Id: 24A

using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());

            var graph = new int[n, n];
            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Trim().Split();
                var a = Int32.Parse(line[0]);
                var b = Int32.Parse(line[1]);
                var c = Int32.Parse(line[2]);

                graph[a - 1, b - 1] = 1;
                graph[b - 1, a - 1] = c + 1;
            }

            var res1 = DFS(graph, 0, new Color[n], Direction.Forward) - n;
            var res2 = DFS(graph, 0, new Color[n], Direction.Backward) - n;

            Console.WriteLine(Math.Min(res1, res2));
        }

        private static int DFS(int[,] graph, int u, Color[] colors, Direction dir) {
            int result = 0;

            colors[u] = Color.Gray;

            for (int v = 0; v < colors.Length; v++) {
                if (graph[u,v] != 0) {
                    if (colors[v] == Color.White) {
                        switch (dir) {
                            case Direction.Forward:
                                result = graph[u, v];
                                break;
                            case Direction.Backward:
                                result = graph[v, u];
                                break;
                        }
                        result += DFS(graph, v, colors, dir);
                    }
                    else if (colors[v] == Color.Black) {
                        switch (dir) {
                            case Direction.Forward:
                                result += graph[v, u];
                                break;
                            case Direction.Backward:
                                result += graph[u, v];
                                break;
                        }
                        break;
                    }
                }
            }

            colors[u] = Color.Black;

            return result;
        }

        private enum Color
        {
            White, Gray, Black
        }

        private enum Direction
        {
            Forward, Backward
        }
    }
}
