//
// Created by john on 8/20/17.
//
#include "barker_event.h"
#include <iomanip>
#include <iterator>


namespace barker {

Event::Event(std::string id, std::string topic,
             std::chrono::system_clock::time_point timestamp)
    : m_id(id),
      m_topic(std::move(topic)),
      m_timestamp(std::move(timestamp)) {}

Event::~Event() {}

void Event::addTag(const std::string & tag) {
    m_tags.emplace_back(tag);
}

const std::vector<std::string> & Event::tags() const {
    return m_tags;
}

const std::string & Event::topic() const {
    return m_topic;
}

const std::chrono::system_clock::time_point & Event::timestamp() const {
    return m_timestamp;
}

const std::string & Event::id() const {
    return m_id;
}

void Event::print(std::ostream & out) const {
    time_t timestamp_time_t = std::chrono::system_clock::to_time_t(m_timestamp);
    out << "<Event (topic=" << m_topic
        << ", timestamp=" << std::put_time(std::gmtime(&timestamp_time_t), "%DT%T")
        << ", tags=[";
    std::copy(m_tags.begin(), m_tags.end(), std::ostream_iterator<std::string>(out, ","));
    out << "]>";
}

}