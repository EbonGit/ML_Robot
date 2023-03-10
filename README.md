# ML_Robot (WIP)
Repository for the project ML_Robot, a quadruped robot for the implementation of artificial intelligence.
![alt text](https://github.com/EbonGit/ML_Robot/blob/main/Image/readme.jpg)

## Table of Contents

+ [About](#About)
+ [Folders](#Folders)
  + [Model](#Model)
  + [PCB](#PCB)
  + [Raspberry Pi Pico](#RaspberryPico)
  + [Controller](#Controller)
  + [Unity Project](#UnityProject)
  + [Results](#Results)
+ [Build](#Build)

# About
This personal project aims to experiment with the principles of **reinforcement learning*** applied to **robotics**. After modeling the robot using fusion360, I 3d printed it. See assembly guide (WIP). Physical simulation of the robot inside **Unity**, and use of the ml-agents library to train a neural network to control the robot.

# Folders

### Model
all 3D files modeled with **fusion360** for 3D printing.
(image)

### PCB
gerber file, this printed circuit contains both the power circuit and the connections between the pins of the raspberry pi pico and the **servo motors (DS3218)** https://www.amazon.ca/dp/B085PVVZNQ


### RaspberryPico
use of the raspberry pi pico because supports the **tinyML** library of tensorflow, **multiprocessor** which allows the use of one of the two cores for the execution of the neural network while the second takes care of performing the resulting actions.
https://www.youtube.com/watch?v=aIFElaK14V4&ab_channel=LearnEmbeddedSystems (video from [Learn Embedded Systems](https://www.youtube.com/@LearnEmbeddedSystems))

### Controller
all the codes to control the robot using instructions via usb (in python) and the program in C and C++ to program the raspberry pi pico, using .uf2 to flash the memory
(video)

### UnityProject
the whole project under unity

**Unity ml-agents** -> https://github.com/Unity-Technologies/ml-agents

https://github.com/EbonGit/ML_Agent-Unity-Robot_Build (google colab .ipynb)

### Results
artificial intelligence models and related learning graphs

![Screenshot](https://github.com/EbonGit/ML_Robot/blob/main/Image/Results.PNG)

### Image


# Build
(WIP)





