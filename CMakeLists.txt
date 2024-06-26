cmake_minimum_required(VERSION 3.0)
project(logging_demo)

# 添加头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 添加源文件
set(SOURCES logging.cc)
set(TEST_SOURCES main.cc)

# 生成动态库
add_library(logging SHARED ${SOURCES})

# 添加可执行文件
add_executable(test_logging ${TEST_SOURCES})

# 添加链接库
target_link_libraries(test_logging logging)

# 设置输出目录
set_target_properties(logging PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
set_target_properties(test_logging PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

# 安装目标文件和头文件
#install(TARGETS logging DESTINATION /usr/local/lib)
#install(FILES logging.h DESTINATION /usr/local/include)

