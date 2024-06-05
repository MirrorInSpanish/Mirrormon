//A work in progress for a virtual pet game
//Currently running via console

import os
import threading
import time
import sched
import inquirer
from turtle import clear
import math

#Module1
# define vpet class & constructor
class Mirrormon:
    def __init__(self):
        self.name    = "VoidCat"
        self.age     = 0
        self.power   = 0
        self.ultra   = 0
        self.weight  = 5
        self.thirst  = 0
        self.hunger  = 0
        self.energy  = 5
        self.alive   = True

#this is the eat method for the vpet class
#it increases the food level by 2
    def activity_eat(self):
        self.hunger = self.hunger + 2
        self.weight = self.weight + 2
        return ("Eating...")

    # this is drink method for the vpet class
    #it increases the thirst level by 1
    def activity_drink(self):
        self.thirst = self.thirst + 1
        self.weight = self.weight + 1
        return ("Drinking...")

# this is train method for the vpet class
#it decreases the food level by .5 & thirst level by .25
    def activity_train(self):
        self.hunger = self.hunger   - .5
        self.thirst = self.thirst   - .25
        self.power = self.power     + 1
        self.weight = self.weight   - 3
        self.energy = self.energy   - 0.5
        self.ultra = self.ultra     + .25
        return ("Destroying dark towers...")

#sleep method for the vpet class
#decreases the food level by 10
#decreased the thirst level by 5
#increases the energy level by 15
    def activity_sleep(self):
        self.energy = self.energy   + 15
        self.hunger = self.hunger   - 10
        self.thirst = self.thirst   - 5
        return ("Resting...")

#pass_time method for the vpet class
#it increases the age by 0.2
    def pass_time(self):
        self.age = self.age + 0.2
        self.thirst = self.thirst - 2.5
        self.hunger = self.hunger - 5
        self.energy = self.energy + 0.5      
        
        if self.hunger <= -20 or self.thirst <= -10 or self.energy <= 0:
            self.alive = False

#status method for the vpet class
#prints the status of the vpet
    def status(self):
        print(
            f"""
Name:   {self.name}
Age:    {round(self.age)}
Weight: {self.weight}
Hunger: {self.hunger}
Thirst: {self.thirst}
Power:  {self.power}
Ultra:  {self.ultra}
Energy: {self.energy}
-----------
        """
        )

#Module 2
# this is run method for the Tamagotchi class   
#it clears the screen, prints the status of the Tamagotchi, asks the user for an activity and runs the activity
    def run(self):
        self.clear()
        self.status()
        question = [
            inquirer.List(
                "activity",
                message="What should we do?",
                choices=["Eat", "Drink", "Train", "Sleep"],
            ),
        ]
        answer = inquirer.prompt(question)
        activity_name = "activity_{}".format(answer.get("activity")).lower()
        activity = getattr(self, activity_name, lambda: "Invalid activity")
        (status) = activity()
        print(self.status)
        time.sleep

    def clear(self):
        if os.name == "nt":
            _ = os.system("cls")
        else:
            _ = os.system("clear")        

#Module 3
def main():
    void = Mirrormon()

    s = sched.scheduler(time.time, time.sleep)

    def run(sc):
        void.pass_time()
        if void.alive:
            s.enter(10, 1, run, (sc,))

    s.enter(10, 1, run, (s,))
    t = threading.Thread(target=s.run)
    t.start()

    while void.alive:
        void.run()

    while void.alive : False
    print(f"{void.name} has died :(")

if __name__ == "__main__":
    main()
