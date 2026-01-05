#ifndef SIMPLE_ANIMATION_KEYFRAMES_HPP
#define SIMPLE_ANIMATION_KEYFRAMES_HPP

#include <vector>
#include <map>
#include <cmath>

namespace simpleAnimation {

class Keyframes {
public:
    struct Keyframe {
        int time;
        int value;
    };

    Keyframes() = default;
    ~Keyframes() = default;

    void addKeyframe(int time, int value);
    void removeKeyframe(int time);
    void clear();

    int evaluate(int time) const;
    int getDuration() const;
    bool isEmpty() const;

    const std::map<int&,Keyframe>& getKeyframes() const;

private:
    std::vector<Keyframe> keyframes;

    int findKeyframeIndex(int time) const;
};

} // namespace simpleAnimation

#endif // SIMPLE_ANIMATION_KEYFRAMES_HPP
