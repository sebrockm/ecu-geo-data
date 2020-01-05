#ifndef DATA_SOURCE_HPP
#define DATA_SOURCE_HPP

#include <functional>

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

private:
    std::function<void(Point const&)> _newPointCallback;
    std::function<void(Line const&)> _newLineCallback;
    std::function<void(Area const&)> _newAreaCallback;
};

#endif
