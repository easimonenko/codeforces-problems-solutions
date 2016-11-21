// Problem Id: 8A

using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var s = Console.ReadLine().Trim();
            var sub1 = Console.ReadLine().Trim();
            var sub2 = Console.ReadLine().Trim();

            var first_forward = false;
            var forward_idx1 = -1;
            for (int i = 0; i < s.Length - sub1.Length; i++) {
                bool ok = true;
                for (int j = 0; j < sub1.Length; j++) {
                    if (s[i + j] != sub1[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    first_forward = true;
                    forward_idx1 = i;
                    break;
                }
            }

            var second_forward = false;
            if (first_forward) {
                for (int i = forward_idx1 + sub1.Length; i < s.Length - sub2.Length + 1; i++) {
                    bool ok = true;
                    for (int j = 0; j < sub2.Length; j++) {
                        if (s[i + j] != sub2[j]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        second_forward = true;
                        break;
                    }
                }
            }

            var first_backward = false;
            var backward_idx1 = -1;
            for (int i = s.Length - 1; i >= sub1.Length - 1; i--) {
                bool ok = true;
                for (int j = 0; j < sub1.Length; j++) {
                    if (s[i - j] != sub1[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    first_backward = true;
                    backward_idx1 = i;
                    break;
                }
            }

            var second_backward = false;
            if (first_backward) {
                for (int i = backward_idx1 - sub1.Length; i >= sub2.Length - 1; i--) {
                    bool ok = true;
                    for (int j = 0; j < sub2.Length; j++) {
                        if (s[i - j] != sub2[j]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        second_backward = true;
                        break;
                    }
                }
            }


            var forward = first_forward && second_forward;
            var backward = first_backward && second_backward;
            var answer = (forward ? (backward ? "both" : "forward") : (backward ? "backward" : "fantasy"));

            Console.WriteLine(answer);
        }
    }
}
