cmake_minimum_required(VERSION 3.5.1)
project(grid_map_octomap)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## Find catkin macros and libraries
find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    grid_map_core
    grid_map_ros
    grid_map_cv
    filters
    grid_map_filters
)
find_package(octomap REQUIRED)
message(STATUS "Found Octomap (version ${octomap_VERSION}): ${OCTOMAP_INCLUDE_DIRS}")

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS
    include
    ${OCTOMAP_INCLUDE_DIRS}
  LIBRARIES
    ${PROJECT_NAME}
    ${OCTOMAP_LIBRARIES}
  CATKIN_DEPENDS
    grid_map_core
    grid_map_ros
    grid_map_cv
    roscpp
  DEPENDS
)

###########
## Build ##
###########

## Specify additional locations of header files
if(${octomap_VERSION} VERSION_LESS 1.8) # ROS Indigo and Jade.
  add_definitions(-DOCTOMAP_VERSION_BEFORE_ROS_KINETIC)
  include_directories(
    include
    SYSTEM
      ${catkin_INCLUDE_DIRS}
      ${OCTOMAP_INCLUDE_DIR}
  )
else() # ROS Kinetic and above.
  include_directories(
    include
    SYSTEM
      ${catkin_INCLUDE_DIRS}
      ${OCTOMAP_INCLUDE_DIRS}
  )
endif()

## Declare a cpp library
add_library(${PROJECT_NAME}
  src/GridMapOctomapConverter.cpp
  src/convert.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OCTOMAP_LIBRARIES}
)

add_dependencies(${PROJECT_NAME}
  ${catkin_EXPORTED_TARGETS}
)

#############
## Install ##
#############

# Mark executables and/or libraries for installation
install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Mark cpp header files for installation
install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
)

#############
## Testing ##
#############

if(CATKIN_ENABLE_TESTING)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

  # Add gtest based cpp test target and link libraries
  catkin_add_gtest(${PROJECT_NAME}-test
    test/test_grid_map_octomap.cpp
    test/OctomapConverterTest.cpp
  )
  target_include_directories(${PROJECT_NAME}-test PRIVATE
    include
  )
  target_include_directories(${PROJECT_NAME}-test SYSTEM PUBLIC
    ${catkin_INCLUDE_DIRS}
    ${OCTOMAP_INCLUDE_DIRS}
  )
  target_link_libraries(${PROJECT_NAME}-test
    ${PROJECT_NAME}
    ${OCTOMAP_LIBRARIES}
  )

  ###################
  ## Code_coverage ##
  ###################
  find_package(cmake_code_coverage QUIET)
  if(cmake_code_coverage_FOUND)
    add_gtest_coverage(
      TEST_BUILD_TARGETS
        ${PROJECT_NAME}-test
    )
  endif()
endif()

add_executable(convert_node src/convert.cpp)
target_link_libraries(convert_node
  ${PROJECT_NAME}
  ${OCTOMAP_LIBRARIES}
  ${catkin_LIBRARIES}
)


#################
## Clang_tools ##
#################
find_package(cmake_clang_tools QUIET)
if(cmake_clang_tools_FOUND)
  add_default_clang_tooling(
    DISABLE_CLANG_FORMAT
  )
endif(cmake_clang_tools_FOUND)