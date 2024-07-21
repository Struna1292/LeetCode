class Solution {
public:
    string losingPlayer(int x, int y) {

        string prev = "Bob";

        while (true)
        {
            x--;
            y -= 4;

            if (x < 0 || y < 0)
            {
                break;
            }
            else
            {
                if (prev == "Alice")
                {
                    prev = "Bob";
                }
                else
                {
                    prev = "Alice";
                }
            }
        }

        return prev;
    }
};