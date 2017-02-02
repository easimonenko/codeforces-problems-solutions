using System;
using System.Collections.Generic;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var t = Int32.Parse(Console.ReadLine().Trim());

            while (t > 0) {
                t--;
                var n = Int32.Parse(Console.ReadLine().Trim());
                var hash_names = new Dictionary<String, int>();
                hash_names.Add("", 0);
                var names = Console.ReadLine().Trim().Split();
                for (int k = 1; k <= n; k++) {
                    hash_names.Add(names[k], k);
                }

                var m = Int32.Parse(Console.ReadLine().Trim());

                var messages_names = new string[m + 2];
                var messages_texts = new string[m + 2];
                messages_names[0] = "";
                messages_names[m + 1] = "";

                var names_variants = new HashSet<int>();

                for (int i = 1; i <= m; i++) {
                    var line = Console.ReadLine().Trim().Split(new char[]{ ':' });
                    messages_names[i] = line[0];
                    messages_texts[i] = line[1];

                    if (messages_names[i] == "?") {
                        
                    }
                }
            }
        }
    }
}
