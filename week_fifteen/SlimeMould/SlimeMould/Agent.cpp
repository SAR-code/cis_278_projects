#include "Agent.h"
#include <cstdlib>
#include <cmath>

// AI forgot default constructor
Agent::Agent()
{
}

Agent::Agent(int dimension) : position(dimension), fitness(0.0f) {
    for (auto& x : position)
        x = static_cast<float>(rand() % 20); // random in 0-19
}

void Agent::update(const std::vector<float>& bestPos, float a, float b) {
    for (size_t i = 0; i < position.size(); ++i) {
        float delta = a * ((float)rand() / RAND_MAX - 0.5f);
        position[i] += delta;
    }
    fitness = 0.0f;
    for (float x : position)
        fitness += std::pow(x - 10, 2); // simple fitness
}