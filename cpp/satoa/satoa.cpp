#include <Eigen/Dense>


namespace satoa {
Eigen::Vector3d foo(
    const Eigen::Vector3d &x,
    double k
) {
    Eigen::Vector3d output = k * x;
	return output;
}
} // namespace satoa
