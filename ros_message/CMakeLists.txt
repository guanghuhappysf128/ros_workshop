project(ros_tute_message)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
set(CMAKE_BUILD_TYPE Release)
add_definitions(-w -Wno-dev)

find_package(catkin REQUIRED COMPONENTS
  std_msgs
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

add_executable(${PROJECT_NAME}_listener
  listener.cpp
)

target_link_libraries(${PROJECT_NAME}_listener
  PUBLIC
  ${catkin_LIBRARIES}
)


target_include_directories(${PROJECT_NAME}_listener
  PRIVATE
  ${catkin_INCLUDE_DIRS}
)


