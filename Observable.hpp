#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <vector>

template <class Data>
class Observable
{
public:
    void AddObserver(IObserver<Data>& observer)
    {
        _observers.push_back(&observer);
    }

protected:
    void NotifyObservers(Data const& data) const
    {
        for (auto pObserver: _observers)
            pObserver->Notify(data);
    }

private:
    std::vector<IObserver<Data>*> _observers;
};

#endif
