using System;
using System.Globalization;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            var po = new int[n];
            var po_input = Console.ReadLine().Trim().Split();
            for (int i = 0; i < n; i++) {
                po[i] = Int32.Parse(po_input[i]);
            }
            var co = new int[n];
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ()
                }
            }
        }
    }
}
