using System;
using System.Collections.Generic;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            var scores = new Dictionary<string, int>();
            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Trim().Split();
                var name = line[0];
                var score = Int32.Parse(line[1]);

                if (scores.ContainsKey(name)) {
                    scores[name] += score;
                }
                else {
                    scores.Add(name, score);
                }
            }

            string answer_name = "";
            int answer_score = 0;


            Console.WriteLine(answer_name);
        }
    }
}
