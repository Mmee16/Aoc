#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


std::unordered_map<std::string, int> distance_map;
std::unordered_set<std::string> city_set;
void populate_distance_map(std::vector<std::string> inputs) {
    std::string city1 = inputs[0].substr(0,2);
    std::string city2 = inputs[2].substr(0,2);

    city_set.insert(city1);
    city_set.insert(city2);

    distance_map[city1+city2] = stoi(inputs[inputs.size()-1]);
}



