class Dog():
  name = ""
  age = 0
  __breed = None
  def __init__(self, dog_name, dog_age, dog_breed):
    self.name = dog_name
    self.age = dog_age
    self.__breed = dog_breed #encapsulated

  def speak(self, sound):
    print(self.name, "says", sound)

  def run(self, speed):
    print(self.name, "runs", speed, "mph")

  def description(self):
    print(self.name, "is a", self.age,  "year old", self.__breed)

  def define_buddy(self, buddy):
    self.buddy = buddy
    buddy.buddy = self

scout = Dog("Scout", 2, "Belgian Malinois")
print(scout)
print(scout.name)
print(scout.age)

# Question 1: the output of print(scout) is <__main__.Dog object at 0x10b4820f0>
# it's the default output of printing an object. __main__ shows where the class is 
# defined, Dog is the name of the class, and the last bit is the memory address of the 
# object

# Question 2: trying to print scout's breed throws an error. 
# Traceback (most recent call last):
#   File "/Users/camillephares/Desktop/ECE_16/LAB3/Python/tutorial_oop_dog.py", line 14, in <module>
#     print(scout.__breed)
#           ^^^^^^^^^^^^^
# AttributeError: 'Dog' object has no attribute '__breed'

# Since __breed is encapsulated, the attribute isn't accessible this way

scout.speak("woof")
scout.description()


skippy = Dog("Skippy", 4, "Golden Retriever")
scout.define_buddy(skippy)
scout.buddy.description()

