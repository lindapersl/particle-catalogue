// PHYS 30762 Programming in C++
// Assignment 5

// Implementation of Muon class member functions

// Author: Linda Persley (student ID: 10683097)
// Date: 20/04/2024

#include<iostream>
#include<string>
#include<memory>
#include<iomanip>

#include"particle.h"
#include"lepton.h"
#include"muon.h"

// Print function
void Muon::print_info()
{
  if(four_momentum_ptr!=nullptr)
  {
    // Calling the equivalent lepton class function
    Lepton::print_info();

    std::cout<<"Muon isolation information = ";

    if(isolation_info == 0)
    {
      std::cout<<"Not isolated"<<std::endl;
    }

    else if(isolation_info == 1)
    {
      std::cout<<"Isolated"<<std::endl;
    }
  }

  else
  {
    std::cerr<<"The four momentum pointer is a null pointer, hence information about the "<<particle_type<<
      "'s four momentum cannot be printed."<<std::endl;
  }
}