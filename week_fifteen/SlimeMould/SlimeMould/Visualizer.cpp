#include "Visualizer.h"
#include <iostream>
#include <vector>

void Visualizer::draw(const SMA& sma, int width, int height) {
    std::vector<std::vector<char>> grid(height, std::vector<char>(width, '.'));

    for (const auto& agent : sma.getAgents()) {
        int x = static_cast<int>(agent.position[0]);
        int y = static_cast<int>(agent.position[1]);
        if (x >= 0 && x < width && y >= 0 && y < height)
            grid[y][x] = '#';
    }

    for (const auto& row : grid) {
        for (char cell : row)
            std::cout << cell << ' ';
        std::cout << '\n';
    }
    std::cout << "---------------------------\n";
}