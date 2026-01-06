#include <simpleAnimation/Keyframes.hpp>
using namespace simpleAnimation;
void Keyframes::addKeyframe(int value, int frame)
{
    keyframes[frame] = value;
}
