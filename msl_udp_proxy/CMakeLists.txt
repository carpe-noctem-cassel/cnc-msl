cmake_minimum_required(VERSION 2.8.3)
project(msl_udp_proxy)

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED system_config roscpp roslib sensor_msgs msl_sensor_msgs process_manager)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system filesystem regex)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
#add_message_files(
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

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
# INCLUDE_DIRS include
# LIBRARIES 
 CATKIN_DEPENDS system_config roscpp roslib sensor_msgs msl_sensor_msgs process_manager
 DEPENDS system filesystem regex
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

# Please note, that the following command does not work, if you compile your workspace the first time, because rosrun does not know anything about udp_proxy_generator in that case.
# We could exchange the command with something more ROS-Independent, like calling the binary without rosrun.
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/proxy_gen/ros2udpProxy.cpp
    #COMMAND rosrun udp_proxy_generator udp_proxy_generator ${PROJECT_NAME}
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../../../devel/lib/udp_proxy_generator/udp_proxy_generator ${PROJECT_NAME}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/relayMsgs.conf udp_proxy_generator
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "${PROJECT_NAME}: Generating Code ..."
)

## Declare a cpp executable
add_executable(${PROJECT_NAME}
  proxy_gen/ros2udpProxy.cpp
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${Boost_LIBRARIES})

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(${PROJECT_NAME} ${catkin_LIBRARIES} ${Boost_LIBRARIES} msl_sensor_msgs_gencpp msl_msgs_msgs_gencpp process_manager_msgs_gencpp)