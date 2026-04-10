class TimeMap {
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {}
    
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))  return "";
        auto &vec = mp[key];
        int  l=0;
        int r = vec.size()-1;
        string result = "";

        while(l<=r) {
            int mid = l +(r-l)/2;
            if(vec[mid].first <= timestamp) {
                result = vec[mid].second;
                l = mid +1;
            }else {
                r= mid-1;
            }
        }
        return result;
    }
};
