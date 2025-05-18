#ifndef AGENT_H
#define AGENT_H

#include <vector>

class Agent {
public:
    // AI forgot default constructor
    Agent();
    Agent(int dimension);
    void update(const std::vector<float>& bestPos, float a, float b);
    float fitness;
    std::vector<float> position;
};

#endif
