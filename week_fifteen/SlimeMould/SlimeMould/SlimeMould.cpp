/*
* script: SlimeMould.cpp
* action: This program was built in partnership
*         with ChatGPT to showcase AI tools
* author: D.M & ChatGPT
* date: 17MAY25
*/

#include "SMA.h"
#include "Visualizer.h"
#include <chrono>
#include <thread>

int main() {
    SMA sma(10, 2); // 10 agents, 2D
    Visualizer vis;

    for (int i = 0; i < 20; ++i) {
        sma.iterate();
        vis.draw(sma, 20, 10); // 20x10 grid
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
