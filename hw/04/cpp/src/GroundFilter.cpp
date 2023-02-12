
#include "GroundFilter.h"

// -- LAS reading and writing
#include <lasreader.hpp>
#include <laswriter.hpp>

// -- CGAL delaunay triangulation
#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Delaunay_triangulation_2.h>

// -- CGAL kd-tree
#include <CGAL/Orthogonal_k_neighbor_search.h>
#include <CGAL/Search_traits_3.h>



void help_csf(const std::vector<Point>& pointcloud) {
  typedef CGAL::Search_traits_3<Kernel> TreeTraits;
  typedef CGAL::Orthogonal_k_neighbor_search<TreeTraits> Neighbor_search;
  typedef Neighbor_search::Tree Tree;

  // double resolution = jparams["resolution"];
  // double epsilon_zmax = jparams["epsilon_zmax"];
  // double epsilon_ground = jparams["epsilon_ground"];
  // std::string output_las = jparams["output_las"];

  //-- print the first 5 points in the pointcloud, which are CGAL Point_3
  //-- https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Point__3.html
  int i = 0;
  for (auto p : pointcloud) {
    std::cout << "(" << p.x() << ", " << p.y() << ", " << p.z()  << ")" << std::endl;
    i++;
    if (i == 5)
      break;
  }

  //-- TIP
  //-- construct and query kd-tree:
  // https://doc.cgal.org/latest/Spatial_searching/index.html#title5
  
  Tree tree(pointcloud.begin(), pointcloud.end());
  const unsigned int N = 1;
  Point query_point = Point(0,0,0);
  Neighbor_search search_result(tree, query_point, N);
  for(auto res : search_result) {
    Point neighbour_point = res.first;
    double distance = res.second;
  }
}



std::vector<Point> read_lasfile(std::string filename) {
  /*
  Function to read points from a LAS/LAZ file

  Inputs:
    filename:   the filename to read the LAS file to

  Returns:
    a std::vector<Point> with the points from the LAS file
  */
	LASreadOpener lasreadopener;
	lasreadopener.set_file_name(filename.c_str());
	LASreader* lasreader = lasreadopener.open();
	if (!lasreader){
		std::cerr << "cannot read las file: " << filename << "\n";
		exit(1);
	}
  //-- store each point in a CGAL Point_3 object
  //-- https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Point__3.html
	std::vector<Point> points;
	while (lasreader->read_point()) {
    // auto c = int(lasreader->point.get_classification());
    // std::cout << c << std::endl;
    // auto i = int(lasreader->point.get_intensity());
		points.push_back(
			Point(
				lasreader->point.get_x(),
				lasreader->point.get_y(),
				lasreader->point.get_z()
			)
		);
	}
	lasreader->close();
	delete lasreader;
	return points;
}

