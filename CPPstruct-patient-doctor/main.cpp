/*
* ----------------------------------------------------------
Name: Muhammed Berkay Ermiþ

Course: Programming for Engineers . 64170024, Fall , 2020

Purpose: The aim of this project is that creating Patient and Doctor structures
         by using struct and keep their datas inside struct.
         Reading information of patients and doctors, printing them.
         Comparing patients priority and determine that whether two doctors are same or not.
         Lastly, reading data of patient and doctor from an input file and writing each of them into
         an output file.

* ----------------------------------------------------------
*/

// Libraries
#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>

using namespace std;

/*
    Patient struct with name, ID and number of doctor
*/
struct Patient {

    string name;
    int ID;
    int number_of_doctor;
};

/*
    Doctor struct with name, speciality, office number and age
*/
struct Doctor {
    string doctor_name;
    string speciality;
    int office_number;
    int age;
};

// Function prototypes
void patient_func(Patient*);
void doctor_func(Doctor*);
void display_patient(Patient*);
void display_doctor(Doctor*);
void check_doctors(Doctor*, Doctor*);
void check_patient(Patient*, Patient*);
void readData(Doctor*, Patient*);

// Main function
int main()
{

    /*
     Single patient and a struct declaration with 3 patients.
     2 single doctor informations and a doctor struct declaration with 7 doctors.
    */
    Patient p1;
    Patient p2;
    Patient p3[3];
    Doctor d1;
    Doctor d2;
    Doctor d3[7];

    // Reading 2 patients.
    patient_func(&p1);
    patient_func(&p2);

    // Reading a doctor.
    doctor_func(&d1);
    readData(d3, p3); // file processes
    // Display the patients
    cout << "Patient 1:" << endl;
    display_patient(&p1);
    cout << "Patient 2:" << endl;
    display_patient(&p2);

    //check doctors
    check_doctors(&d3[0], &d3[1]);
    check_doctors(&d3[0], &d3[0]);

    //check patients
    check_patient(&p1, &p2);

}

/*
    patient_func function provides to read informations about a patient.
    Also, it can change an existing patient informations.
*/
void patient_func(Patient* p1) {

    cout << "Enter patient name:";
    cin >> p1->name;
    cout << "Enter patient ID:";
    cin >> p1->ID;
    cout << "Enter number of doctor ";
    cin >> p1->number_of_doctor;
}

/*
    doctor_func function provides to read informations about a doctor.
    Also, it can change an existing doctor informations
*/
void doctor_func(Doctor* d1) {

    cout << "Enter doctor name:";
    cin >> d1->doctor_name;
    cout << "Enter doctor speciality:";
    cin >> d1->speciality;
    cout << "Enter doctor office number:";
    cin >> d1->office_number;
    cout << "Enter doctor age:";
    cin >> d1->age;
    cout << " " << endl;
}

/*
    display_patient function prints information of given patient
*/
void display_patient(Patient* p1) {
    cout << "Patient name: " << p1->name << endl;
    cout << "Patient ID: " << p1->ID << endl;
    cout << "Patient number of doctor: " << p1->number_of_doctor << endl;
    cout << " " << endl;
}

/*
    display_doctor function prints information of given doctor
*/
void display_doctor(Doctor* d1) {
    cout << "Doctor name: " << d1->doctor_name << endl;
    cout << "Doctor Speciality: " << d1->speciality << endl;
    cout << "Doctor office number: " << d1->office_number << endl;
    cout << "Doctor age: " << d1->age << endl;
    cout << " " << endl;
}

/*
    check_doctors function checks 2 doctor informations and determine whether they are same or not
    If they are same, function returns true, otherwise false.
*/
void check_doctors(Doctor* d1, Doctor* d2) {
    if ((d1->doctor_name == d2->doctor_name) && (d1->office_number == d2->office_number)) {
        cout << "Two doctors are same." << endl;
    }
    else
        cout << "Two doctors are different." << endl;
}
/*
    check_patient function checks two patients and it decides that who should be
    treated before.
    If ID and number of doctor of any patient are greater than other patient,
    it returns true and prints a message.
*/
void check_patient(Patient* p1, Patient* p2) {

    if (p1->ID > p2->ID) {
        if (p2->number_of_doctor < p1->number_of_doctor || p1->number_of_doctor == p2->number_of_doctor) {
            cout << p1->name << " should be treated before " << p2->name << endl;
        }
        else {
            cout << p2->name << " should be treated before " << p1->name << endl;
        }
    }
    else if (p2->ID > p1->ID) {
        if (p2->number_of_doctor > p1->number_of_doctor || p2->number_of_doctor == p1->number_of_doctor) {
            cout << p2->name << " should be treated before " << p1->name << endl;
        }
        else {
            cout << p1->name << " should be treated before " << p2->name << endl;
        }
    }
}

/*
    readData function takes two parameters which 7 doctors and 3 patient informations.
    It reads each line of input file and saves doctor and patients information into the struct declarations.
    After assigning values, these informations are written into two different output files.
*/
void readData(Doctor d1[7], Patient p1[3]) {

    ifstream berkay_IN("berkay_IN.txt", ios::in);
    string line;
    int checkDoctor = -1, checkPatient = -1, temp = 0;
    while (!berkay_IN.eof()) {
        getline(berkay_IN, line);
        checkDoctor = line.compare("Doctors:");
        checkPatient = line.compare("Patients:");
        if (checkDoctor == 0) {
            for (int i = 0; i < 7; i++) {
                getline(berkay_IN, line);
                d1[i].doctor_name = line;

                getline(berkay_IN, line);
                stringstream offNum(line);
                offNum >> temp;
                d1[i].office_number = temp;

                getline(berkay_IN, line);
                d1[i].speciality = line;

                getline(berkay_IN, line);
                stringstream Age(line);
                Age >> temp;
                d1[i].age = temp;
            }
        }
        else if (checkPatient == 0) {
            for (int i = 0; i < 3; i++) {
                getline(berkay_IN, line);
                p1[i].name = line;

                getline(berkay_IN, line);
                stringstream id(line);
                id >> temp;
                p1[i].ID = temp;

                getline(berkay_IN, line);
                stringstream nod(line);
                nod >> temp;
                p1[i].number_of_doctor = temp;
            }
        }
    }

    berkay_IN.close();
    ofstream fileOne, fileTwo;
    fileOne.open("Doctors.txt", ios::out);
    fileOne << "Doctors: \n" << endl;
    for (int i = 0; i < 7; i++) {
        fileOne << "Doctor Name: " << d1[i].doctor_name << endl;
        fileOne << "Doctor Office Number: " << d1[i].office_number << endl;
        fileOne << "Doctor Specialty: " << d1[i].speciality << endl;
        fileOne << "Doctor Age: " << d1[i].age << endl;
        fileOne << endl;
    }
    fileOne.close();
    fileTwo.open("Patients.txt", ios::out);
    fileTwo << "Patients: \n" << endl;
    for (int i = 0; i < 3; i++) {
        fileTwo << "Patient Name: " << p1[i].name << endl;
        fileTwo << "Patient ID: " << p1[i].ID << endl;
        fileTwo << "Patient's Number of Doctor: " << p1[i].number_of_doctor << endl;
        fileTwo << endl;
    }
}