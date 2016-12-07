// Problem Id: 23A

using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var s = Console.ReadLine().Trim();

            var answer = 0;

            for (var i = 0; i < s.Length - answer; i++) {
                for (var j = i + 1; j < s.Length - answer; j++) {
                    if (s[i] == s[j]) {
                        int k = 0;
                        for (; k < s.Length - j; k++) {
                            if (s[i + k] != s[j + k]) {
                                break;
                            }
                        }
                        if (k > answer) {
                            answer = k;
                        }
                    }
                }
            }

            Console.WriteLine(answer);
        }
    }
}
