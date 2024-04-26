// PHYS 30762 Programming in C++
// Project 2

// Header including Particle class

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#ifndef Particle_H
#define Particle_H

#include<iostream>
#include<memory>
#include<string>

#include"four_momentum.h"

class Particle
{
  private:

  protected:
    //Data members
    double particle_charge{};
    double particle_spin{};
    std::string particle_type{"Ghost"};
    std::unique_ptr<FourMomentum> four_momentum_ptr{nullptr};

  public:
    // Default constructor
    Particle() {std::cout<<"Default constructor called in Particle class for a "<<particle_type<<"."<<std::endl;}

    // Parameterised constructor
    Particle(double charge, double spin, std::string type, double energy, double p_x, double p_y, double p_z);

    // Copy constructor
    Particle(const Particle &original_Particle);

    // Move constructor
    Particle(Particle &&original_Particle);

    // Destructor
    virtual ~Particle() {std::cout<<"Destructor called in Particle class for a "<<particle_type<<"."<<std::endl;}

    // Move assignment operator
    virtual Particle& operator=(Particle &&original_Particle);

    // Copy assignment operator
    virtual Particle& operator=(const Particle &original_Particle);

    // Setter function
    void set_charge(double charge) {particle_charge=charge;}
    void set_spin(double spin) {particle_spin=spin;}
    void set_type(std::string type) {particle_type=type;}
    void set_four_momentum_ptr(std::unique_ptr<FourMomentum> four_mom_ptr) {four_momentum_ptr=std::move(four_mom_ptr);}

    // Getter functions
    double get_charge() const {return particle_charge;}
    double get_spin() const {return particle_spin;}
    std::string get_type() const {return particle_type;}
    const std::unique_ptr<FourMomentum>& get_four_momentum_ptr() const {return four_momentum_ptr;}

    // Function to convert between particles and antiparticles
    virtual std::unique_ptr<Particle> convert_particle()=0;

    // Print function
    virtual void print_info();

    // Friend function: overloaded sum operator of two four-momenta
    friend FourMomentum operator+(const Particle& particle_1, const Particle& particle_2);

    // Friend function: overloaded subtraction operator of two four-momenta
    friend FourMomentum operator-(const Particle& particle_1, const Particle& particle_2);

    // Friend function: dot product of two four-momenta
    friend double dotProduct(const Particle& particle_1, const Particle& particle_2);
};

#endif