#include "data_source.hpp"

std::function<void(Point const&)> DataSource::s_newPointCallback = nullptr;
std::function<void(Line const&)> DataSource::s_newLineCallback = nullptr;
std::function<void(Area const&)> DataSource::s_newAreaCallback = nullptr;

void DataSource::SetNewPointCallback(std::function<void(Point const&)> callback)
{
    s_newPointCallback = callback;
}

void DataSource::SetNewLineCallback(std::function<void(Line const&)> callback)
{
    s_newLineCallback = callback;
}

void DataSource::SetNewAreaCallback(std::function<void(Area const&)> callback)
{
    s_newAreaCallback = callback;
}

int main()
{
}
