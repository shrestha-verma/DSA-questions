class Solution {
    int dateToDay(const string& date) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = day;
        for (int m = 0; m < month - 1; m++) {
            totalDays += daysInMonth[m];
        }
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = dateToDay(arriveAlice);
        int endA = dateToDay(leaveAlice);
        int startB = dateToDay(arriveBob);
        int endB = dateToDay(leaveBob);

        int overlapStart = max(startA, startB);
        int overlapEnd = min(endA, endB);

        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        return 0;
    }
};