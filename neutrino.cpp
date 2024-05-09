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
#include<set>
#include<stdexcept>

#include"particle.h"
#include"lepton.h"
#include"neutrino.h"

// Parameterised constructor (all neutrinos have lepton number=1, charge=0 and rest mass=0
// so these are set here)
Neutrino::Neutrino(bool interacted, std::string flavour, double energy, double p_x, double p_y, double p_z) :
  Lepton(1, 0, (flavour+" neutrino"), 0, energy, p_x, p_y, p_z)
{
  interaction_info=interacted;
  set_flavour(flavour); // Makes use of input checking

  // Updating the particle_type with the correct one just in case 'flavour' was a rouge input
  set_type(flavour+" neutrino");
}

// Setter function
void Neutrino::set_flavour(std::string flavour)
{
  // Ensuring the input are one of the three possible flavours
  std::set<std::string> possible_flavours{"electron", "muon", "tau"};

  if(possible_flavours.count(flavour)>0)
  {
    neutrino_flavour=flavour;
  }

  else
  {
    throw std::invalid_argument("Invalid neutrino flavour: "+flavour);
  }
}

// Print function
void Neutrino::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    // Calling the equivalent lepton class function
    Lepton::print_info();

    std::cout<<std::left<<std::setfill('.')<<std::setw(25)<<"Neutrino has interacted = ";

    if(interaction_info == 0)
    {
      std::cout<<std::right<<std::setfill('.')<<std::setw(25)<<"No"<<std::endl;
    }

    else if(interaction_info == 1)
    {
      std::cout<<std::right<<std::setfill('.')<<std::setw(25)<<"Yes"<<std::endl;
    }
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Neutrino::convert_particle()
{
  // Negating the lepton number (charge is zero for neutrinos, so no need to negate it)
  lepton_number*=-1;

  // If neutrino is an antiparticle after conversion
  if(lepton_number<0)
  {
    std::stringstream particle_type_stream(particle_type);
    std::string flavour, neutrino_name;

    particle_type_stream>>flavour>>neutrino_name;

    particle_type=flavour+" anti"+neutrino_name;
  }

  // If neutrino is its particle after conversion
  else if(lepton_number>0)
  {
    std::stringstream particle_type_stream(particle_type);
    std::string flavour, neutrino_name;

    particle_type_stream>>flavour>>neutrino_name;

    // Deleting "anti" from "antineutrino"
    neutrino_name.erase(0, 4);

    // Gets rid of "anti" in the middle of the name for the particle type
    particle_type=flavour+" "+neutrino_name;
  }

  return std::make_unique<Neutrino>(*this);
}