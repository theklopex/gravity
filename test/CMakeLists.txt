include(CTest)

#add_subdirectory(unit_test)

add_executable(TestTuple TestTuple.cpp)
target_link_libraries(TestTuple Tuple)
target_include_directories(TestTuple PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(TestTuple PUBLIC "${PROJECT_SOURCE_DIR}/test")
target_include_directories(TestTuple PUBLIC "${PROJECT_SOURCE_DIR}/test/unit_test")

add_executable(TestEntity TestEntity.cpp)
target_link_libraries(TestEntity Entity)
target_include_directories(TestEntity PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(TestEntity PUBLIC "${PROJECT_SOURCE_DIR}/test")
target_include_directories(TestEntity PUBLIC "${PROJECT_SOURCE_DIR}/test/unit_test")

add_executable(TestVector TestVector.cpp)
target_link_libraries(TestVector Vector Tuple)
target_include_directories(TestVector PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(TestVector PUBLIC "${PROJECT_SOURCE_DIR}/test")
target_include_directories(TestVector PUBLIC "${PROJECT_SOURCE_DIR}/test/unit_test")

add_test(NAME TestTuple COMMAND TestTuple)
add_test(NAME TestEntity COMMAND TestEntity)
add_test(NAME TestVector COMMAND TestVector)