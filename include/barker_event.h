//
// Created by john on 8/20/17.
//

#ifndef BARKER_EVENT_H
#define BARKER_EVENT_H

#include <string>
#include <chrono>
#include <vector>
#include <ostream>

namespace barker {
class Event {
public:
    Event() = delete;
    Event(std::string id, std::string topic, std::chrono::system_clock::time_point timestamp);
    ~Event();
    void addTag(const std::string & tag);
    const std::vector<std::string> & tags() const;
    const std::string & topic() const;
    const std::chrono::system_clock::time_point & timestamp() const;
    const std::string & id() const;
    void print(std::ostream & out) const;
private:
    std::string m_id;
    std::string m_topic;
    std::vector<std::string> m_tags;
    std::chrono::system_clock::time_point m_timestamp;
};
}

#endif //BARKER_EVENT_H
