// Problem Id: 20A

using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var source_path = Console.ReadLine().Trim();
            var dirs = source_path.Split(new char[]{'/'}, StringSplitOptions.RemoveEmptyEntries);

            if (source_path[0] == '/') {
                Console.Write('/');
            }

            Console.WriteLine(String.Join("/", dirs));
        }
    }
}
