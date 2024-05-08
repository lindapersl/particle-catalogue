// PHYS 30762 Programming in C++
// Project 2

// Implementation of Lepton class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<cmath>

#include"particle.h"
#include"lepton.h"

// Parameterised constructor (all leptons are spin-1/2 particles, so this is set here)
Lepton::Lepton(int l_number, double charge, std::string type, double rest_mass, double energy, double p_x,
  double p_y, double p_z) : Particle(charge, 0.5, type, rest_mass, energy, p_x, p_y, p_z)
{
  set_l_number(l_number); // Input checking done within setter function
}

// Setter function
void Lepton::set_l_number(int l_number)
{
  // Ensuring lepton number is either 1 or -1 (has an absolute value of 1)
  if(abs(l_number)==1)
  {
    lepton_number=l_number;
  }

  else
  {
    std::cerr<<"The lepton number you entered is not physical. It has to be either +1 or -1."<<std::endl;
    
    if(particle_type.substr(0, 4)=="anti")
    {
      std::cout<<"A value of -1 will be set for you as this lepton is an antiparticle."<<std::endl;

      lepton_number=-1;
    }

    else
    {
      std::cout<<"A value of +1 will be set for you as this lepton is a particle."<<std::endl;

      lepton_number=1;
    }
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Lepton::convert_particle()
{
  // Negating the charge and lepton number
  particle_charge*=-1;
  lepton_number*=-1;

  // If lepton should be antiparticle after conversion
  if(lepton_number<0)
  {
    particle_type="anti"+particle_type;
  }

  // If lepton should be particle after conversion
  else if(lepton_number>0)
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
  }

  return std::make_unique<Lepton>(*this);
}

// Print function
void Lepton::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    // Calling the equivalent base class function
    Particle::print_info();

    std::cout<<std::left<<std::setfill('.')<<std::setw(25)<<"Lepton number = "<<std::right<<std::setfill('.')
      <<std::setw(25)<<lepton_number<<std::endl;
  }
}