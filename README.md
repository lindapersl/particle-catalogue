Supplementary instructions on how to use the code:

New elements of the particle containers can be created by the use of the overloaded subscript operator, and they have to be unique pointers to particles as specified in the template function ParticleContainer.

Input parameters of parameterised constructors are as follows:

- FourMomentum(double rest_mass, double energy, double p_x, double p_y, double p_z)
- Particle(double charge, double spin, std::string type, double rest_mass, double energy, double p_x, double p_y, double p_z)
- Lepton(int l_number, double charge, std::string type, double rest_mass, double energy, double p_x, double p_y, double p_z)
- Electron(double layer_1, double layer_2, double layer_3, double layer_4, double energy, double p_x, double p_y, double p_z)
- Muon(bool isolated, double energy, double p_x, double p_y, double p_z)
- Tau(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, std::unique_ptr<Particle> particle_3, double energy, double p_x, double p_y, double p_z)
- Neutrino(bool interacted, std::string flavour, double energy, double p_x, double p_y, double p_z)
- Quark(double b_number, std::string colour, double charge, std::string type, double rest_mass, double energy, double p_x, double p_y, double p_z)
- Up(std::string colour, double energy, double p_x, double p_y, double p_z)
- Down(std::string colour, double energy, double p_x, double p_y, double p_z)
- Charm(std::string colour, double energy, double p_x, double p_y, double p_z)
- Strange(std::string colour, double energy, double p_x, double p_y, double p_z)
- Top(std::string colour, double energy, double p_x, double p_y, double p_z)
- Bottom(std::string colour, double energy, double p_x, double p_y, double p_z)
- GaugeBoson(double charge, std::string type, double rest_mass, double energy, double p_x, double p_y, double p_z)
- Photon(double energy, double p_x, double p_y, double p_z)
- Gluon(std::string colour_1, std::string colour_2, double energy, double p_x, double p_y, double p_z)
- ZBoson(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double energy, double p_x, double p_y, double p_z)
- WBoson(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double energy, double p_x, double p_y, double p_z)
- Higgs(std::unique_ptr<Particle> particle_1, std::unique_ptr<Particle> particle_2, double energy, double p_x, double p_y, double p_z)

Where unique pointers to the decay products of tau, Z Boson, W boson and Higgs Boson should be inputted as an argument using move semantics as explained in the project report.