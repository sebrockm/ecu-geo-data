#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

template <class Data>
struct IObserver
{
    virtual ~IObserver() = default;
    virtual void Notify(Data const& data) = 0;
};

#endif
