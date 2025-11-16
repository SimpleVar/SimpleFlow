add_executable(simpleflow main.cpp)

target_include_directories(simpleflow PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
