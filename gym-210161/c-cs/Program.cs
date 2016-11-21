// Problem Id: 9A

using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var y = Int32.Parse(line[0]);
            var w = Int32.Parse(line[1]);

            var d = 7 - Math.Max(y, w);

            var answer = "";
            switch (d) {
                case 0:
                    answer = "0/1";
                    break;
                case 1:
                    answer = "1/6";
                    break;
                case 2:
                    answer = "1/3";
                    break;
                case 3:
                    answer = "1/2";
                    break;
                case 4:
                    answer = "2/3";
                    break;
                case 5:
                    answer = "5/6";
                    break;
                case 6:
                    answer = "1/1";
                    break;
            }

            Console.WriteLine(answer);
        }
    }
}
