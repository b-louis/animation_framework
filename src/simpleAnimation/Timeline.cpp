#include <simpleAnimation/Timeline.hpp>


void Timeline::addKeyframe(int &var, int value, int frame)
{
    auto componentKeyframes = keyframes[var];
    if(componentKeyframes)
    {
        keyframe k = componentKeyframes.find(frame);
        if (!k) // before first keyframe
        {
            keyframe newK = keyframe(frame, value);
            newK.next = componentKeyframes.first();
            componentKeyframes.first() = newK;
            return;
        }
        keyframe oldNextK = k ? k.next() : nullptr;
        keyframe newK = keyframe(frame, value);
        k.next = newK;
        newK.next = oldNextK;
    }
    else
    {
        keyframes[var] = keyframes(var);
        keyframe newK = keyframe(frame, value);
        keyframes[var].first() = newK;
    }
}

void Timeline::step()
{
    if (cursor < length)
    {
        cursor++;
    }
    
}

bool Timeline::end()
{
    return cursor >= length;
}