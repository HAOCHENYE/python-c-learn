from pet_example import Dog, Pet, Samoye, get_pet

pet = Pet('jenny')
print(pet.getName())
pet.setName('bob')
print(pet.getName())

dog = Dog('sara')
print(dog.bark())

samoye = Samoye('andy')
print(samoye.bark())

samoye.set('jack')
samoye.set(12)
print(f'age: {samoye.age}, name: {samoye.name}')
# Age and name are attribute of pybind11, not normal python instance attribute.
print(samoye.__dict__)

pet = get_pet('sandy')
print(pet.name)
