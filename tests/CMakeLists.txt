find_package(GTest CONFIG REQUIRED)

add_executable(simpleflow_tests
    test_main.cpp
    test_input_source.cpp
    test_input_manager.cpp
    test_config.cpp
)

target_link_libraries(simpleflow_tests PRIVATE
    GTest::gtest_main
    tomlplusplus::tomlplusplus
    nlohmann_json::nlohmann_json
    Eigen3::Eigen
)
target_include_directories(simpleflow_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(simpleflow_tests)
