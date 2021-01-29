#pragma once

#include <unordered_map>

#include "rv/LaserscanReader.h"

std::unordered_map<std::string, double> find_best_params(const rv::Laserscan& scan);