project(ros_tute_node)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
set(CMAKE_BUILD_TYPE Release)
add_definitions(-w -Wno-dev)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  )

catkin_package(
  INCLUDE_DIRS
)

add_executable(${PROJECT_NAME}_node
  main.cpp
)

target_link_libraries(${PROJECT_NAME}_node
  PUBLIC
  ${catkin_LIBRARIES}
)


target_include_directories(${PROJECT_NAME}_node
  PRIVATE
  ${catkin_INCLUDE_DIRS}
)