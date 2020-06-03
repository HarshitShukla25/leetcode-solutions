class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp=[](auto a,auto b){return a[1]-a[0]>b[1]-b[0];};  // this is the main line
        sort(costs.begin(),costs.end(),cmp);
        int ans=0;
        for(int i=0 ; i<costs.size() ; i++)
        {
            if(i<costs.size()/2) ans+=costs[i][0];
            else ans+=costs[i][1];
        }
        return ans;
    }
};
/*
EXPLANATION:-
The problem is to send n persons to city A 
and n persons to city B with minimum cost.

The idea is to send each person to city A.
costs = [[10,20],[30,200],[400,50],[30,20]]

So, totalCost = 10 + 30 + 400 + 30 = 470

Now, we need to send n persons to city B.
Which persons do we need to send city B?

Here, we need to minimize the cost.
We have already paid money to go to city A.
So, Send the persons to city B who get more refund
so that our cost will be minimized.

So, maintain refunds of each person
refund[i] = cost[i][1] - cost[i][0]

So, refunds of each person
    refund = [10, 170, -350, -10]

Here, refund +ve means we need to pay
             -ve means we will get refund.

So, sort the refund array.

refund = [-350, -10, 10, 170]

Now, get refund for N persons,
totalCost += 470 + -350 + -10 = 110

So, minimum cost is 110*/