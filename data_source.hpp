#ifndef DATA_SOURCE_HPP
#define DATA_SOURCE_HPP

#include <atomic>
#include <functional>
#include <thread>

struct Point {};
struct Line {};
struct Area {};


class DataSource
{
public:
    DataSource(
            std::function<void(Point const&)> newPointCallback,
            std::function<void(Line const&)> newLineCallback,
            std::function<void(Area const&)> newAreaCallback);

    ~DataSource();

private:
    std::function<void(Point const&)> _newPointCallback;
    std::function<void(Line const&)> _newLineCallback;
    std::function<void(Area const&)> _newAreaCallback;

    std::thread _pointCreator;
    std::thread _lineCreator;
    std::thread _areaCreator;

    std::atomic_bool _running = true;
};

#endif
