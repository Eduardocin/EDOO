#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

struct statistic {
    double mean;
    double moda;
    double median;
};

statistic calculate_statistic(int* array, int size) {
    statistic s;
    s.mean = 0;
    s.moda = 0;
    s.median = 0;

    // Calcula a média
    for (int i = 0; i < size; i++) {
        s.mean += array[i];
    }
    s.mean /= size;

    // Calcula a mediana
    std::vector<int> sorted_array(array, array + size);
    std::sort(sorted_array.begin(), sorted_array.end());
    if (size % 2 == 0) {
        s.median = (sorted_array[size / 2 - 1] + sorted_array[size / 2]) / 2.0;
    } else {
        s.median = sorted_array[size / 2];
    }

    // Calcula a moda
    std::map<int, int> frequency;
    for (int i = 0; i < size; i++) {
        frequency[array[i]]++;
    }
    int max_count = 0;
    for (const auto& pair : frequency) {
        if (pair.second > max_count) {
            max_count = pair.second;
            s.moda = pair.first;
        }
    }

    return s;
}

int main() {
    int array[] = {1, 2, 2, 3, 4};
    int size = sizeof(array) / sizeof(array[0]);

    statistic s = calculate_statistic(array, size);

    std::cout << "Mean: " << s.mean << std::endl;
    std::cout << "Median: " << s.median << std::endl;
    std::cout << "Moda: " << s.moda << std::endl;

    return 0;
}