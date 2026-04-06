class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int,int>> cars;
       for(int i=0;i<speed.size();i++) {
            cars.push_back({position[i],speed[i]});
       }
       sort(cars.rbegin(),cars.rend());
       double prevtime = 0.0;
       int fleets=1;
       prevtime = (double)(target - cars[0].first) / cars[0].second;
       for(int i=1;i<cars.size();i++) {
        double currtime = (double) (target-cars[i].first)/cars[i].second;
        if(currtime>prevtime) {
            fleets++;
            prevtime = currtime;
        }
       }
       return fleets;
    }
};
