// PHYS 30762 Programming in C++
// Project 2

// Implementation of Gluon class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<string>

#include"particle.h"
#include"gauge_boson.h"
#include"gluon.h"

// Parameterised constructor
Gluon::Gluon(std::string colour_1, std::string colour_2, double charge, double spin, double energy, double p_x, double p_y, double p_z) :
  GaugeBoson(charge, spin, "gluon", energy, p_x, p_y, p_z)
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
  if(particle_type.substr(0, 4)!="anti") // If particle is converting from particle to antiparticle
  {
    particle_type="anti"+particle_type;
  }

  else if(particle_type.substr(0, 4)=="anti") // If particle is converting from antiparticle to particle
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
  }

  if(((colour_charge_1.substr(0, 4))!="anti")&((colour_charge_2.substr(0, 4))=="anti")) // If changing colour_charge_1 to anticolour and colour_charge_2 to colour
  {
    set_colours("anti"+colour_charge_1, colour_charge_2.erase(0, 4)); // Makes use of input checking in setter function
  }

  else if(((colour_charge_1.substr(0, 4))=="anti")&((colour_charge_2.substr(0, 4))!="anti")) // If changing colour_charge_1 to colour and colour_charge_2 to anticolour
  {
    set_colours(colour_charge_1.erase(0, 4), "anti"+colour_charge_2);
  }

  return this->clone();
}

// Print function
void Gluon::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    Particle::print_info();

    std::cout<<"Colour charge combination = "<<colour_charge_1<<" and "<<colour_charge_2<<std::endl;
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the gluon's "<<
      "four momentum cannot be printed."<<std::endl;
  }
}