class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<int> people;

        for (int i = 0; i < tickets.size(); i++)
        {
            people.push(i);
        }

        int output = 0;

        while (!people.empty())
        {
            output++;

            int front = people.front();
            tickets[front]--;

            if (front == k && tickets[front] == 0)
            {
                break;
            }

            people.pop();

            if (tickets[front] > 0)
            {
                people.push(front);
            }

        }

        return output;
    }
};