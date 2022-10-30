#pragma once

#include <Eigen/Dense>

#include "../utils.hpp"
#include "activation.hpp"

struct NeuralNetwork {
  int input_size;
  int hidden_size;
  int output_size;

  Eigen::MatrixXf weights_ih; // weights for input -> hidden
  Eigen::MatrixXf weights_ho; // weights for hidden -> output

  Eigen::VectorXf bias_h; // bias for hidden layer
  Eigen::VectorXf bias_o; // bias for output layer

  NeuralNetwork(int input_size, int hidden_size, int output_size)
    : input_size(input_size),
      hidden_size(hidden_size),
      output_size(output_size) {
    // initialize random weights
    weights_ih.resize(hidden_size, input_size);
    weights_ho.resize(output_size, hidden_size);
    fill_random_float(weights_ih, -0.5f, 0.5f);
    fill_random_float(weights_ho, -0.5f, 0.5f);

    // initialize random bias
    bias_h.resize(hidden_size);
    bias_o.resize(output_size);
    fill_random_float(bias_h, -0.5f, 0.5f);
    fill_random_float(bias_o, -0.5f, 0.5f);
  }

  auto feed_fowrard(Eigen::VectorXf inputs) -> Eigen::VectorXf {
    Eigen::MatrixXf hidden_result = (weights_ih * inputs) + bias_h;
    hidden_result.unaryExpr([](float x) { return sigmoid(x); });

    Eigen::MatrixXf output_result = (weights_ho * hidden_result) + bias_o;
    output_result.unaryExpr([](float x) { return sigmoid(x); });

    std::cout << "result:\n";
    std::cout << output_result << '\n';

    return Eigen::VectorXf(output_result);
    return Eigen::VectorXf(0);
  }

  template<typename... T>
  auto feed_fowrard(T ...input_list) -> Eigen::VectorXf {
    // https://www.scs.stanford.edu/~dm/blog/param-pack.html
    return feed_fowrard(initializer_list_to_vectorxf({float(input_list)...}));
  }

  auto train(Eigen::VectorXf inputs, float answer) -> void {
    // TODO: implement this
    // https://www.youtube.com/watch?v=r2-P1Fi1g60&list=PLRqwX-V7Uu6aCibgK1PTWWu9by6XFdCfh&index=15
  }
};
