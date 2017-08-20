//
// Created by john on 8/20/17.
//

#include "barker_eventqueue.h"

namespace barker {

EventQueue::EventQueue(std::string topic)
    : m_topic(std::move(topic)),
      m_queuedIds(),
      m_lock() {}

EventQueue::~EventQueue() {}

void EventQueue::push(Event event) {
    std::lock_guard<std::recursive_mutex> lock(const_cast<std::recursive_mutex &>(m_lock));
    if(m_queuedIds.end() != m_queuedIds.find(event.id())) {
        return;
    }
    m_events.emplace_back(std::move(event));
}

Event EventQueue::front() const {
    std::lock_guard<std::recursive_mutex> lock(const_cast<std::recursive_mutex &>(m_lock));
    if(!m_events.empty()) {
        return m_events.front();
    } else {
        throw std::runtime_error("EventQueue is empty, cannot return front event.");
    }
}

void EventQueue::pop() {
    std::lock_guard<std::recursive_mutex> lock(const_cast<std::recursive_mutex &>(m_lock));
    if(!m_events.empty()) {
        m_events.erase(m_events.begin());
    }
}

size_t EventQueue::size() const {
    std::lock_guard<std::recursive_mutex> lock(const_cast<std::recursive_mutex &>(m_lock));
    return m_events.size();
}

}