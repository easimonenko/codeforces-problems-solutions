// Problem Id: 16A

using System;

namespace ecs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var m = Int32.Parse(line1[1]);

            var answer = true;

            var flag_line = Console.ReadLine().Trim();
            for (int j = 1; j < m; j++) {
                if (flag_line[j] != flag_line[j - 1]) {
                    answer = false;
                    break;
                }
            }

            if (answer) {
                for (int i = 1; i < n; i++) {
                    var flag_line_next = Console.ReadLine().Trim();
                    if (flag_line_next[0] == flag_line[0]) {
                        answer = false;
                        break;
                    }
                    for (int j = 1; j < m; j++) {
                        if (flag_line_next[j] != flag_line_next[j - 1]) {
                            answer = false;
                            break;
                        }
                    }
                    if (answer) {
                        flag_line = flag_line_next;
                    }
                    else {
                        break;
                    }
                }
            }

            Console.WriteLine(answer ? "YES" : "NO");
        }
    }
}
