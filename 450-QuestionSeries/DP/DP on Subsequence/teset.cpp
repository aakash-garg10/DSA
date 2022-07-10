class Solution
{
public:
    bool canChange(string start, string target)
    {
        int startL = 0, startR = 0, targetL = 0, targetR = 0;
        vector<int> temp1;
        vector<int> temp2;
        for (auto i : start)
        {
            if (i != '_')
                temp1.push_back(i);
            if (i == 'L')
                startL++;
            else if (i == 'R')
                startR++;
        }
        for (auto i : target)
        {
            if (i != '_')
                temp2.push_back(i);
            if (i == 'L')
                targetL++;
            else if (i == 'R')
                targetR++;
        }
        if (startL == targetL && startR == targetR)
        {

            bool lag = 1;
            for (int i = 0; i < temp1.size(); i++)
            {
                if (start[temp1[i]] != target[temp2[i]])
                {
                    lag = 0;
                }
                else
                {
                    if (start[temp1[i]] == 'L')
                    {
                        if (temp1[i] < temp2[i])
                            lag = 0;
                    }
                    else
                    {
                        if (temp1[i] > temp2[i])
                            lag = 0;
                    }
                }
            }
            if (lag)
                return true;
            return false;
        }
        return false;
    }
};