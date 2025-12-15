#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include <string>

template<typename... Args>
class Event 
{
    struct Subscription
    {
        int Id = 0;
        std::function<void(Args...)> Function; 
    };
    

    private:

    std::vector<Subscription> _messages;
    int _nextId = 0;

    public:

    int subscribe(const std::function<void(Args...)>& func)
    {
        _nextId ++;
        _messages.push_back({_nextId, func});
        return _nextId;
    }

    void trigger(Args... args)
    {
        for(auto& sub : _messages)
        {
            sub.Function(args...);
        }
    }
    
    void unsubscribe(uint64_t id) 
    {
        int removeIndex = 0;

        for(auto& sub : _messages)
        {
            if(sub.ID == id)
                break;

            removeIndex++;
        }

        if(removeIndex < _messages.size())
            _messages.erase(_messages.begin() + removeIndex);
    }

};