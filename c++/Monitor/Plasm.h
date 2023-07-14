#pragma once
#include<iostream>
#include "Monitors.h"
#include<string>
using std::string;
class Plasm :
    public Monitors
{
private:
    double resolution;
    double angle;
public:
    Plasm(string model="", double d=0, double resolution=0, double angle=0) :Monitors(model, d), resolution(resolution), angle(angle) { }
    friend std::istream& operator>>(std::istream& is, Plasm& p);
    friend std::ostream& operator<<(std::ostream& os, const Plasm& p);
    void print(std::ostream& os)override;
    void read(std::istream& is)override;
    double getFrequency()override {
        return 0.0;
    }
};

