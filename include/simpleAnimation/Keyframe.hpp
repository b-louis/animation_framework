#ifndef SIMPLE_ANIMATION_KEYFRAME_HPP
#define SIMPLE_ANIMATION_KEYFRAME_HPP

#include <cstdint>
#include <vector>

namespace SimpleAnimation {

class Keyframe {
public:
    Keyframe(uint32_t time, const int& value);
    
    uint32_t getTime() const;
    int getValue() const;
    void setValue(const int& value);
    
private:
    uint32_t m_time;
    int m_value;
};

Keyframe::Keyframe(uint32_t time, const int& value)
    : m_time(time), m_value(value) {}

uint32_t Keyframe::getTime() const {
    return m_time;
}

int Keyframe::getValue() const {
    return m_value;
}

void Keyframe::setValue(const int& value) {
    m_value = value;
}

}  // namespace SimpleAnimation

#endif  // SIMPLE_ANIMATION_KEYFRAME_HPP