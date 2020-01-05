#ifndef DATA_SOURCE_HPP
#define DATA_SOURCE_HPP

#include <functional>

struct Point {};
struct Line {};
struct Area {};


class DataSource
{
public:
    static void SetNewPointCallback(std::function<void(Point const&)> callback);
    static void SetNewLineCallback(std::function<void(Line const&)> callback);
    static void SetNewAreaCallback(std::function<void(Area const&)> callback);

private:
    static std::function<void(Point const&)> s_newPointCallback;
    static std::function<void(Line const&)> s_newLineCallback;
    static std::function<void(Area const&)> s_newAreaCallback;
};

#endif
