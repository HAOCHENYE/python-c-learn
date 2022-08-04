pybind11_add_module(pet_example pet.cpp)
install(TARGETS pet_example
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/")