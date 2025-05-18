#ifndef SMA_H
#define SMA_H

#include "Agent.h"
#include <vector>

class SMA {
public:
    SMA(int popSize, int dim);
    void iterate();
    const std::vector<Agent>& getAgents() const;

private:
    std::vector<Agent> agents;
    Agent bestAgent;
    float a, b;
};

#endif
