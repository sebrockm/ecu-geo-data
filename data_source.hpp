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
    static void SetPointCallback(std::function<void(Point const&)> pointCallback);
    static void SetLineCallback(std::function<void(Line const&)> lineCallback);
    static void SetAreaCallback(std::function<void(Area const&)> areaCallback);

    static void Destroy();

private:
    static std::function<void(Point const&)> _pointCallback;
    static std::function<void(Line const&)> _lineCallback;
    static std::function<void(Area const&)> _areaCallback;

    static std::thread _pointCreator;
    static std::thread _lineCreator;
    static std::thread _areaCreator;

    static std::atomic_bool _isRunning;
};

#endif
