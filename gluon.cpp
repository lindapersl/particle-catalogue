// PHYS 30762 Programming in C++
// Project 2

// Implementation of Gluon class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<string>
#include<iomanip>

#include"particle.h"
#include"gauge_boson.h"
#include"gluon.h"

// Parameterised constructor (glon charge and rest mass are zero, so these are set here)
Gluon::Gluon(std::string colour_1, std::string colour_2, double energy, double p_x, double p_y, double p_z) :
  GaugeBoson(0, "gluon", 0, energy, p_x, p_y, p_z)
{
  set_colours(colour_1, colour_2);  // Input checking done within setter function
}

// Setter function
void Gluon::set_colours(std::string colour_1, std::string colour_2)
{
  // Checking if gluon has been assigned one colour and one anticolour
  if((((colour_1.substr(0, 4))!="anti")&((colour_2.substr(0, 4))=="anti"))||(((colour_1.substr(0, 4))=="anti")&((colour_2.substr(0, 4))!="anti")))
  {
    colour_charge_1=colour_1;
    colour_charge_2=colour_2;
  }

  else
  {
    std::cerr<<"The gluon colour charge combination isn't physical. It has to have one charge and one anticharge. Thus, no colour charges were set."
      <<std::endl;
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Gluon::convert_particle()
{
  // (No need to negate the charge as it is zero for gluons)

  // Changing the particle type and colour charges

  // If particle is converting from particle to antiparticle
  if(particle_type.substr(0, 4)!="anti")
  {
    particle_type="anti"+particle_type;
  }

  // If particle is converting from antiparticle to particle
  else if(particle_type.substr(0, 4)=="anti")
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
  }

  // If changing colour_charge_1 to anticolour and colour_charge_2 to colour
  if(((colour_charge_1.substr(0, 4))!="anti")&((colour_charge_2.substr(0, 4))=="anti"))
  {
    set_colours("anti"+colour_charge_1, colour_charge_2.erase(0, 4)); // Makes use of input checking in setter function
  }

  // If changing colour_charge_1 to colour and colour_charge_2 to anticolour
  else if(((colour_charge_1.substr(0, 4))=="anti")&((colour_charge_2.substr(0, 4))!="anti"))
  {
    set_colours(colour_charge_1.erase(0, 4), "anti"+colour_charge_2);
  }

  return std::make_unique<Gluon>(*this);
}

// Print function
void Gluon::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    Particle::print_info();

    std::cout<<std::left<<std::setfill('.')<<std::setw(25)<<"Colour charge combination = "<<std::right<<std::setfill('.')<<std::setw(25)<<colour_charge_1
      <<" and "<<colour_charge_2<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }
}