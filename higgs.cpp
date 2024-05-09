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
#include"bottom.h"

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
  // Using the clone function to deep copy the decay products of the original particle by iterating over each element
  std::vector<std::unique_ptr<Particle>>::const_iterator vector_iterator;

  for(vector_iterator=(original_boson.decay_products).begin();vector_iterator<(original_boson.decay_products).end();
    vector_iterator++)
  {
    decay_products.push_back((*vector_iterator)->clone());
  }
}

// Move constructor
Higgs::Higgs(Higgs &&original_boson) : Particle(std::move(original_boson))
{
  // Move data of the original particle to a new particle
  decay_products=std::move(original_boson.decay_products);

  // The data member of the original particle is reset automatically when moving a unique pointer
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

    // Using the clone function to deep copy the decay products of the original particle by iterating over each element
    std::vector<std::unique_ptr<Particle>>::const_iterator vector_iterator;

    for(vector_iterator=(original_boson.decay_products).begin();vector_iterator<(original_boson.decay_products).end();
      vector_iterator++)
    {
      decay_products.push_back((*vector_iterator)->clone());
    }
  
    return *this;
  }
}

// Setter function
void Higgs::set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2)
{
  // Calculating the total charge, lepton number and baryon number of the decay products
  double sum_product_charge{particle_1->get_charge()+particle_2->get_charge()};
  int sum_l_number{particle_1->get_l_number()+particle_2->get_l_number()};
  double sum_b_number{particle_1->get_b_number()+particle_2->get_b_number()};

  // Ensuring the decay product vector is empty before appending
  if(decay_products.size()!=0)
  {
    std::cerr<<"The decay product vector of this "<<particle_type<<" was not empty. It will be cleared and filled with your new particles."
      <<std::endl;

    decay_products.clear();
  }

  // Checking if the total charge, lepton number and baryon number are equal to that of the Higgs boson
  if((sum_product_charge==get_charge())&(sum_l_number==get_l_number())&(sum_b_number==get_b_number()))
  {
    decay_products.push_back(std::move(particle_1));
    decay_products.push_back(std::move(particle_2));
  }

  else
  {
    std::cerr<<"The decay you chose is not physical as it breaks conservations law(s). The most probable decay will be chosen for you instead."
      <<std::endl;

    decay_products.push_back(std::make_unique<Bottom>("red", 26, 13, 20, 9));
    decay_products.push_back(std::make_unique<Bottom>("green", 19, 15, 1, 7)->convert_particle());
  }
}

// Print function
void Higgs::print_info()
{
  if((four_momentum_ptr!=nullptr)&(decay_products.size()!=0))
  {
    // Calling the equivalent Particle class function
    Particle::print_info();

      std::cout<<std::left<<std::setfill('.')<<std::setw(25)<<"Particles the higgs-boson decays to = "<<std::right<<
        std::setfill('.')<<std::setw(18)<<decay_products[0]->get_type()<<", "<<decay_products[1]->get_type()<<std::endl;
  }

  else if((four_momentum_ptr==nullptr)&(decay_products.size()!=0))
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }

  else if((four_momentum_ptr!=nullptr)&(decay_products.size()==0))
  {
    std::cerr<<"The decay product vector of the "<<particle_type<<" was empty, hence information about its "<<
      "produced particles cannot be printed."<<std::endl;
  }

  else
  {
    std::cerr<<"The decay product vector of the "<<particle_type<<" was empty and four momentum pointer is a null pointer,"
      <<" hence information about it cannot be printed."<<std::endl;
  }
}