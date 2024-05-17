include(CTest)

add_subdirectory(unit_test)

add_executable(TestTuple TestTuple.cpp ../Tuple.cpp)
target_include_directories(TestTuple PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(TestTuple PUBLIC "${PROJECT_SOURCE_DIR}/test")
target_include_directories(TestTuple PUBLIC "${PROJECT_SOURCE_DIR}/test/unit_test")

add_executable(TestEntity TestEntity.cpp ../Entity.cpp ../Tuple.cpp ../ForceVector.cpp)
target_include_directories(TestEntity PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(TestEntity PUBLIC "${PROJECT_SOURCE_DIR}/test")
target_include_directories(TestEntity PUBLIC "${PROJECT_SOURCE_DIR}/test/unit_test")

add_executable(TestForceVector TestForceVector.cpp ../ForceVector.cpp ../Tuple.cpp)
target_include_directories(TestForceVector PUBLIC "${PROJECT_SOURCE_DIR}")
target_include_directories(TestForceVector PUBLIC "${PROJECT_SOURCE_DIR}/test")
target_include_directories(TestForceVector PUBLIC "${PROJECT_SOURCE_DIR}/test/unit_test")

add_test(NAME TestTuple COMMAND TestTuple)
add_test(NAME TestEntity COMMAND TestEntity)
add_test(NAME TestForceVector COMMAND TestForceVector)