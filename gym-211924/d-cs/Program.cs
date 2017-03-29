using System;
using System.Collections.Generic;
using System.Collections;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var p = Console.ReadLine().Trim();
            var len = p.Length;
            var n = 2 * len + 1 + 2;
            var map = new bool[n, n];

            int x = n / 2;
            int y = n / 2;
            foreach (var c in p) {
                switch (c) {
                    case 'L':
                        x -= 1;
                        break;
                    case 'R':
                        x += 1;
                        break;
                    case 'U':
                        y -= 1;
                        break;
                    case 'D':
                        y += 1;
                        break;
                }
                map[x, y] = true;
            }

            if (len == BFS(map, n, x, y)) {
                Console.WriteLine("OK");
            }
            else {
                Console.WriteLine("BUG");
            }
        }

        private static int BFS(bool[,] map, int n, int x_finish, int y_finish) {
            var dists = new int[n, n];
            var qx = new Queue<int>();
            var qy = new Queue<int>();
            qx.Enqueue(n / 2);
            qy.Enqueue(n / 2);
            dists[n / 2, n / 2] = 0;
            map[n / 2, n / 2] = false;
            while (qx.Count != 0) {
                var x = qx.Dequeue();
                var y = qy.Dequeue();
                if (map[x - 1,y]) {
                    dists[x - 1, y] = dists[x,y] + 1;
                    map[x - 1, y] = false;
                    qx.Enqueue(x-1);
                    qy.Enqueue(y);
                }
                if (map[x + 1,y]) {
                    dists[x + 1, y] = dists[x,y] + 1;
                    map[x + 1, y] = false;
                    qx.Enqueue(x+1);
                    qy.Enqueue(y);
                }
                if (map[x,y - 1]) {
                    dists[x, y - 1] = dists[x,y] + 1;
                    map[x, y - 1] = false;
                    qx.Enqueue(x);
                    qy.Enqueue(y-1);
                }
                if (map[x, y + 1]) {
                    dists[x, y + 1] = dists[x,y] + 1;
                    map[x, y + 1] = false;
                    qx.Enqueue(x);
                    qy.Enqueue(y+1);
                }
            }

            return dists[x_finish, y_finish];
        }
    }
}
