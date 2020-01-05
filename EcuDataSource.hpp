#ifndef ECUDATASOURCE_HPP
#define ECUDATASOURCE_HPP

#include <vector>
#include "data_source.hpp"
#include "IObserver.hpp"

class EcuDataSource
{
public:
    EcuDataSource();

public:
    void AddPointObserver(IObserver<Point>& pointObserver);
    void AddLineObserver(IObserver<Line>& lineObserver);
    void AddAreaObserver(IObserver<Area>& areaObserver);

private:
    void NotifyPointObservers(Point const& point) const;
    void NotifyLineObservers(Line const& line) const;
    void NotifyAreaObservers(Area const& area) const;

private:
    std::vector<IObserver<Point>*> _pointObservers;
    std::vector<IObserver<Line>*> _lineObservers;
    std::vector<IObserver<Area>*> _areaObservers;
};

#endif
