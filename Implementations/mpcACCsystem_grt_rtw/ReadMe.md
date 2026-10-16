# Cpp code Generated for the Automatic Cruise Control Problem

## Important Files

- main.cpp: contains the next function (implementating the stability property) and the loop for checking the property.
- my_mpcACCsystem_data.cpp: contains the inputs for the simulation (speed, acceleration, position, PID params).
- my_mpcACCsystem.cpp: implements the simulink model behavior. 
- ./results: contains the report results for the scenarios executed in the paper.
- my_mpcACCsystem.mk: makefile for compiling, and executing the model. Used for checking the properties with divine.