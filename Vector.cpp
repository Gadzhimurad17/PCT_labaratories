#include <iostream>
#include "Vector.h"
#include <algorithm>
Vector CreateVector(){
    int* array= new int[kDefaultSize];
    return{.vectorSize=0,.vectorCapacity=kDefaultSize,.vector=array};
}

void ResizeVector(Vector& vector){
    if (!vector.vector){
        std::cerr<<"invalid vector";
    }
    size_t grownCapacity= kDefaultSize*grownFactor;
    int* buffer= new int[grownCapacity];
    std::copy(vector.vector,vector.vector+vector.vectorSize,buffer);
    int* oldVector=vector.vector;
    vector.vector=buffer;
    delete[] oldVector;
}

int GetVectorElement(Vector& vector,size_t index){
    if (index>=vector.vectorCapacity){
        std::cerr<<"Выход за пределы вектора";
        return -1;
    }
    if (!vector.vector){
        std::cerr<<"invalid vector";
        return -1;
    }
    return vector.vector[index];
}

void PushBack(Vector& vector,int element){
    if (!vector.vector){
        std::cerr<<"invalid vector";
    }
    if(vector.vectorSize>=vector.vectorCapacity){
        ResizeVector(vector);
    }
    vector.vector[vector.vectorSize++]=element;
}

void PrintElement(Vector& vector){
    for(size_t i=0;i<=vector.vectorSize;i++){
        std::cout<<GetVectorElement(vector,i);
    }
    std::cout<<std::endl;
}

void DeleteVector(Vector& vector){
    vector.vectorSize=0;
    vector.vectorCapacity=0;
    delete[] vector.vector;
    vector.vector=nullptr;
}
