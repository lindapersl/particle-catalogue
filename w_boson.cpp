// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of WBoson class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<memory>

#include"particle.h"
#include"gauge_boson.h"
#include"w_boson.h"

// Parameterised constructor
WBoson::WBoson(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double charge, double spin, double energy,
  double p_x, double p_y, double p_z) : GaugeBoson(charge, spin, "W-boson", energy, p_x, p_y, p_z)
{
  set_products(std::move(particle_1), std::move(particle_2)); // Input checking done within setter function
}

// Copy constructor
WBoson::WBoson(const WBoson &original_boson) : GaugeBoson(original_boson)
{
  // Deep copying the decay products of the original particle by iterating over each of its element of unique pointers
  std::vector<std::unique_ptr<Particle>>::iterator vector_iterator;

  for(vector_iterator=decay_products.begin();vector_iterator<decay_products.end();vector_iterator++)
  {
    decay_products.push_back((*vector_iterator)->clone());
  }

  std::cout<<"Copy constructor called in WBoson class for a "<<particle_type<<"."<<std::endl;
}

// Move constructor
WBoson::WBoson(WBoson &&original_boson) : GaugeBoson(std::move(original_boson))
{
  // Move data of the original particle to a new particle
  decay_products=std::move(original_boson.decay_products);

  // The data member of the original particle is reset automatically when moving a unique pointer

  std::cout<<"Move constructor called in WBoson class for a "<<particle_type<<"."<<std::endl;
}

// Move assignment operator
WBoson& WBoson::operator=(WBoson &&original_boson)
{
  // Avoiding self-assignment
  if(&original_boson==this)
  {
    std::cerr<<"Self-assignment detected, hence move assignment was not performed in"
    <<" WBoson class for a "<<particle_type<<"."<<std::endl;


    return *this;
  }

  else
  {
    // Calling the equivalent base class operator
    Particle::operator=(std::move(original_boson));

    // Move data of the original particle to a new particle
    decay_products=std::move(original_boson.decay_products);

    // The data member of the original particle is reset automatically when moving a unique pointer

    std::cout<<"Move assignment called in WBoson class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Copy assignment operator
WBoson& WBoson::operator=(const WBoson &original_boson)
{
  // Avoiding self-assignment
  if(&original_boson==this)
  {
    std::cerr<<"Self-assignment detected, hence copy assignment was not performed in WBoson class for a "
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

    std::cout<<"Copy assignment called in WBoson class for a "<<particle_type<<"."<<std::endl;
  
    return *this;
  }
}

// Setter function
void WBoson::set_products(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2)
{
  // Calculating the total charge of the decay products
  double sum_product_charge{particle_1->get_charge()+particle_2->get_charge()};

  // Checking if the total charge is equal to that of the WBoson particle
  if(sum_product_charge==get_charge())
  {
    // Ensuring the decay product vector is empty before appending
    if(decay_products.size()!=0)
    {
      std::cerr<<"The decay product vector of this w-boson was not empty. It will be cleared and filled with your new particles"
        <<std::endl;

      decay_products.clear();
    }

    decay_products.push_back(std::move(particle_1));
    decay_products.push_back(std::move(particle_2)); /// or clone?
  }

  // else if(abs(sum_product_charge)==abs(get_charge()))
  // {
  //   // This scenario can happen if an antiWBoson particle is instatiated - should be 
  //   // Ensuring the decay product vector is empty before appending
  //   if(decay_products.size()!=0)
  //   {
  //     std::cerr<<"The decay product vector of this WBoson particle was not empty.\nIt will be cleared and filled with your new particles"
  //       <<std::endl;

  //     decay_products.clear();
  //   }

  //   decay_products.push_back(particle_1->clone());
  //   decay_products.push_back(particle_2->clone());
  //   decay_products.push_back(particle_3->clone());
  // }

  else
  {
    std::cerr<<"The sum of decay product charges does not add up to the w-boson charge, so no decay products were set."<<std::endl;
  }
}

// Function to convert between particles and antiparticles
std::unique_ptr<Particle> WBoson::convert_particle()
{
  // Negating the charge
  particle_charge*=-1;

  // convert_and_set_products(std::move(decay_products[0]), std::move(decay_products[1]), std::move(decay_products[2]));
  set_products(std::move(decay_products[0]->convert_particle()), std::move(decay_products[1]->convert_particle()));

  // std::unique_ptr<Particle> converted_product_1{decay_products[0]->convert_particle()}; ////// std::move?
  // std::unique_ptr<Particle> converted_product_2{decay_products[1]->convert_particle()};
  // std::unique_ptr<Particle> converted_product_3{decay_products[2]->convert_particle()};


  // set_products(std::move(converted_product_1), std::move(converted_product_2), std::move(converted_product_3));
  

  // set_products(std::move(decay_products[0]->convert_particle()), std::move(decay_products[1]->convert_particle()),
  //   std::move(decay_products[2]->convert_particle()));

  if(particle_charge<0) // If w-boson should be W(-) after conversion
  {
    particle_type="W(-)-boson";
  }

  else if(particle_charge>0) // If w-boson should be W(+) after conversion
  {
    // Delete first four letters "anti"
    particle_type="W(+)-boson";
  }

  return this->clone();
}

// Print function
void WBoson::print_info()
{
  if((four_momentum_ptr!=nullptr)&(decay_products.size()!=0))//&(decay_product_1!=nullptr)&(decay_product_2!=nullptr)&(decay_product_3!=nullptr))
  {
    // Calling the equivalent GaugeBoson class function
    GaugeBoson::print_info();

      std::cout<<"Particles the w-boson decays to = "<<decay_products[0]->get_type()<<", "<<decay_products[1]->get_type()<<std::endl;
  }

  // else if((four_momentum_ptr==nullptr)||(decay_product_1==nullptr)||(decay_product_2==nullptr)||(decay_product_3==nullptr))
  // {
  //   std::cerr<<"At least one of the smart pointers (four momentum pointer or one of the decay product pointers) is a null pointer,"
  //     <<"hence information about the GaugeBoson's four momentum and/or decay products cannot be printed.\n"<<std::endl;
  // }

  else if((four_momentum_ptr==nullptr)&(decay_products.size()!=0))
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the w-boson's "<<
      "four momentum cannot be printed."<<std::endl;
  }

  else if((four_momentum_ptr!=nullptr)&(decay_products.size()==0))
  {
    std::cerr<<"The decay product vector of this w-boson was empty, hence information about its "<<
      "produced particles cannot be printed."<<std::endl;
  }

  else
  {
    std::cerr<<"The decay product vector of this w-boson was empty and four momentum pointer is a null pointer,"
      <<" hence information about it cannot be printed."<<std::endl;
  }
}