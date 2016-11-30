// Problem Id: 18A

using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var coords = new int[3, 2];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    coords[i, j] = Int32.Parse(line[i * 2 + j]);
                }
            }

            switch (CheckTriangle(coords)) {
                case Answer.RIGHT:
                    Console.WriteLine("RIGHT");
                    break;
                case Answer.ALMOST:
                    Console.WriteLine("ALMOST");
                    break;
                case Answer.NEITHER:
                    Console.WriteLine("NEITHER");
                    break;
            }
        }

        private static int[,] Offsets = new int[,]{ { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

        private enum Answer
        {
            NEITHER, ALMOST, RIGHT
        }

        private static Answer CheckTriangle(int[,] coords)
        {
            if (CheckRight(coords)) {
                return Answer.RIGHT;
            }
            else if (CheckAlmost(coords)) {
                return Answer.ALMOST;
            }
            else {
                return Answer.NEITHER;
            }
        }

        private static bool CheckRight(int[,] coords)
        {
            var a = Distance(coords, 0, 1);
            var b = Distance(coords, 1, 2);
            var c = Distance(coords, 0, 2);
            if (a == 0 || b == 0 || c == 0) {
                return false;
            }
            return a + c == b || a + b == c || b + c == a;
        }

        private static bool CheckAlmost(int[,] coords)
        {
            for (int i = 0; i < 3; i++) {
                for (int k = 0; k < Offsets.GetLength(0); k++) {
                    var c = (int[,])coords.Clone();
                    c[i, 0] += Offsets[k, 0];
                    c[i, 1] += Offsets[k, 1];
                    if (CheckRight(c)) {
                        return true;
                    }
                }
            }

            return false;
        }

        private static int Distance(int[,] coords, int first, int second)
        {
            return Square(coords[first, 0] - coords[second, 0]) + Square(coords[first, 1] - coords[second, 1]);
        }

        private static int Square(int value)
        {
            return value * value;
        }
    }
}
