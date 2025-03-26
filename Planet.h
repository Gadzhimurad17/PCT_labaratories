#pragma once
#include <iostream>
#include <cstring>
class Planet {
public:
    Planet() : name(nullptr), diameter(0), life(0), satellitesNumber(0) {}
    Planet(const char* name, int diameter, int life, int satellitesNumber) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->diameter = diameter;
        this->life = life;
        this->satellitesNumber = satellitesNumber;
    }
    ~Planet() {
        delete[] name;
    }
    
    Planet(const Planet& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        diameter = other.diameter;
        life = other.life;
        satellitesNumber = other.satellitesNumber;
    }
    
    Planet& operator=(const Planet& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            diameter = other.diameter;
            life = other.life;
            satellitesNumber = other.satellitesNumber;
        }
        return *this;
    }

    const char* GetName() const { return name; }
    int GetDiameter() const { return diameter; }
    int GetSatellitesNumber() const { return satellitesNumber; }
    int GetLife() const { return life; }
    
    void SetName(const char* setName) {
        delete[] name;
        name = new char[strlen(setName) + 1];
        strcpy(name, setName);
    }
    
    void SetDiameter(int setDiameter) { diameter = setDiameter; }
    void SetLife(int setLife) { life = setLife; }
    void SetSatellitesNumber(int setSatellitesNumber) { satellitesNumber = setSatellitesNumber; }
    
    void Display() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Planet& planet);
    friend std::istream& operator>>(std::istream& in, Planet& planet);
    friend bool operator<(const Planet& a, const Planet& b) { return a.diameter < b.diameter; }
    friend bool operator<=(const Planet& a, const Planet& b) { return a.diameter <= b.diameter; }
    friend bool operator>=(const Planet& a, const Planet& b) { return a.diameter >= b.diameter; }
    friend int operator+(const Planet& a, const Planet& b) { return a.diameter + b.diameter; }
    friend Planet& operator++(Planet& p) { p.diameter++; return p; } // префиксный
    friend Planet operator++(Planet& p, int) { Planet temp = p; p.diameter++; return temp; } // постфиксный
    friend Planet& operator--(Planet& p) { p.diameter--; return p; } // префиксный
    friend Planet operator--(Planet& p, int) { Planet temp = p; p.diameter--; return temp; } // постфиксный
    static void ReadDb(Planet*& arr, int& count);
    static void WriteDB(Planet* arr, int count);
    static void AddPlanet(Planet*& arr, int& count, const Planet& newPlanet);
    static void DeletePlanet(Planet*& arr, int& count, int index);
    static void EditPlanet(Planet& planet);
    static void SortDB(Planet* arr, int count);
private:
    char* name;
    int diameter;
    int life;
    int satellitesNumber;
};
