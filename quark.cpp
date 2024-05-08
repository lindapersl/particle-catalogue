// PHYS 30762 Programming in C++
// Project 2

// Implementation of Quark class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<cmath>

#include"particle.h"
#include"quark.h"

// Parameterised constructor (all quarks are spin-1/2 particles, so this is set here)
Quark::Quark(double b_number, std::string colour, double charge, std::string type, double rest_mass, double energy, double p_x,
  double p_y, double p_z) : Particle(charge, 0.5, type, rest_mass, energy, p_x, p_y, p_z)
{
  set_b_number(b_number);  // Input checking done within setter function
  set_colour(colour);
}

// Setter functions
void Quark::set_b_number(double b_number)
{
  // Ensuring baryon number is either 1/3 or -1/3 (has an absolute value of 1/3)
  if(fabs(b_number)==0.333)
  {
    baryon_number=b_number;
  }

  else
  {
    std::cerr<<"The baryon number you entered is not physical. It has to be either +1/3 or -1/3."<<std::endl;
    
    if(particle_type.substr(0, 4)=="anti")
    {
      std::cout<<"A value of -1/3 will be set for you."<<std::endl;

      baryon_number=-0.333;
    }

    else
    {
      std::cout<<"A value of +1/3 will be set for you."<<std::endl;

      baryon_number=0.333;
    }
  }
}

void Quark::set_colour(std::string colour)
{
  // Checking if colour charge is consistent with whether the quark is a particle or an antiparticle

  // If the quark is a particle
  if(baryon_number==0.333)
  {
    // If the colour charge is a colour
    if((colour.substr(0, 4))!="anti")
    {
      colour_charge=colour;
    }

    else
    {
      std::cerr<<"The colour charge is an anti-colour, but the quark is a particle. A colour charge was not set for you due to to this inconsistency."
        <<std::endl;
    }
  }

  // If the quark is an antiparticle
  else if(baryon_number==-0.333)
  {
    // If the colour charge is an anti-colour
    if((colour.substr(0, 4))=="anti")
    {
      colour_charge=colour;
    }

    else
    {
      std::cerr<<"The colour charge is a colour, but the quark is an antiparticle. A colour charge was not set for you due to to this inconsistency."
        <<std::endl;
    }
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Quark::convert_particle()
{
  // Negating the charge and Quark number
  particle_charge*=-1;
  baryon_number*=-1;

  // Changing the particle type and colour charge accordingly

  // If quark should be antiparticle after conversion
  if(baryon_number<0)
  {
    particle_type="anti"+particle_type;
    set_colour("anti"+colour_charge); // Makes use of input checking in setter function
  }

  // If quark should be its particle after conversion
  else if(baryon_number>0)
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
    set_colour(colour_charge.erase(0, 4));
  }

  return std::make_unique<Quark>(*this);
}

// Print function
void Quark::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    Particle::print_info();

    std::cout<<std::left<<std::setfill('.')<<std::setw(25)<<"Baryon number = "<<std::right<<std::setfill('.')<<std::setw(25)<<baryon_number
    <<std::left<<std::setfill('.')<<std::setw(25)<<"\nColour charge = "<<std::right<<std::setfill('.')<<std::setw(25)<<colour_charge<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }
}