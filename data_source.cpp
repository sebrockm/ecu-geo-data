#include "data_source.hpp"

DataSource::DataSource(
        std::function<void(Point const&)> newPointCallback,
        std::function<void(Line const&)> newLineCallback,
        std::function<void(Area const&)> newAreaCallback)
    : _newPointCallback(newPointCallback),
    _newLineCallback(newLineCallback),
    _newAreaCallback(newAreaCallback)
    { }

int main()
{
    DataSource dataSource(nullptr, nullptr, nullptr);
}
