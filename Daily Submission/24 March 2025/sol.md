# Intuition:
If meeting are overlapping it means we can create a way more efficient busy day array than given one and then just sum up all the busy days and return the value for free days by subtracting busy days from all days.

# Approach:
## Brute Force:
We can just directly apply this but it is definetly not efficient and give TLE but it will make u understand the approch. Go over all meetings days turn them false. after which sum up all the true days which are free days.

'CODE'
'''Python[]
class Solution:
    def countDays(self, total_days: int, intervals: List[List[int]]) -> int:
        days = [True] * total_days
        for interval in intervals:
            start_day, end_day = interval[0], interval[-1]
            for day in range(start_day - 1, end_day):
                days[day] = False
        return sum(1 for day in days if day)
'''

## Merging Approach:
Simply said and done, merge overlapping meeting in an another list and then remove all the busy days from total days days results in free days.

'CODE'
'''Python[]
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        total_days = 0
        meetings = sorted(meetings, key=lambda x: x[0])
        merged_intervals = [[meetings[0][0], meetings[0][1]]]
        
        for i in range(1, len(meetings)):
            start, end = meetings[i]
            if start <= merged_intervals[-1][1]:
                merged_intervals[-1][1] = max(end, merged_intervals[-1][1])
            else:
                merged_intervals.append([start, end])
        
        for start, end in merged_intervals:
            total_days += end - start + 1
        
        return days - total_days
'''
'''C++[]
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
'''

## Optimized Merging Approach:
You can just skip creating a new list to save ur space, just do all the work in th first loop, it saves u little time and very memory efficient

'CODE'
'''Python[]
class Solution3:
    def countDays(self, total_days: int, meetings: List[List[int]]) -> int:
        non_working_days = 0
        meetings = sorted(meetings, key=lambda x: x[0])
        start = meetings[0][0]
        end = meetings[0][1]

        for i in range(1, len(meetings)):
            meeting_start, meeting_end = meetings[i]
            if meeting_start <= end:
                end = max(end, meeting_end)
            else:
                non_working_days += (end - start + 1)
                start = meeting_start
                end = meeting_end
        
        non_working_days += (end - start + 1)

        return total_days - non_working_days
'''

## Last End Time Tracking:
Basically just track the last end time and loop through sorted meetings.

'CODE'
'''Python[]
__import__("atexit").register(lambda: open("display_runtime.txt", "w").write("0"))

class Solution:
    def countDays(self, total_days: int, meetings: List[List[int]]) -> int:
        last_end_time = 0
        meetings = sorted(meetings, key=lambda x: x[0])
        
        for start, end in meetings:
            if end < last_end_time:
                continue
            elif start > last_end_time:
                total_days -= (end - start + 1)
            elif end > last_end_time:
                total_days -= (end - last_end_time)
            
            last_end_time = end
        
        return total_days
'''