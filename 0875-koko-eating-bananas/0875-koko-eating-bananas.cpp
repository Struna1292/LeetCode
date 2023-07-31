class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(begin(piles), end(piles));

        int left = 1;
        int right = piles[piles.size()-1];

        int answer = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int currHours = h;
            for (int i = 0; i < piles.size(); i++)
            {
                if (currHours < 0)
                    break;
                currHours -= ceil((double)piles[i] / (double)mid);
            }
            
            if (currHours >= 0)
            {
                answer = mid;
                right = mid - 1;             
            }
            else
            {
                left = mid + 1;
            }
        }

        return answer;
    }
};