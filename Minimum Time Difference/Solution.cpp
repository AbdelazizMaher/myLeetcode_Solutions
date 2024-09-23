class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int minTime = INT_MAX;
        int length = timePoints.size();

        sort(timePoints.begin(), timePoints.end());

        for (size_t i = 1; i < length; ++i) {
            int time = parseAndcompute(timePoints[i - 1], timePoints[i]);
            minTime = min(minTime, time);
        }

        int wrapAroundTime = parseAndcompute(timePoints[length - 1], timePoints[0]);
        minTime = min(minTime, wrapAroundTime);

        return minTime;
    }

    int parseAndcompute(string timePoint1, string timePoint2) {
        int delimiter1 = timePoint1.find(":");
        int delimiter2 = timePoint2.find(":");

        int time1 = stoi(timePoint1.substr(0, delimiter1)) * 60 + stoi(timePoint1.substr(delimiter1 + 1));
        int time2 = stoi(timePoint2.substr(0, delimiter2)) * 60 + stoi(timePoint2.substr(delimiter2 + 1));

        int minTime1 = abs(time1 - time2);
        int minTime2 = (24 * 60) - minTime1;
        return min(minTime1, minTime2); 
    }
};