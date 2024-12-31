class Solution {
    vector<int> day, cost, dp;
public:
    int solve(int i) {
        int n = day.size();
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int oneDayCost = 0, sevenDayCost = 0, thirtyDayCost = 0;

        oneDayCost = cost[0] + solve(i + 1);

        int j = i;
        while(j < n && day[j] - day[i] < 7) {
            j++;
        }

        sevenDayCost = cost[1] + solve(j);

        j = i;
        while(j < n && day[j] - day[i] < 30) {
            j++;
        }
        
        thirtyDayCost = cost[2] + solve(j);

        if(oneDayCost <= sevenDayCost && oneDayCost <= thirtyDayCost) {
            return dp[i] = oneDayCost;
        } else if(sevenDayCost <= oneDayCost && sevenDayCost <= thirtyDayCost) {
            return dp[i] = sevenDayCost;
        } else {
            return dp[i] = thirtyDayCost;
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n+1, -1);
        day = days, cost = costs;

        return solve(0);
    }
};