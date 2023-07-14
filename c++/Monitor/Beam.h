#pragma once
#include<iostream>
#include <string>
#include "Monitors.h"
using std::string;
class Beam :
    public Monitors
{
private:
    double frequency;
    double radiation;
public:
    Beam(string model = "", double d = 0,double frequency=0,double radiation=0 ):Monitors(model,d),frequency(frequency),radiation(radiation){ }
    friend std::istream& operator>>(std::istream& is, Beam& b);
    friend std::ostream& operator<<(std::ostream& os, Beam& b);
    void print(std::ostream& os)override;
    void read(std::istream& is)override;
    double getFrequency()override {
        return frequency;
    }
};

