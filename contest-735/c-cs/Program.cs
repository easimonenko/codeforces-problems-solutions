using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int64.Parse(Console.ReadLine().Trim());

            int answer = 0;

            while (n >= 2) {
                answer += 1;
                if (n % 2 != 0) {
                    answer += 1;
                }
                n >>= 1;
            }

            Console.WriteLine(answer);
        }
    }
}
