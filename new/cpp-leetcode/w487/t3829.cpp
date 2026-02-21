#include <bits/stdc++.h>
using namespace std;
class RideSharingSystem
{
private:
    queue<int> customers;
    queue<int> drivers;
    map<int, int> canceled;

public:
    RideSharingSystem()
    {
    }

    void addRider(int riderId)
    {
        canceled[riderId] = -1;
        customers.push(riderId);
    }

    void addDriver(int driverId)
    {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider()
    {
        if (drivers.empty())
        {
            return {-1, -1};
        }
        while (!customers.empty())
        {
            if (canceled[customers.front()] == 1)
            {
                customers.pop();
                continue;
            }
            vector<int> ans = {drivers.front(), customers.front()};
            drivers.pop();
            customers.pop();
            return ans;
        }
        return {-1, -1};
    }

    void cancelRider(int riderId)
    {
        if (canceled[riderId] == -1)
            canceled[riderId] = 1;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */