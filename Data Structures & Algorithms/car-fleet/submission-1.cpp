class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {

        int n = pos.size();
        vector<pair<int,double>> cars;

        for(int i = 0; i < n; i++)
        {
            double time = (double)(target - pos[i]) / speed[i];
            cars.push_back({pos[i], time});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,double>>());

        int fleets = 0;
        double lastTime = 0;

        for(auto &car : cars)
        {
            if(car.second > lastTime)
            {
                fleets++;
                lastTime = car.second;
            }
        }

        return fleets;
    }
};