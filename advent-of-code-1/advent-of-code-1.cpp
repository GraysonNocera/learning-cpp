#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

std::string find_calibration(std::string line);

int main(void) {

  std::ifstream file("advent-of-code-1.txt");
  std::string line;
  std::string calibration;
  int sum{0};
  if (!file.is_open()) {
    return EXIT_FAILURE;
  }

  while (!file.eof()) {
    std::getline(file, line);
    std::cout << line << std::endl;
    calibration = find_calibration(line);
    std::cout << calibration << std::endl;
    if (!calibration.empty()) {
      sum += std::stoi(calibration);
    }
  }

  std::cout << sum << std::endl;
}

std::string find_calibration(std::string line) {
  int li{0}, ri{static_cast<int>(line.length() - 1)};
  std::string l{""}, r{""};

  while (li < line.length()) {
    if (l.empty() && std::isdigit(line[li])) {
      l = line[li];
      break;
    }

    li++;
  }

  while (ri >= 0) {
    if (r.empty() && std::isdigit(line[ri])) {
      r = line[ri];
      break;
    }

    ri--;
  }

  return l + r;
}