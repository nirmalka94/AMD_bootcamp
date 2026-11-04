cmake_minimum_required(VERSION 3.8)
project(robot_status_node_solutions)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Main assignment reference.
add_executable(robot_status_node robot_status_node.cpp)
ament_target_dependencies(robot_status_node rclcpp std_msgs std_srvs)

# Both challenges.
add_executable(robot_status_node_challenges robot_status_node_challenges.cpp)
ament_target_dependencies(robot_status_node_challenges rclcpp std_msgs std_srvs)

# Exam Part A.
add_executable(cmd_vel_listener cmd_vel_listener.cpp)
ament_target_dependencies(cmd_vel_listener rclcpp geometry_msgs)

install(TARGETS robot_status_node robot_status_node_challenges cmd_vel_listener
  DESTINATION lib/${PROJECT_NAME})

ament_package()
