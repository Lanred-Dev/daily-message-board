#pragma once

#include <vector>
#include <functional>

template <typename... Args>
class Signal
{
private:
    std::vector<std::function<void(Args...)>> _subscribers;

public:
    void connect(std::function<void(Args...)> callback)
    {
        _subscribers.push_back(callback);
    }

    void disconnect(std::function<void(Args...)> callback)
    {
        _subscribers.erase(std::remove(_subscribers.begin(), _subscribers.end(), callback), _subscribers.end());
    }

    void emit(Args... args)
    {
        for (const auto &callback : _subscribers)
        {
            callback(args...);
        }
    }
};