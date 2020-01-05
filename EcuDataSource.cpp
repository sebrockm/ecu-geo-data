#include "EcuDataSource.hpp"

EcuDataSource::EcuDataSource()
{
    DataSource::SetPointCallback([=] (Point const& point) { NotifyPointObservers(point); });
    DataSource::SetLineCallback([=] (Line const& line) { NotifyLineObservers(line); });
    DataSource::SetAreaCallback([=] (Area const& area) { NotifyAreaObservers(area); });
}

void EcuDataSource::AddPointObserver(IObserver<Point>& pointObserver)
{
    _pointObservers.push_back(&pointObserver);
}

void EcuDataSource::AddLineObserver(IObserver<Line>& lineObserver)
{
    _lineObservers.push_back(&lineObserver);
}

void EcuDataSource::AddAreaObserver(IObserver<Area>& areaObserver)
{
    _areaObservers.push_back(&areaObserver);
}

void EcuDataSource::NotifyPointObservers(Point const& point) const
{
    for (auto pObserver: _pointObservers)
        pObserver->Notify(point);
}

void EcuDataSource::NotifyLineObservers(Line const& line) const
{
    for (auto pObserver: _lineObservers)
        pObserver->Notify(line);
}

void EcuDataSource::NotifyAreaObservers(Area const& area) const
{
    for (auto pObserver: _areaObservers)
        pObserver->Notify(area);
}
