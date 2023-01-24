from pynput.keyboard import Key, Controller
import time

import csv

final = []
nbr = 0

n = 90
keyboard = Controller()

time.sleep(4)
keyboard.press("r")



def read_():

    keyboard.press("q")
    keyboard.release("q")

    global final
    new_final = final



    while new_final == final or final == []:
        with open('D:\Fichier\IA_Robot\Build\IA_Robot_Data\input.csv', newline='') as csvfile:
            spamreader = csv.reader(csvfile, delimiter=';', quotechar='|')
            a = 0

            for row in spamreader:
                final = row
                a+=1

            nbr = a
    print(final)


#read_()

keyboard.press("q")
keyboard.release("q")


for i in range(3):


    for j in range(n):

        keyboard.press("à")
        keyboard.release("à")

        keyboard.press("&")
        keyboard.release("&")

        keyboard.press("é")
        keyboard.release("é")

        keyboard.press('"')
        keyboard.release('"')

        keyboard.press("e")
        keyboard.release("e")

        keyboard.press("f")
        keyboard.release("f")

        keyboard.press("g")
        keyboard.release("g")

        keyboard.press("h")
        keyboard.release("h")



        read_()



    for j in range(n):

        keyboard.press("a")
        keyboard.release("a")

        keyboard.press("b")
        keyboard.release("b")

        keyboard.press("c")
        keyboard.release("c")

        keyboard.press("d")
        keyboard.release("d")

        keyboard.press("'")
        keyboard.release("'")

        keyboard.press("(")
        keyboard.release("(")

        keyboard.press("-")
        keyboard.release("-")

        keyboard.press("è")
        keyboard.release("è")




        read_()



