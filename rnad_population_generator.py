from random import random

with open("population.txt", "wt") as population:
    states = []
    for i in range(100000):
        state = ""
        for j in range(10):
            state += str(round(random()))
        # population.write(state)
        print(state)
        state += "\n"
        states.append(state)
    population.writelines(states)