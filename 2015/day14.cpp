#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>


std::unordered_map<std::string, int> horse_map;
std::unordered_map<std::string, std::vector<int>> horse_data_map;
std::unordered_map<std::string, int> horse_points;

int distance_travelled(int time_limit, std::vector<int> horse_data) {
    int time_spent = 0;
    int _distance= 0;
    while(time_limit > time_spent) {
        if(time_limit-time_spent < horse_data[1]) {
            _distance += (time_limit-time_spent)*horse_data[0];
        }
        else {
            _distance+=horse_data[0]*horse_data[1];
        }
        time_spent+=(horse_data[1]+horse_data[2]);
    }
    return _distance;
}

void setup(std::vector<std::string> data, int time_limit) {
    std::string name = data[0];
    std::vector<int> horse_data;
    std::cout<<name<<std::endl;
    horse_data.push_back(std::stoi(data[3]));
    horse_data.push_back(std::stoi(data[6]));
    horse_data.push_back(std::stoi(data[13]));
    horse_map[name] = distance_travelled(time_limit, horse_data);
    horse_data_map[name] = horse_data;
    horse_points[name]=0;
}

int get_max() {
    int maxi=0;
    for(auto horse: horse_points) {
        maxi= std::max(maxi, horse.second);
    }
    return maxi;
}

void populate_point(int maxi) {
    for(auto i: horse_map) {
        if(i.second == maxi) {
            horse_points[i.first]++;
        }
    }
}

int get_max(int time_limit) {
    for(int i=1; i<=time_limit; i++) {
        int maxi=0;
        std::string name;
        for(auto horse:horse_data_map) {
            int distance = distance_travelled(i, horse.second);
            horse_map[horse.first] = distance;
            if(distance > maxi) {
                name=horse.first;
                maxi = distance;
            }
        }
        populate_point(maxi);
    }
    return get_max();
}


