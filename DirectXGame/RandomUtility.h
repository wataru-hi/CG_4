#pragma once
#include <random>

namespace RandomUtility {
inline std::random_device seedGenerator;
inline std::mt19937 randomEngine(seedGenerator());
inline std::uniform_real_distribution<float> distridution(-1.0f, 1.0f);
inline std::uniform_real_distribution<float> distridutionZero(0.0f, 1.0f);

inline float GetRandom() { return distridution(randomEngine); }

inline float GetRandomZeroToOne() { return distridutionZero(randomEngine); }
} // namespace RandomUtility
