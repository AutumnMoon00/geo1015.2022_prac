
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Interpolation_traits_2.h>
#include <CGAL/natural_neighbor_coordinates_2.h>
#include <CGAL/interpolation_functions.h>
#include <vector>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>                   Delaunay_triangulation;
typedef CGAL::Interpolation_traits_2<K>                     Traits;
typedef K::FT                                               Coord_type;
typedef K::Point_2                                          Point2;

void nni_example();