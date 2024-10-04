class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(begin(skill), end(skill));

        int i = 0;
        int j = skill.size()-1;

        int groupSkill = skill[i] + skill[j];

        long long output = 0;

        while (i < j)
        {
            if (skill[i] + skill[j] == groupSkill)
            {
                output += (skill[i] * skill[j]);
            }
            else
            {
                return -1;
            }

            i++;
            j--;
        }

        return output;
    }
};