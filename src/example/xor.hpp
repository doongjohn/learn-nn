#pragma once

#include "neural_network.hpp"

static auto example_xor() -> void {
  NeuralNetwork nn(2, 2, 1);

  int a = 0;
  int b = 0;
  std::cin >> a;
  std::cin >> b;
  nn.feed_fowrard(a, b);
}
