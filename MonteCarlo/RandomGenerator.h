#pragma once
#include <cmath>
#include <vector>

std::vector<double> randuniform(int n); // returns a vec of n Uniform(0,1) distributed reals
std::vector<double> randn(int n); // returns a vec of n N(0,1) distributed reals
std::vector<double> boxmuller(int n); // returns a vec of n N(0,1) distributed reals with the Box Muller algorithm



