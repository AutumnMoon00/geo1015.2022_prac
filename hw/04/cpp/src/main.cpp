//-- demo code to help you start
//-- Hugo Ledoux <h.ledoux@tudelft.nl>
//-- 2022-12-19


#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

//-- our GroundFilter functions
#include "GroundFilter.h"
#include "DatasetASC.h"
#include "nni.h"

int main(int argc, char** argv)
{
  //-- read a ASC grid
  std::string input_file = "/Users/hugo/data/ahn3/grid/ahn3_dsm50cm_bk_small_2.asc";
  DatasetASC ds(input_file);
  if (ds.validity == false) {
    return -1;
  } 

  //-- you could modify it
  ds.data[100][100] = 666.666;

  //-- write the array to a ASC file 
  ds.write("out.asc"); 

  //-- read pointcloud from input file
  // std::vector<Point> pointcloud = read_lasfile("/Users/hugo/data/ahn3/delft1.laz");
  std::vector<Point> pointcloud = read_lasfile("/Users/hugo/data/ahn3/crop.laz");
  std::cout << "Number of points " << pointcloud.size() << std::endl;
  std::cout << pointcloud[2] << std::endl;

  //-- help with CSF and handling pointclouds
  std::cout << "Help CSF" << std::endl;
  help_csf(pointcloud);

  //-- help with nni
  std::cout << "Help nni" << std::endl;
  nni_example();


  //-- we're done, return 0 to say all went fine
  return 0;
}
