#pragma once

#include <math.h>

static auto step(float input) -> int {
  // https://en.wikipedia.org/wiki/Heaviside_step_function
  int output = input > 0 ? 1 : 0; // -> 0 or 1
  return output;
}

static auto sigmoid(float input) -> float {
  // https://en.wikipedia.org/wiki/Sigmoid_function
  return 1.f / (1 + exp(-input));
}
