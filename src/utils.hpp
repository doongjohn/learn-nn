#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>

#include <Eigen/Dense>

static auto random_int(int min, int max) -> int {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);
  return distr(gen);
}

static auto random_float(float min, float max) -> float {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> distr(min, max);
  return distr(gen);
}

static auto initializer_list_to_vectorxf(std::initializer_list<float> list) -> Eigen::VectorXf {
  Eigen::VectorXf result(list.size());
  int i = 0;
  for (auto n : list) {
    result[i++] = n;
  }
  return result;
}

static auto fill_random_int(Eigen::VectorXf &vec, int min, int max) -> void {
  for (int i = 0; i < vec.size(); ++i) {
    vec[i] = random_int(min, max);
  }
}

static auto fill_random_float(Eigen::VectorXf &vec, float min, float max) -> void {
  for (int i = 0; i < vec.size(); ++i) {
    vec[i] = random_float(min, max);
  }
}

static auto fill_random_int(Eigen::MatrixXf &mat, int min, int max) -> void {
  for (int col = 0; col < mat.cols(); ++col) {
    for (int row = 0; row < mat.rows(); ++row) {
      mat(row, col) = random_int(min, max);
    }
  }
}

static auto fill_random_float(Eigen::MatrixXf &mat, float min, float max) -> void {
  for (int col = 0; col < mat.cols(); ++col) {
    for (int row = 0; row < mat.rows(); ++row) {
      mat(row, col) = random_float(min, max);
    }
  }
}

static auto read_file(const std::string path) -> std::string {
  std::string result = "";
  std::fstream fs;
	fs.open(path, std::ios::in);
	if (!fs) {
    std::cout << "failed to open file!\n";
	} else {
    std::stringstream ss;
    ss << fs.rdbuf();
    result = ss.str();
	}
  fs.close();
  return result;
}
