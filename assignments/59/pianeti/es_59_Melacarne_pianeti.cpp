#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

constexpr int N_PLANETS = 8;

typedef struct {
  string name;
  int diameter;
  int moons;
  int orbitDuration;
  double rotationPeriod;
  int64_t distanceFromSun;
} Planet;

Planet newPlanet(string name, int diameter, int moons, int orbitDuration,
                 double rotationPeriod, int64_t distanceFromSun) {
  Planet planet;
  planet.name = name;
  planet.diameter = diameter;
  planet.moons = moons;
  planet.orbitDuration = orbitDuration;
  planet.rotationPeriod = rotationPeriod;
  planet.distanceFromSun = distanceFromSun;
  return planet;
}

void printPlanet(Planet planet) {
  cout << "Name: " << planet.name << endl;
  cout << "Diameter: " << planet.diameter << " km" << endl;
  cout << "Moons: " << planet.moons << endl;
  cout << "Orbit duration: " << planet.orbitDuration << " days" << endl;
  cout << "Rotation period: " << planet.rotationPeriod << " days" << endl;
  cout << "Distance from Sun: " << planet.distanceFromSun << " km" << endl;
}

int main() {
  array<Planet, N_PLANETS> planets{
      newPlanet("Mercury", 4879, 0, 88, 58.6, 57910000),
      newPlanet("Venus", 12104, 0, 225, 243, 108200000),
      newPlanet("Earth", 12756, 1, 365, 1, 149600000),
      newPlanet("Mars", 6792, 2, 687, 1.03, 227900000),
      newPlanet("Jupiter", 142984, 79, 4333, 0.41, 778600000),
      newPlanet("Saturn", 120536, 62, 10759, 0.45, 1433500000),
      newPlanet("Uranus", 51118, 27, 30687, -0.72, 2872500000),
      newPlanet("Neptune", 49528, 14, 60190, 0.67, 4495100000)};

  for (auto planet : planets) {
    printPlanet(planet);
  }

  return 0;
}
