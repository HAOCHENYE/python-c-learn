#include <pybind11/attr.h>
#include <pybind11/pybind11.h>

/*These codes are inferred from https://pybind11.readthedocs.io/en/stable/classes.html*/
namespace py = pybind11;

struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

    void set(int age_) { age = age_; }
    void set(const std::string &name_) { name = name_; }
    std::string name;
    int age;
};

struct Dog: public Pet
{
    Dog(const std::string &name) : Pet(name) { }
    std::string bark() const { return "woof!"; }
};

struct Samoye: public Dog
{
    Samoye(const std::string &name) : Dog(name) { }
    std::string bark() const { return "woof woof!"; }
};

Pet get_pet(const std::string & name)
{
    return Pet(name);
}

PYBIND11_MODULE(pet_example, m) {
    /*dynamic_attr make Pet can have dynamic attribute*/
    py::class_<Pet>(m, "Pet", py::dynamic_attr())
        .def("set", static_cast<void (Pet::*)(int)>(&Pet::set), "Set the pet's age")
        .def("set", static_cast<void (Pet::*)(const std::string &)>(&Pet::set), "Set the pet's name")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def_readwrite("name", &Pet::name)  /*make pet.name can be read and write*/
        .def_readwrite("age", &Pet::age);  /*make pet.age can be read and write*/


    /*inherit by template*/
    py::class_<Dog, Pet> dog(m, "Dog");
        dog.def(py::init<const std::string &>());
        dog.def("bark", &Dog::bark);

    /*inherit by parameter*/
    py::class_<Samoye, Dog>(m, "Samoye")
        .def(py::init<const std::string &>())
        .def("bark", &Samoye::bark);

    m.def("get_pet", &get_pet, "get a pet");
}