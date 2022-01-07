#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <map>


class Point
{
    double x;
    double y;

    Point();
};

class Section
{
    Point p1;
    Point p2;

    Point direction;

    Section();
};

class Particle
{
    double x;
    double y;

    Particle()
    {
        this->x = 0;
        this->y = 0;
    }

    Particle(std::mt19937 gen, std::normal_distribution<> d)
    {
        this->x = d(gen);
        this->y = d(gen);
    }

    void move();
};

class GeometryBox
{
    std::vector<Section> bounce_box;
    std::vector<Section> cooper_iron_box;
    std::vector<Section> cooper_void_box;

    bool is_in_iron(Point p);
    bool is_in_cooper(Point p);

    double iron_param;
    double cooper_param;
};

class Simulation
{
    std::vector<Particle> particles;
    GeometryBox geometry_box;

    Simulation();
};

int main()
{
    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution<> d{0,1};

    std::map<int, int> hist{};
    for(int n=0; n<10000; ++n) {
        ++hist[std::round(d(gen))];
    }

    std::cout << "Hello, world!\n";

    return 0;
}