// PHYS 30762 Programming in C++
// Project 2: A program to design and demonstrate the functionality of a data catalogue of Standard Model particles.
// The catalogue is a wrapper for std::map and it is based on a class hierarchy using abstract classes and polymorphism,
// in addition to a separate four momentum class.

// Author: Linda Persley (student ID: 10683097)
// Date: 12/05/2024

#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<map>
#include<iomanip>

#include"particle_container.h"
#include"four_momentum.h"
#include"particle.h"
#include"lepton.h"
#include"quark.h"
#include"gauge_boson.h"
#include"electron.h"
#include"muon.h"
#include"tau.h"
#include"neutrino.h"
#include"up.h"
#include"down.h"
#include"charm.h"
#include"strange.h"
#include"top.h"
#include"bottom.h"
#include"gluon.h"
#include"z_boson.h"
#include"w_boson.h"
#include"higgs.h"
#include"photon.h"

int main()
{
  // Defining the particle catalogue as a wrapper container for std:: map with particle type as the key
  ParticleContainer<Particle> particle_catalogue;

  // Instantiating the decay products of tau particles
  std::unique_ptr<Particle> tau_decay_product_1=std::make_unique<Muon>(0, 30, 5, 3, 7);
  std::unique_ptr<Particle> tau_decay_product_2=std::make_unique<Neutrino>(0, "muon", 10, 4, 7, 1)->convert_particle();
  std::unique_ptr<Particle> tau_decay_product_3=std::make_unique<Neutrino>(0, "tau", 8, 1, 2, 5)->convert_particle();

  // Instantiating the decay products of antitau particles
  std::unique_ptr<Particle> antitau_decay_product_1=std::make_unique<Down>("green", 12, 2, 12, 11);
  std::unique_ptr<Particle> antitau_decay_product_2=std::make_unique<Up>("blue", 34, 2, 25, 12)->convert_particle();
  std::unique_ptr<Particle> antitau_decay_product_3=std::make_unique<Neutrino>(0, "tau", 11, 4, 8, 1)->convert_particle();

  // Instantiating the decay products of the Z boson
  std::unique_ptr<Particle> z_boson_decay_product_1=std::make_unique<Up>("green", 41, 7, 11, 6);
  std::unique_ptr<Particle> z_boson_decay_product_2=std::make_unique<Up>("red", 17, 2, 1, 6)->convert_particle();

  // Instantiating the decay products of the W- boson
  std::unique_ptr<Particle> w_1_boson_decay_product_1=std::make_unique<Muon>(0, 28, 4, 11, 15);
  std::unique_ptr<Particle> w_1_boson_decay_product_2=std::make_unique<Neutrino>(0, "muon", 10, 1, 3, 6)->convert_particle();

  // Instantiating the decay products of the W+ boson
  std::unique_ptr<Particle> w_2_boson_decay_product_1=std::make_unique<Top>("red", 12, 2, 1, 5)->convert_particle();
  std::unique_ptr<Particle> w_2_boson_decay_product_2=std::make_unique<Bottom>("blue", 18, 6 , 12, 2);

  // Instantiating the decay products of the Higgs boson
  std::unique_ptr<Particle> higgs_decay_product_1=std::make_unique<Photon>(43, 13, 20, 3);
  std::unique_ptr<Particle> higgs_decay_product_2=std::make_unique<Photon>(20, 9, 12, 17);

  // Creating a catalogue with all 31 particles
  particle_catalogue["electron"]=std::make_unique<Electron>(10, 6, 4, 3, 1.6, 0.5, 0.7, 0.8);
  particle_catalogue["antielectron"]=std::make_unique<Electron>(13, 2, 5, 4, 24, 7, 5, 9)->convert_particle();
  particle_catalogue["muon"]=std::make_unique<Muon>(1, 20, 1, 2, 3);
  particle_catalogue["antimuon"]=std::make_unique<Muon>(1, 44, 6, 11, 8)->convert_particle();
  particle_catalogue["tau"]=std::make_unique<Tau>(std::move(tau_decay_product_1), std::move(tau_decay_product_2),
    std::move(tau_decay_product_3), 27, 3, 6, 8);
  particle_catalogue["antitau"]=std::make_unique<Tau>(std::move(antitau_decay_product_1), std::move(antitau_decay_product_2),
    std::move(antitau_decay_product_3), 18, 5, 7, 3)->convert_particle(); ///// Problem of converting decay products
  particle_catalogue["electron neutrino"]=std::make_unique<Neutrino>(0, "electron", 10, 2, 2, 1);
  particle_catalogue["electron antineutrino"]=std::make_unique<Neutrino>(0, "electron", 8, 1, 5, 3)->convert_particle();
  particle_catalogue["muon neutrino"]=std::make_unique<Neutrino>(0, "muon", 16, 6, 5, 1);
  particle_catalogue["muon antineutrino"]=std::make_unique<Neutrino>(0, "muon", 12, 2, 2, 1)->convert_particle();
  particle_catalogue["tau neutrino"]=std::make_unique<Neutrino>(0, "tau", 9, 4, 3, 6);
  particle_catalogue["tau antineutrino"]=std::make_unique<Neutrino>(0, "tau", 17, 7, 7, 3)->convert_particle();
  particle_catalogue["up"]=std::make_unique<Up>("blue", 11, 4, 5, 6);
  particle_catalogue["antiup"]=std::make_unique<Up>("red", 61, 77, 52, 13)->convert_particle();
  particle_catalogue["down"]=std::make_unique<Down>("red", 3, 1, 1, 2);
  particle_catalogue["antidown"]=std::make_unique<Down>("green", 18, 8, 6, 4)->convert_particle();
  particle_catalogue["charm"]=std::make_unique<Charm>("blue", 32, 9, 4, 7);
  particle_catalogue["anticharm"]=std::make_unique<Charm>("red", 12, 8, 6, 11)->convert_particle();
  particle_catalogue["strange"]=std::make_unique<Strange>("red", 16, 6, 6, 3);
  particle_catalogue["antistrange"]=std::make_unique<Strange>("green", 23, 3, 7, 7)->convert_particle();
  particle_catalogue["top"]=std::make_unique<Top>("blue", 44, 4, 8, 10);
  particle_catalogue["antitop"]=std::make_unique<Top>("blue", 18, 9, 13, 6)->convert_particle();
  particle_catalogue["bottom"]=std::make_unique<Bottom>("green", 30, 20, 23, 9);
  particle_catalogue["antibottom"]=std::make_unique<Bottom>("red", 29, 11, 3, 2)->convert_particle();
  particle_catalogue["gluon"]=std::make_unique<Gluon>("green", "antired", 33, 6, 4, 2);
  particle_catalogue["antigluon"]=std::make_unique<Gluon>("antigreen", "blue", 38, 9, 10, 15)->convert_particle();
  particle_catalogue["Z boson"]=std::make_unique<ZBoson>(std::move(z_boson_decay_product_1), std::move(z_boson_decay_product_2),
    20, 1, 2, 4);
  particle_catalogue["W- boson"]=std::make_unique<WBoson>(std::move(w_1_boson_decay_product_1), std::move(w_1_boson_decay_product_2),
    12, 2, 4, 7);
  particle_catalogue["W+ boson"]=std::make_unique<WBoson>(std::move(w_2_boson_decay_product_1), std::move(w_2_boson_decay_product_2),
    30, 2, 22, 12)->convert_particle();
  particle_catalogue["photon"]=std::make_unique<Photon>(56, 14, 21, 11);
  particle_catalogue["higgs boson"]=std::make_unique<Higgs>(std::move(higgs_decay_product_1), std::move(higgs_decay_product_2),
    12, 2, 1, 4);

  std::cout<<"Total number of particles in the catalogue : "<<particle_catalogue.get_total_number_particles()<<std::endl;

  std::cout<<"Number of lepton type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<Lepton>()<<std::endl;
  std::cout<<"Number of quark type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<Quark>()<<std::endl;
  std::cout<<"Number of gauge boson type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<GaugeBoson>()<<std::endl;
  std::cout<<"Number of scalar boson type particles in the catalogue : "<<particle_catalogue.get_number_particles_of_type<Higgs>()<<std::endl;
  
  // Defining a new sub-containers for leptons, quarks, gauge bosons and scalar bosons
  ParticleContainer<Particle> lepton_catalogue;
  ParticleContainer<Particle> quark_catalogue;
  ParticleContainer<Particle> gauge_boson_catalogue;
  ParticleContainer<Particle> scalar_boson_catalogue;

  lepton_catalogue=particle_catalogue.get_sub_container_of_type<Lepton>();
  quark_catalogue=particle_catalogue.get_sub_container_of_type<Quark>();
  gauge_boson_catalogue=particle_catalogue.get_sub_container_of_type<GaugeBoson>();
  scalar_boson_catalogue=particle_catalogue.get_sub_container_of_type<Higgs>();

  // Printing information about all particles in the complete catalogu
  std::cout<<"Information about all particles in the complete catalogue:\n"<<std::endl;
  particle_catalogue.print_catalogue();

  // Printing information about one particle (antitau for example)
  std::cout<<"Information about the antitau:\n"<<std::endl;
  lepton_catalogue.print_particle_info("antitau");

  // Summing the four momenta of all particles within the complete catalogue
  std::vector<double> sum_four_momentum=particle_catalogue.sum_four_momenta();

  // Taking the dot product of two particles (up quark and strange quark for example)
  double dot_product_up_strange=particle_catalogue.dot_product_four_momenta("up", "strange");

  // Subtracting the four momenta of two particles (electron and W(+) boson for example)
  std::vector<double> subtracted_electron_w_boson=particle_catalogue.subtract_four_momenta("electron", "W+ boson");

  // Clearing one of the containers (quark catalogue for example)
  quark_catalogue.clear_container();

  // Testing input checking by instantiating particles with wrong characteristics
  // For example, an antitau particle with 'illegal' decay products and non-physical four-momentum
  ParticleContainer<Particle> bad_particle_container;

  std::unique_ptr<Particle> bad_antitau_decay_product_1=std::make_unique<Photon>(12, 11, 1, 14);
  std::unique_ptr<Particle> bad_antitau_decay_product_2=std::make_unique<Charm>("green", 12, 2, 12, 7)->convert_particle();
  std::unique_ptr<Particle> bad_antitau_decay_product_3=std::make_unique<Down>("blue", 18, 22, 12, 13);

  bad_particle_container["tau"]=std::make_unique<Tau>(std::move(bad_antitau_decay_product_1), std::move
    (bad_antitau_decay_product_2), std::move(bad_antitau_decay_product_3), 29, 12, 15, 9)->convert_particle();

  // Another example of a gluon with the wrong colour charges (the same ones)
  bad_particle_container["gluon"]=std::make_unique<Gluon>("green", "red", 39, 12, 23, 3);

  // Another example of a neutrino with a 'bad' flavour (uncomment if needed - does terminate the code though)
  // bad_particle_container["bad neutrino"]=std::make_unique<Neutrino>(0, "bad", 12, 4, 13, 8);

  std::cout<<"Information about the corrected 'bad' particles:\n"<<std::endl;
  bad_particle_container.print_catalogue();

 return 0;
}