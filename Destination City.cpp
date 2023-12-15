

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        set<string> startCities;

        // Store all starting cities in a set
        for (const auto& path : paths) {
            startCities.insert(path[0]);
        }

        // Find the destination city
        for (const auto& path : paths) {
            if (startCities.find(path[1]) == startCities.end()) {
                return path[1]; // Return the destination city
            }
        }

        return ""; // If no destination city found (shouldn't reach here if every path is valid)
    }
};

