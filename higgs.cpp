// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of Higgs class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<memory>

#include"particle.h"
#include"higgs.h"

// Parameterised constructor (all Higgs bosons have charge and spin zero and rest mass= 125110 MeV/c^2,
// so these are set here)
Higgs::Higgs(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double energy,
  double p_x, double p_y, double p_z) : Particle(0, 0, "higgs", 125110, energy, p_x, p_y, p_z)
{
  set_products(std::move(particle_1), std::move(particle_2)); // Input checking done within setter function
}

// Copy constructor
Higgs::Higgs(const Higgs &original_boson) : Particle(original_boson)
{
  // Deep copying the decay products of the original particle by iterating over each of its element of unique pointers
  std::vector<std::unique_ptr<Particle>>::const_iterator vector_iterator;

  for(vector_iterator=(original_boson.decay_products).begin();vector_iterator<(original_boson.decay_products).end();vector_iterator++)
  {
    decay_products.push_back((*vector_iterator)->clone());
  }

  std::cout<<"Copy constructor called in Higgs class for a "<<particle_type<<"."<<std::endl;
}

// Move constructor
Higgs::Higgs(Higgs &&original_boson) : Particle(std::move(original_boson))
{
  // Move data of the original particle to a new particle
  decay_products=std::move(original_boson.decay_products);

  // The data member of the original particle is reset automatically when moving a unique pointer

  std::cout<<"Move constructor called in Higgs class for a "<<particle_type<<"."<<std::endl;
}

// Move assignment operator
Higgs& Higgs::operator=(Higgs &&original_boson)
{
  // Avoiding self-assignment
  if(&original_boson==this)
  {
    std::cerr<<"Self-assignment detected, hence move assignment was not performed in"
    <<" Higgs class for a "<<particle_type<<"."<<std::endl;


    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(std::move(original_boson));

    // Move data of the original particle to a new particle
    decay_products=std::move(original_boson.decay_products);

    // The data member of the original particle is reset automatically when moving a unique pointer

    std::cout<<"Move assignment called in Higgs class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Copy assignment operator
Higgs& Higgs::operator=(const Higgs &original_boson)
{
  // Avoiding self-assignment
  if(&original_boson==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment was not performed in Higgs class for a "
    <<particle_type<<"."<<std::endl;

    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(original_boson);

    // Deep copying the decay products of the original particle by iterating over each of its element of unique pointers
    std::vector<std::unique_ptr<Particle>>::const_iterator vector_iterator;

    for(vector_iterator=(original_boson.decay_products).begin();vector_iterator<(original_boson.decay_products).end();vector_iterator++)
    {
      decay_products.push_back((*vector_iterator)->clone());
    }

    std::cout<<"Copy assignment called in Higgs class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Setter function
void Higgs::set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2)
{
  // Calculating the total charge of the decay products
  double sum_product_charge{particle_1->get_charge()+particle_2->get_charge()};

  // Checking if the total charge is equal to that of the Higgs particle
  if(sum_product_charge==get_charge())
  {
    // Ensuring the decay product vector is empty before appending
    if(decay_products.size()!=0)
    {
      std::cerr<<"The decay product vector of this higgs boson was not empty. It will be cleared and filled with your new particles"
        <<std::endl;

      decay_products.clear();
    }

    decay_products.push_back(std::move(particle_1));
    decay_products.push_back(std::move(particle_2)); /// or clone?
  }

  // else if(abs(sum_product_charge)==abs(get_charge()))
  // {
  //   // This scenario can happen if an antiHiggs particle is instatiated - should be 
  //   // Ensuring the decay product vector is empty before appending
  //   if(decay_products.size()!=0)
  //   {
  //     std::cerr<<"The decay product vector of this Higgs particle was not empty.\nIt will be cleared and filled with your new particles"
  //       <<std::endl;

  //     decay_products.clear();
  //   }

  //   decay_products.push_back(particle_1->clone());
  //   decay_products.push_back(particle_2->clone());
  //   decay_products.push_back(particle_3->clone());
  // }

  else
  {
    std::cerr<<"The sum of decay product charges does not add up to the higgs boson charge, so no decay products were set."<<std::endl;
  }
}

// Print function
void Higgs::print_info()
{
  if((four_momentum_ptr!=nullptr)&(decay_products.size()!=0))//&(decay_product_1!=nullptr)&(decay_product_2!=nullptr)&(decay_product_3!=nullptr))
  {
    // Calling the equivalent Particle class function
    Particle::print_info();

      std::cout<<"Particles the higgs-boson decays to = "<<decay_products[0]->get_type()<<", "<<decay_products[1]->get_type()<<std::endl;
  }

  // else if((four_momentum_ptr==nullptr)||(decay_product_1==nullptr)||(decay_product_2==nullptr)||(decay_product_3==nullptr))
  // {
  //   std::cerr<<"At least one of the smart pointers (four momentum pointer or one of the decay product pointers) is a null pointer,"
  //     <<"hence information about the Particle's four momentum and/or decay products cannot be printed.\n"<<std::endl;
  // }

  else if((four_momentum_ptr==nullptr)&(decay_products.size()!=0))
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }

  else if((four_momentum_ptr!=nullptr)&(decay_products.size()==0))
  {
    std::cerr<<"The decay product vector of this tau particle was empty, hence information about the "<<particle_type<<
      "'s produced particles cannot be printed."<<std::endl;
  }

  else
  {
    std::cerr<<"The decay product vector of this tau particle was empty and four momentum pointer is a null pointer,"
      <<" hence information about the "<<particle_type<<" cannot be printed."<<std::endl;
  }
}