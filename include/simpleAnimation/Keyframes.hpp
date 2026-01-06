#ifndef SIMPLE_ANIMATION_KEYFRAMES_HPP
#define SIMPLE_ANIMATION_KEYFRAMES_HPP

#include <vector>
#include <map>
#include <cmath>

namespace simpleAnimation {

class Keyframes {
public:

    Keyframes() = default;
    ~Keyframes() = default;

    void addKeyframe(int time, int value);
    const std::map<int,int>& getKeyframes() const
    {
        return keyframes;
    };

private:
    // The first int is the frame and the second int is the value
    std::map<int,int> keyframes;
};

} // namespace simpleAnimation

#endif // SIMPLE_ANIMATION_KEYFRAMES_HPP
