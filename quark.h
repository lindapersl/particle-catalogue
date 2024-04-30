// PHYS 30762 Programming in C++
// Project 2

// Header including Quark class

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef QUARK_H
#define QUARK_H

#include<iostream>
#include<memory>
#include<string>

#include"particle.h"

class Quark : public Particle
{
  private:

  protected:
  double baryon_number{};
  std::string colour_charge{"ghost"};


  public:
    // Default constructor
    Quark() : Particle() {std::cout<<"Default constructor called in Quark class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Quark(double b_number, std::string colour, double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z);

    // // Copy constructor
    // Quark(const Quark &original_Quark);

    // // Move constructor
    // Quark(Quark &&original_Quark);

    // Destructor
    virtual ~Quark() {std::cout<<"Destructor called in Quark class for a "<<particle_type<<"."<<std::endl;}

    // // Move assignment operator
    // virtual Quark& operator=(Quark &&original_Quark);

    // // Copy assignment operator
    // virtual Quark& operator=(const Quark &original_Quark);

    // Setter functions
    void set_b_number(double b_number);
    void set_colour(std::string colour);

    // Getter functions
    double get_b_number() const {return baryon_number;}
    std::string get_colour() const {return colour_charge;}

    // Function to convert between particles and antiparticles
    virtual std::unique_ptr<Particle> convert_particle();

    // Overriden clone function
    virtual std::unique_ptr<Particle> clone() const {return std::make_unique<Quark>(*this);}

    // Print function
    virtual void print_info();
};

#endif