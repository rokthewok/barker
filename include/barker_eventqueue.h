//
// Created by john on 8/20/17.
//

#ifndef BARKER_EVENTQUEUE_H
#define BARKER_EVENTQUEUE_H

#include <string>
#include <unordered_set>
#include <mutex>
#include "barker_event.h"

namespace barker {
class EventQueue {
public:
    EventQueue() = delete;
    EventQueue(const EventQueue & other) = delete;
    EventQueue & operator=(const EventQueue & lhs) = delete;
    explicit EventQueue(std::string topic);
    ~EventQueue();
    void push(Event event);
    Event front() const;
    void pop();
    size_t size() const;
private:
    std::string m_topic;
    std::unordered_set<std::string> m_queuedIds;
    std::vector<Event> m_events;
    std::recursive_mutex m_lock;
};
}

#endif //BARKER_EVENTQUEUE_H
