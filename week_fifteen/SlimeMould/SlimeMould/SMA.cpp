#include "SMA.h"
#include <algorithm>

SMA::SMA(int popSize, int dim) : a(1.0f), b(0.2f) {
    for (int i = 0; i < popSize; ++i)
        agents.emplace_back(dim);

    bestAgent = *std::min_element(agents.begin(), agents.end(),
        [](const Agent& a, const Agent& b) {
            return a.fitness < b.fitness;
        });
}

void SMA::iterate() {
    for (auto& agent : agents)
        agent.update(bestAgent.position, a, b);

    for (const auto& agent : agents)
        if (agent.fitness < bestAgent.fitness)
            bestAgent = agent;
}

const std::vector<Agent>& SMA::getAgents() const {
    return agents;
}