#include "data_source.hpp"

#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

DataSource::DataSource(
        std::function<void(Point const&)> newPointCallback,
        std::function<void(Line const&)> newLineCallback,
        std::function<void(Area const&)> newAreaCallback)
    : _newPointCallback(newPointCallback),
    _newLineCallback(newLineCallback),
    _newAreaCallback(newAreaCallback)
{
    _pointCreator = std::thread([=]
    {
        while (true)
        {
            std::this_thread::sleep_for(1ms);
            if (_newPointCallback)
                _newPointCallback(Point{});
        }
    });
    _lineCreator = std::thread([=]
    {
        while (true)
        {
            std::this_thread::sleep_for(1ms);
            if (_newLineCallback)
                _newLineCallback(Line{});
        }
    });
    _areaCreator = std::thread([=]
    {
        while (true)
        {
            std::this_thread::sleep_for(1ms);
            if (_newAreaCallback)
                _newAreaCallback(Area{});
        }
    });
}

int main()
{
    DataSource dataSource(
            [] (Point const&) { std::cout << "new point" << std::endl; },
            [] (Line const&) { std::cout << "new line" << std::endl; },
            [] (Area const&) { std::cout << "new area" << std::endl; });

    std::this_thread::sleep_for(10s);
}
