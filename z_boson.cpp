// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of ZBoson class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<memory>

#include"particle.h"
#include"gauge_boson.h"
#include"z_boson.h"

// Parameterised constructor
ZBoson::ZBoson(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double charge, double spin, double energy,
  double p_x, double p_y, double p_z) : GaugeBoson(charge, spin, "z-boson", energy, p_x, p_y, p_z)
{
  set_products(std::move(particle_1), std::move(particle_2)); // Input checking done within setter function
}

// Copy constructor
ZBoson::ZBoson(const ZBoson &original_boson) : GaugeBoson(original_boson)
{
  // Deep copying the decay products of the original particle by iterating over each of its element of unique pointers
  std::vector<std::unique_ptr<Particle>>::iterator vector_iterator;

  for(vector_iterator=decay_products.begin();vector_iterator<decay_products.end();vector_iterator++)
  {
    decay_products.push_back((*vector_iterator)->clone());
  }

  std::cout<<"Copy constructor called in ZBoson class for a "<<particle_type<<"."<<std::endl;
}

// Move constructor
ZBoson::ZBoson(ZBoson &&original_boson) : GaugeBoson(std::move(original_boson))
{
  // Move data of the original particle to a new particle
  decay_products=std::move(original_boson.decay_products);

  // The data member of the original particle is reset automatically when moving a unique pointer

  std::cout<<"Move constructor called in ZBoson class for a "<<particle_type<<"."<<std::endl;
}

// Move assignment operator
ZBoson& ZBoson::operator=(ZBoson &&original_boson)
{
  // Avoiding self-assignment
  if(&original_boson==this)
  {
    std::cerr<<"Self-assignment detected, hence move assignment was not performed in"
    <<" ZBoson class for a "<<particle_type<<"."<<std::endl;


    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(std::move(original_boson));

    // Move data of the original particle to a new particle
    decay_products=std::move(original_boson.decay_products);

    // The data member of the original particle is reset automatically when moving a unique pointer

    std::cout<<"Move assignment called in ZBoson class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Copy assignment operator
ZBoson& ZBoson::operator=(const ZBoson &original_boson)
{
  // Avoiding self-assignment
  if(&original_boson==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment was not performed in ZBoson class for a "
    <<particle_type<<"."<<std::endl;

    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(original_boson);

    // Deep copying the decay products of the original particle by iterating over each of its element of unique pointers
    std::vector<std::unique_ptr<Particle>>::iterator vector_iterator;

    for(vector_iterator=decay_products.begin();vector_iterator<decay_products.end();vector_iterator++)
    {
      decay_products.push_back((*vector_iterator)->clone());
    }

    std::cout<<"Copy assignment called in ZBoson class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Setter function
void ZBoson::set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2)
{
  // Calculating the total charge of the decay products
  double sum_product_charge{particle_1->get_charge()+particle_2->get_charge()};

  // Checking if the total charge is equal to that of the ZBoson particle
  if(sum_product_charge==get_charge())
  {
    // Ensuring the decay product vector is empty before appending
    if(decay_products.size()!=0)
    {
      std::cerr<<"The decay product vector of this z-boson was not empty. It will be cleared and filled with your new particles"
        <<std::endl;

      decay_products.clear();
    }

    decay_products.push_back(std::move(particle_1));
    decay_products.push_back(std::move(particle_2)); /// or clone?
  }

  // else if(abs(sum_product_charge)==abs(get_charge()))
  // {
  //   // This scenario can happen if an antiZBoson particle is instatiated - should be 
  //   // Ensuring the decay product vector is empty before appending
  //   if(decay_products.size()!=0)
  //   {
  //     std::cerr<<"The decay product vector of this ZBoson particle was not empty.\nIt will be cleared and filled with your new particles"
  //       <<std::endl;

  //     decay_products.clear();
  //   }

  //   decay_products.push_back(particle_1->clone());
  //   decay_products.push_back(particle_2->clone());
  //   decay_products.push_back(particle_3->clone());
  // }

  else
  {
    std::cerr<<"The sum of decay product charges does not add up to the z-boson charge (0), so no decay products were set."<<std::endl;
  }
}

// Print function
void ZBoson::print_info()
{
  if((four_momentum_ptr!=nullptr)&(decay_products.size()!=0))//&(decay_product_1!=nullptr)&(decay_product_2!=nullptr)&(decay_product_3!=nullptr))
  {
    // Calling the equivalent GaugeBoson class function
    GaugeBoson::print_info();

      std::cout<<"Particles the z-boson decays to = "<<decay_products[0]->get_type()<<", "<<decay_products[1]->get_type()<<std::endl;
  }

  // else if((four_momentum_ptr==nullptr)||(decay_product_1==nullptr)||(decay_product_2==nullptr)||(decay_product_3==nullptr))
  // {
  //   std::cerr<<"At least one of the smart pointers (four momentum pointer or one of the decay product pointers) is a null pointer,"
  //     <<"hence information about the GaugeBoson's four momentum and/or decay products cannot be printed.\n"<<std::endl;
  // }

  else if((four_momentum_ptr==nullptr)&(decay_products.size()!=0))
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the particle's "<<
      "four momentum cannot be printed."<<std::endl;
  }

  else if((four_momentum_ptr!=nullptr)&(decay_products.size()==0))
  {
    std::cerr<<"The decay product vector of this z-boson was empty, hence information about its "<<
      "produced particles cannot be printed."<<std::endl;
  }

  else
  {
    std::cerr<<"The decay product vector of this z-boson was empty and four momentum pointer is a null pointer,"
      <<" hence information about it cannot be printed."<<std::endl;
  }
}