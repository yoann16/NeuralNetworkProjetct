#ifndef UTILITY_H
#define UTILITY_H
#pragma once

#include <cmath>

[[nodiscard]] inline float sigmoid(float x)
{
	return 1.0f / (1.0f + std::expf(-x));
}
#endif