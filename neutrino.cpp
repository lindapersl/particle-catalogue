// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of Neutrino class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<memory>

#include"lepton.h"
#include"neutrino.h"

// Print function
void Neutrino::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    // Calling the equivalent lepton class function
    Lepton::print_info();

    std::cout<<"Neutrino has interacted = ";

    if(interaction_info == 0)
    {
      std::cout<<"No"<<std::endl;
    }

    else if(interaction_info == 1)
    {
      std::cout<<"Yes"<<std::endl;
    }
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the lepton's "<<
      "four momentum cannot be printed."<<std::endl;
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Neutrino::convert_particle()
{
  // Negating the lepton number (charge is zero for neutrinos, so no need to negate it)
  lepton_number*=-1;

  if(lepton_number<0) // If neutrino is an antiparticle after conversion
  {
    std::stringstream particle_type_stream(particle_type);
    std::string neutrino_flavour, neutrino_name;

    particle_type_stream>>neutrino_flavour>>neutrino_name;

    particle_type=neutrino_flavour+" anti"+neutrino_name;
  }

  else if(lepton_number>0) // If neutrino is its particle after conversion
  {
    std::stringstream particle_type_stream(particle_type);
    std::string neutrino_flavour, anti_name, neutrino_name;

    particle_type_stream>>neutrino_flavour>>anti_name>>neutrino_name;

    // Gets rid of "anti" in the middle of the name for the particle type
    particle_type=neutrino_flavour+neutrino_name;
  }

  return this->clone();
}