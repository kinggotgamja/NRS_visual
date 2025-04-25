cmake_minimum_required(VERSION 3.0.2)
project(NRS_visual)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
  sensor_msgs
)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES Yoon_simul_cmd
 CATKIN_DEPENDS message_generation roscpp std_msgs sensor_msgs
 DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(NRS_VirUR_cmd src/NRS_VirUR_cmd.cpp)

target_link_libraries(NRS_VirUR_cmd
  ${catkin_LIBRARIES}
)
