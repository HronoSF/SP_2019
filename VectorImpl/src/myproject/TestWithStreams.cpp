#include "Vector.h"
#include <fstream>
#include <random>
#include <algorithm>

int main() {
    Vector<std::ofstream> streams;
    for (int i = 1; i < 11; i++) {
        std::string name = std::to_string(i) + ".txt";
        std::ofstream outStream(name);
        streams.push_back(outStream);
    }
    shuffle(streams.begin(), streams.end(), std::random_device());
    int j = 1;
    std::cout << streams.size() << std::endl;
    for (auto &currentStream: streams) {
        currentStream << j;
        currentStream.close();
        j++;
    }
    return 0;
}