// Problem Id: 7A

using System;

namespace gcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var board = new string[8];
            for (int i = 0; i < 8; i++) {
                board[i] = Console.ReadLine().Trim();
            }

            var answer = 0;
            for (int j = 0; j < 8; j++) {
                if (board[0][j] == 'B') {
                    bool vert = true;
                    for (int i = 0; i < 8; i++) {
                        if (board[i][j] != 'B') {
                            vert = false;
                            break;
                        }
                    }
                    if (vert) {
                        answer += 1;
                        for (int i = 0; i < 8; i++) {
                            board[i][j] = 'W'                            }
                        }
                    }

                }
            }
            for (int i = 0; i < 8; i++) {
                if (board[i][0] == 'B') {
                    answer += 1;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
