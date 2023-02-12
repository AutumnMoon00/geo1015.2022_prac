cmake_minimum_required(VERSION 3.17)
project(geo1015.hw04)


# -- Dependencies
# cgal
find_package(CGAL QUIET COMPONENTS Core REQUIRED)
# laslib
add_subdirectory(external/LAStools)


add_executable(hw04 
  src/main.cpp
  src/GroundFilter.cpp
  src/DatasetASC.cpp
  src/nni.cpp
)
target_link_libraries(hw04 PRIVATE
  CGAL::CGAL CGAL::CGAL_Core
  LASlib
)
set_target_properties(hw04 PROPERTIES 
  CXX_STANDARD 17
)

# Make the executable a default target to build & run in Visual Studio
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT hw04)
