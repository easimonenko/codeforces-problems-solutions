using System;
using System.Collections.Generic;

namespace ecs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var traffic = 0;

            string line;
            var members = new HashSet<string>();
            while ((line = Console.ReadLine()) != null) {
                if (line[0] == '+') {
                    members.Add(line.Substring(1));
                }
                else if (line[0] == '-') {
                    members.Remove(line.Substring(1));
                }
                else {
                    var message = line.Split(':')[1];
                    traffic += message.Length * members.Count;
                }
            }

            Console.WriteLine(traffic);
        }
    }
}
