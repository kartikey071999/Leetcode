class Solution {
    public:
        int countDays(int total_days, vector<vector<int>>& meetings) 
        {
            vector<vector<int>> merged_intervals;
            sort(meetings.begin(), meetings.end());
    
            merged_intervals.push_back({meetings[0][0], meetings[0][1]});
            int n = meetings.size(), j = 0;
    
            for (int i = 1; i < n; ++i)
            {
                int start = meetings[i][0], end = meetings[i][1];
                if (start <= merged_intervals[j][1])
                {
                    if (merged_intervals[j][1] < end)
                        merged_intervals[j][1] = end;
                }
                else
                {
                    merged_intervals.push_back({start, end});
                    ++j;
                }
            }
    
            for (const auto& interval : merged_intervals)
            {
                int start = interval[0], end = interval[1];
                total_days -= (end - start + 1);
            }
    
            return total_days;
        }
    };
    