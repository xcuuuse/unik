#include <iostream>
#include <vector>
#include <algorithm>

class Stack {
private:
    std::vector<int> data;

public:
    void addNode(int newData) {
        data.push_back(newData);
        std::cout << "New element was successfully added!" << std::endl;
    }

    void displayData() {
        std::cout << "| ";
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << "|" << std::endl;
    }

    int find_min() {
        return *std::min_element(data.begin(), data.end());
    }

    int find_max() {
        return *std::max_element(data.begin(), data.end());
    }

    void remove_between_min_max() {
        int minValue = find_min();
        int maxValue = find_max();

        auto minIt = std::find(data.begin(), data.end(), minValue);
        auto maxIt = std::find(data.begin(), data.end(), maxValue);

        if (minIt == data.end() || maxIt == data.end() || minIt == maxIt) {
            std::cout << "No elements to remove between min and max." << std::endl;
            return;
        }

        // Удаляем элементы между min и max
        data.erase(minIt + 1, maxIt);
    }

    int count_between_min_max() {
        int minValue = find_min();
        int maxValue = find_max();

        auto minIt = std::find(data.begin(), data.end(), minValue);
        auto maxIt = std::find(data.begin(), data.end(), maxValue);

        if (minIt == data.end() || maxIt == data.end() || minIt == maxIt) {
            return 0;
        }

        return std::distance(minIt + 1, maxIt);
    }
};
