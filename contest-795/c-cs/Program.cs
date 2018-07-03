using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());

            if (n == 2) {
                Console.WriteLine("1");
            }
            else {
                var numbersOnlyOnes = n / 2;
                var numbersWithSeven = (n - 3) / 2 + 1;
                if (numbersWithSeven >= numbersOnlyOnes) {
                    Console.Write("7");
                }
                else {
                    Console.Write("1");
                }
                for (int i = 1; i < n / 2; i++) {
                    Console.Write("1");
                }
                Console.WriteLine();
            }

        }
    }
}
