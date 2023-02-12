#include "nni.h"


void nni_example() {
  //-- define 2D points
  std::vector<Point2> points;
  points.push_back(Point2(0, 0));
  points.push_back(Point2(10, 0));
  points.push_back(Point2(10, 10));
  points.push_back(Point2(0,10));
  points.push_back(Point2(5,5));

  //-- define their respective z-values
  std::vector<Coord_type> zs;
  zs.push_back(0.0);
  zs.push_back(0.0);
  zs.push_back(0.0);
  zs.push_back(0.0);
  zs.push_back(10.0);


  //-- standard typedef for this CGAL package, complex but this it
  typedef std::map<Point2, Coord_type, K::Less_xy_2>         Coord_map;
  typedef CGAL::Data_access<Coord_map>                      Value_access;
  Coord_map value_function;

  Delaunay_triangulation T;
  for (int i=0 ; i<points.size() ; i++){
    T.insert(points[i]); //-- insert points in DT
    value_function.insert(std::make_pair(points[i], zs[i])); //-- link the z-value
  }

  //-- interpolate at location p
  Point2 p(5.3, 6.34);
  std::vector<std::pair<Point2, Coord_type> > coords;
  //-- calculate the natural neighbour coordinates for p
  Coord_type norm = CGAL::natural_neighbor_coordinates_2(T, p, std::back_inserter(coords)).second;
  //-- interpolate with nni
  Coord_type res =  CGAL::linear_interpolation(coords.begin(), coords.end(), norm,
                                               Value_access(value_function));
  std::cout << "(" << p << ") = " << res << std::endl;
}

