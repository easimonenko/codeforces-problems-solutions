using System;

namespace fcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var sides = new int[4];
            for (int i = 0; i < 4; i++) {
                sides[i] = Int32.Parse(line[i]);
            }

            var answer = "IMPOSSIBLE";
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (j != i) {
                        for (int k = 0; k < 4; k++) {
                            if (k != i && k != j) {
                                if (sides[i] + sides[j] > sides[k]
                                    && sides[i] + sides[k] > sides[j]
                                    && sides[j] + sides[k] > sides[i]) {
                                    answer = "TRIANGLE";
                                }
                                else if (sides[i] + sides[j] == sides[k]
                                    || sides[i] + sides[k] == sides[j]
                                    || sides[j] + sides[k] == sides[i]) {
                                    if (answer != "TRIANGLE") {
                                        answer = "SEGMENT";
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Console.WriteLine(answer);
        }
    }
}
