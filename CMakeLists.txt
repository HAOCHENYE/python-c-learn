set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(PYTHON_EXECUTABLE /mnt/data/yehaochen/miniconda3/bin/python)
set(PYTHON_EXECUTABLE /mnt/data/yehaochen/miniconda3/envs/pytorch1.12python38/bin/python)
# include_directories("/mnt/data/yehaochen/miniconda3/envs/pytorch1.12python38/include")
# include_directories("/mnt/data/yehaochen/miniconda3/envs/pytorch1.12python38/include/python3.8/")
add_subdirectory(pybind11)
add_subdirectory("src/add_example")
add_subdirectory("src/pet_example")
add_compile_options(-G)


