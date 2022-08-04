pybind11_add_module(add_example add_example.cpp)
install(TARGETS add_example
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/")