# Struct of Patient and Doctor with C++

Foobar is a Python library for dealing with word pluralization.

## What is a structure?

A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type.

## Problem

```python
Define a patient structure to keep the name, a constant ID, and the doctor(s) treating the
patient. Notice that you need to keep the number of doctors for each patient. Define the doctor
as another structure where you keep name, specialty, office number and age.

Write the following functions:
1) A function to read information about patients.
2) A function to display (print) the values related to an existing patient.
3) A function to check the equality of two doctors. Two doctors are equal if they have the same
name (use strcmp) and same office.
4) A function to read the information related to a given doctor.

2) A function to decide whether one patient should be treated before another patient. The check
holds true only if the ID of the first patient is greater than the second, and the number of doctors
for the second patient is less than the number of doctors for the first patient.
3) A function to display (print) the values of the variables in an existing doctor.

Add any other functions you find necessary.

Define a text file for input and use a text editor to write inside the file information related to 7
doctors and 3 patients.
Write a function to open the text file and read the values into an array of 7 doctors and another
array of 3 patients. Write them in two different random access files one for doctors and the other
for patients.

Inside the main,
1) call the function, which reads the values from the text file.
2) call and test the other functions defined above.
```

## Resource
[struct](https://www.geeksforgeeks.org/structures-in-cpp/)
