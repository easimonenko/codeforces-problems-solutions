// Problem Id: 21A

using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var jabberId = Console.ReadLine();

            var answer = true;

            var usernameWithOthers = jabberId.Split('@');
            answer = answer && usernameWithOthers.Length == 2;

            var username = usernameWithOthers[0];
            answer = answer && username.Length != 0;

            answer = answer && Check(username);

            var hostnameWithResource = usernameWithOthers.Length > 1 ? usernameWithOthers[1].Split('/') : null;
            answer = answer && hostnameWithResource != null && hostnameWithResource.Length <= 2;

            var hostname = hostnameWithResource != null ? hostnameWithResource[0] : "";
            answer = answer && hostname.Length != 0 && hostname.Length <= 32;

            var domains = hostname.Split('.');
            foreach (var d in domains) {
                answer = answer && d != null && d.Length != 0 && Check(d);
            }

            var resource = hostnameWithResource != null ? (hostnameWithResource.Length == 2 ? hostnameWithResource[1] : null) : "";
            answer = answer && (resource == null || (resource != null && resource.Length != 0 && Check(resource)));

            Console.WriteLine(answer ? "YES" : "NO");
        }

        public static bool Check(string s)
        {
            if (s.Length > 16) {
                return false;
            }

            foreach (var c in s) {
                if (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_')) {
                    return false;
                }
            }

            return true;
        }
    }
}
