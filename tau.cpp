// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of Tau class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<memory>

#include"particle.h"
#include"lepton.h"
#include"tau.h"
#include"up.h"
#include"down.h"
#include"neutrino.h"

// Parameterised constructor (all taus have lepton number=1, charge=-1 and rest mass=1776.8 Mev/c^2 so these are set here)
Tau::Tau(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, std::unique_ptr<Particle> particle_3,
      double energy, double p_x, double p_y, double p_z) : Lepton(1, -1, "tau", 1776.8, energy, p_x, p_y, p_z)
{
  set_products(std::move(particle_1), std::move(particle_2), std::move(particle_3)); // Input checking done within setter function
}

// Copy constructor
Tau::Tau(const Tau &original_lepton) : Lepton(original_lepton)
{
  // Using the clone function to deep copy the decay products of the original particle by iterating over each element
  std::vector<std::unique_ptr<Particle>>::const_iterator vector_iterator;

  for(vector_iterator=(original_lepton.decay_products).begin();vector_iterator<(original_lepton.decay_products).end();vector_iterator++)
  {
    decay_products.push_back((*vector_iterator)->clone());
  }
}

// Move constructor
Tau::Tau(Tau &&original_lepton) : Lepton(std::move(original_lepton))
{
  // Move data of the original particle to a new particle
  decay_products=std::move(original_lepton.decay_products);

  // The data member of the original particle is reset automatically when moving a unique pointer
}

// Move assignment operator
Tau& Tau::operator=(Tau &&original_lepton)
{
  // Avoiding self-assignment
  if(&original_lepton==this)
  {
    std::cerr<<"Self-assignment detected, hence move assignment was not performed in"
    <<" Tau class for a "<<particle_type<<"."<<std::endl;


    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(std::move(original_lepton));

    // Move data of the original particle to a new particle
    decay_products=std::move(original_lepton.decay_products);

    // The data member of the original particle is reset automatically when moving a unique pointer
  
    return *this;
  }
}

// Copy assignment operator
Tau& Tau::operator=(const Tau &original_lepton)
{
  // Avoiding self-assignment
  if(&original_lepton==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment was not performed in Tau class for a "
    <<particle_type<<"."<<std::endl;

    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(original_lepton);

    // Using the clone function to deep copy the decay products of the original particle by iterating over each element
    std::vector<std::unique_ptr<Particle>>::const_iterator vector_iterator;

    for(vector_iterator=(original_lepton.decay_products).begin();vector_iterator<(original_lepton.decay_products).end();vector_iterator++)
    {
      decay_products.push_back((*vector_iterator)->clone());
    }
  
    return *this;
  }
}

// Setter function
void Tau::set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, std::unique_ptr<Particle> particle_3)
{
  // Calculating the total charge, lepton number and baryon number of the decay products
  double sum_product_charge{particle_1->get_charge()+particle_2->get_charge()+particle_3->get_charge()};
  int sum_l_number{particle_1->get_l_number()+particle_2->get_l_number()+particle_3->get_l_number()};
  double sum_b_number{particle_1->get_b_number()+particle_2->get_b_number()+particle_3->get_l_number()};

  // Ensuring the decay product vector is empty before appending
  if(decay_products.size()!=0)
  {
    std::cerr<<"The decay product vector of this "<<particle_type<<" was not empty. It will be cleared and filled with your new particles."
      <<std::endl;

    decay_products.clear();
  }

  // Checking if the total charge, lepton number and baryon number are equal to that of the tau particle
  if((sum_product_charge==get_charge())&(sum_l_number==get_l_number())&(sum_b_number==get_b_number()))
  {
    decay_products.push_back(std::move(particle_1));
    decay_products.push_back(std::move(particle_2));
    decay_products.push_back(std::move(particle_3));
  }

  else
  {
    std::cerr<<"The decay you chose is not physical as it breaks conservations laws()). The most probable decay will be chosen for you instead."
      <<std::endl;

    decay_products.push_back(std::make_unique<Up>("red", 15, 2, 4, 7)->convert_particle());
    decay_products.push_back(std::make_unique<Down>("green", 20, 13, 11, 9));
    decay_products.push_back(std::make_unique<Neutrino>(0, "tau", 10, 6, 12, 11));
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> Tau::convert_particle()
{
  // Negating the charge and lepton number
  particle_charge*=-1;
  lepton_number*=-1;

  // Converting each decay product and setting them to the data member
  set_products(std::move(decay_products[0]->convert_particle()), std::move(decay_products[1]->convert_particle()),
    std::move(decay_products[2]->convert_particle()));

  // If tau should be its antiparticle after conversion
  if(lepton_number<0)
  {
    particle_type="anti"+particle_type;
  }

  // If tau should be its particle after conversion
  else if(lepton_number>0)
  {
    // Delete first four letters "anti"
    particle_type=particle_type.erase(0, 4);
  }

  return std::make_unique<Tau>(*this);
}

// Print function
void Tau::print_info()
{
  if((four_momentum_ptr!=nullptr)&(decay_products.size()!=0))
  {
    // Calling the equivalent lepton class function
    Lepton::print_info();

      std::cout<<std::left<<std::setfill('.')<<std::setw(25)<<"Particles the tau decays to = "<<std::right<<std::setfill('.')<<std::setw(20)<<
        decay_products[0]->get_type()<<", "<<decay_products[1]->get_type()<<", "<<decay_products[2]->get_type()<<std::endl;
  }

  else if((four_momentum_ptr==nullptr)&(decay_products.size()!=0))
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }

  else if((four_momentum_ptr!=nullptr)&(decay_products.size()==0))
  {
    std::cerr<<"The decay product vector of the "<<particle_type<<" is empty, hence information about its "
      <<"produced particles cannot be printed."<<std::endl;
  }

  else
  {
    std::cerr<<"The decay product vector of the "<<particle_type<<" was empty and four momentum pointer is a null pointer,"
      <<" hence information about it cannot be printed."<<std::endl;
  }
}