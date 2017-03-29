using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var board = new char[3, 3];
            for (int i = 0; i < 3; i++) {
                var line = Console.ReadLine().Trim();
                board[i, 0] = line[0];
                board[i, 1] = line[1];
                board[i, 2] = line[2];
            }

            var zero = 0;
            var x = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    switch (board[i,j]) {
                        case 'X':
                            x += 1;
                            break;
                        case '0':
                            zero += 1;
                            break;
                        default:
                            break;
                    }
                }
            }

            var first = CheckWon('X', board);
            var second = CheckWon('0', board);

            if (x - zero > 1 || zero - x > 0) {
                Console.WriteLine("illegal");       
            }

            if (first && second) Console.WriteLine("illegal");
            if (!first && !second && x+zero==9) Console.WriteLine("illegal");
            if (!first && second && zero == x) Console.WriteLine("illegal");
            if (first && !second && x == zero+1) Console.WriteLine("illegal");

        }

        private static bool CheckWon(char c, char[,] board) {
            var left_diag = true;
            var right_diag = true;
            var cols = new bool[3];
            cols[0] = true;
            cols[1] = true;
            cols[2] = true;
            var rows = new bool[3];
            rows[0] = true;
            rows[1] = true;
            rows[2] = true;
            for (int i = 0; i < 3; i++) {
                if (board[i,i] != c) {
                    left_diag = false;
                }
                if (board[i, 2 - i] != c) {
                    right_diag = false;
                }
                for (int j = 0; j < 3; j++) {
                    if (board[i, j] != c) {
                        cols[j] = false;
                        rows[i] = false;
                    }
                }
            }
            return left_diag || right_diag || cols[0] || cols[1] || cols[2] || rows[0] || rows[1] || rows[2];
        }
    }
}
