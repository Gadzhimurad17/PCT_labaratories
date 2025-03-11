#include <iostream>
#include <cstring>
class Planet{
    public:
        Planet(){};
        Planet(int nameLenght){name=new char[nameLenght];}
        ~Planet(){delete[]name;name=nullptr;}
        const char* GetName();
        int GetDiametr();
        int GetSatellitesNumber();
        int GetLife();
        void SetName(char* setName);
        void SetDiameter(int setDiameter);
        void SetLife(int setLife);
        void SetSatellitesNumber(int setSatellitesNumber );
        void Display();
    private:
        char* name{};
        int diameter{};
        int life{};
        int satellitesNumber{};
};
