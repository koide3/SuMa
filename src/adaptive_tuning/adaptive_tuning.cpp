#include "adaptive_tuning.hpp"

#include <vector>
#include <Eigen/Core>

std::unordered_map<std::string, double> find_best_params(const rv::Laserscan& scan) {
  auto points_ = scan.points();

  std::vector<Eigen::Vector3f, Eigen::aligned_allocator<Eigen::Vector3f>> points(points_.size());
  for(int i=0; i<points_.size(); i++) {
    points[i] = points_[i].vec.head<3>();
  }

  std::unordered_map<std::string, double> params;
  return params;

}