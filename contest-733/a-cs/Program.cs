using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim();

            var answer = 1;
            var s = line + "A";
            var c = 1;
            for (int i = 0; i < s.Length; i++) {
                if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O'
                    && s[i] != 'U' && s[i] != 'Y') {
                    c += 1;
                }
                else {
                    if (c > answer) {
                        answer = c;
                    }
                    c = 1;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
    