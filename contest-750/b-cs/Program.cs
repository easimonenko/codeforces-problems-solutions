using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());

            var ans = true;

            var prevHight = 0;
            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Trim().Split();
                var t = Int32.Parse(line[0]);
                var dir = line[1];

                if (i == 0 && dir != "South") {
                    ans = false;
                    break;
                }

                switch (dir) {
                    case "South":
                        if (prevHight + t > 20000) {
                            ans = false;
                        }
                        else {
                            prevHight += t;
                        }
                        break;
                    case "North":
                        if (prevHight - t < 0) {
                            ans = false;
                        }
                        else {
                            prevHight -= t;
                        }
                        break;
                    case "East":
                        if (prevHight == 0 || prevHight == 20000) {
                            ans = false;
                        }
                        break;
                    case "West":
                        if (prevHight == 0 || prevHight == 20000) {
                            ans = false;
                        }
                        break;
                }

                if (!ans) {
                    break;
                }
            }

            if (prevHight != 0) {
                ans = false;
            }

            Console.WriteLine(ans ? "YES" : "NO");
        }
    }
}
