#include "EcuDataSource.hpp"
#include "IObserver.hpp"

#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

class DemoPointObserver : public IObserver<Point>
{
public:
    virtual void Notify(Point const&) override
    {
        std::cout << "DemoPointObserver observes point" << std::endl;
    }
};

class DemoLineObserver : public IObserver<Line>
{
public:
    virtual void Notify(Line const&) override
    {
        std::cout << "DemoLineObserver observes line" << std::endl;
    }
};

class DemoAreaObserver : public IObserver<Area>
{
public:
    virtual void Notify(Area const&) override
    {
        std::cout << "DemoAreaObserver observes area" << std::endl;
    }
};

class DemoAllObserver : public IObserver<Point>, public IObserver<Line>, public IObserver<Area>
{
public:
    virtual void Notify(Point const&) override
    {
        std::cout << "DemoAllObserver observes point" << std::endl;
    }

    virtual void Notify(Line const&) override
    {
        std::cout << "DemoAllObserver observes line" << std::endl;
    }

    virtual void Notify(Area const&) override
    {
        std::cout << "DemoAllObserver observes area" << std::endl;
    }
};

int main()
{
    DemoPointObserver pointObserver1;
    DemoLineObserver lineObserver1;
    DemoAreaObserver areaObserver1;
    DemoAllObserver allObserver1;

    EcuDataSource ecuDataSource;

    ecuDataSource.AddPointObserver(pointObserver1);
    ecuDataSource.AddPointObserver(allObserver1);
    ecuDataSource.AddLineObserver(lineObserver1);
    ecuDataSource.AddLineObserver(allObserver1);
    ecuDataSource.AddAreaObserver(areaObserver1);
    ecuDataSource.AddAreaObserver(allObserver1);

    std::this_thread::sleep_for(10s);

    DataSource::Destroy();
}
