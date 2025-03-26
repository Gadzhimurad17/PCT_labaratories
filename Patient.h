#pragma once
#include <iostream>
#include <cstring>

class Patient {
public:
    Patient() : name(nullptr), age(0), isInsured(false), visitsCount(0) {}
    Patient(const char* name, int age, bool isInsured, int visitsCount) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->isInsured = isInsured;
        this->visitsCount = visitsCount;
    }
    ~Patient() { delete[] name; }

    Patient(const Patient& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        isInsured = other.isInsured;
        visitsCount = other.visitsCount;
    }

    Patient& operator=(const Patient& other) {
        if (this != &other) {   
            SetName(other.name);
            age = other.age;
            isInsured = other.isInsured;
            visitsCount = other.visitsCount;
        }
        return *this;
    }

    const char* GetName() const { return name; }
    int GetAge() const { return age; }
    bool GetIsInsured() const { return isInsured; }
    int GetVisitsCount() const { return visitsCount; }

    void SetName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    void SetAge(int newAge) { age = newAge; }
    void SetIsInsured(bool insured) { isInsured = insured; }
    void SetVisitsCount(int count) { visitsCount = count; }

    void Display() const;

    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
    friend std::istream& operator>>(std::istream& in, Patient& patient);
    static void ReadDb(Patient*& arr, int& count);
    static void WriteDB(Patient* arr, int count);
    static void AddPatient(Patient*& arr, int& count, const Patient& newPatient);
    static void DeletePatient(Patient*& arr, int& count, int index);
    static void EditPatient(Patient& patient);
    static void SortDB(Patient* arr, int count);

private:
    char* name;
    int age;
    bool isInsured;
    int visitsCount;
};
