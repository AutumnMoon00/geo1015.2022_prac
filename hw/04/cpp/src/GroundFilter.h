
#include <string>
#include <vector>

// -- CGAL kernel
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

//-- this is a point in 3D: https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Point__3.html
typedef Kernel::Point_3 Point; 

std::vector<Point> read_lasfile(std::string filename);
void help_csf(const std::vector<Point>& pointcloud);