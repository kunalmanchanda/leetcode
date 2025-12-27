class Solution {
public:
    int bestClosingTime(string customers) {
        int openPenalty = 0;
        int closePenalty = 0;
        int n = customers.length();

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                closePenalty++;
            }
        }

        int hour = 0;
        int mini = openPenalty + closePenalty;

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                closePenalty--;
            } else {
                openPenalty++;
            }

            if(openPenalty + closePenalty < mini) {
                mini = openPenalty + closePenalty;
                hour = i + 1;
            }
        }

        return hour;
    }
};