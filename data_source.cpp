#include "data_source.hpp"

#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

std::function<void(Point const&)> DataSource::_pointCallback = {};
std::function<void(Line const&)> DataSource::_lineCallback = {};
std::function<void(Area const&)> DataSource::_areaCallback = {};

std::thread DataSource::_pointCreator = std::thread([]
{
    while (_isRunning)
    {
        std::this_thread::sleep_for(1ms);
        if (_pointCallback)
            _pointCallback(Point{});
    }
});

std::thread DataSource::_lineCreator = std::thread([]
{
    while (_isRunning)
    {
        std::this_thread::sleep_for(1ms);
        if (_lineCallback)
            _lineCallback(Line{});
    }
});

std::thread DataSource::_areaCreator = std::thread([]
{
    while (_isRunning)
    {
        std::this_thread::sleep_for(1ms);
        if (_areaCallback)
            _areaCallback(Area{});
    }
});

std::atomic_bool DataSource::_isRunning = true;

void DataSource::SetPointCallback(std::function<void(Point const&)> pointCallback)
{
    _pointCallback = std::move(pointCallback);
}

void DataSource::SetLineCallback(std::function<void(Line const&)> lineCallback)
{
    _lineCallback = std::move(lineCallback);
}

void DataSource::SetAreaCallback(std::function<void(Area const&)> areaCallback)
{
    _areaCallback = std::move(areaCallback);
}

void DataSource::Destroy()
{
    _isRunning = false;
    _pointCreator.join();
    _lineCreator.join();
    _areaCreator.join();
}

int main()
{
    DataSource::SetPointCallback([] (Point const&) { std::cout << "new point" << std::endl; });
    DataSource::SetLineCallback([] (Line const&) { std::cout << "new line" << std::endl; });
    DataSource::SetAreaCallback([] (Area const&) { std::cout << "new area" << std::endl; });

    std::this_thread::sleep_for(10s);

    DataSource::Destroy();
}
