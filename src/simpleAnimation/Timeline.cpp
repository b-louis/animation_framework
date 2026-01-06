#include <simpleAnimation/Timeline.hpp>
#include <simpleAnimation/Keyframes.hpp>
using namespace simpleAnimation;
void Timeline::addKeyframe(int *var, int value, int frame)
{
    Keyframes varKeyframes;
    // check if keyframes for this var exist
    if(keyframes.find(var) == keyframes.end())
    {
        keyframes[var] = Keyframes();
        varKeyframes = keyframes[var];
    }
    keyframes[var].addKeyframe(frame, value);
    return;
}

void Timeline::step()
{
    if (cursor < length)
    {
        for (auto const& [var, kf] : keyframes)
        {
            if (kDeltas[var].targetFrame == cursor)
            {
                *var = kf.getKeyframes().at(cursor);
                auto beginK = kf.getKeyframes().upper_bound(cursor+1);
                // initialize variable to first keyframe value
                kDeltas[var].delta = (float)(beginK->second - *var) / (float)(beginK->first - cursor);
                if (beginK != kf.getKeyframes().end())
                {
                    kDeltas[var].targetFrame = beginK->first;
                }                
            }else if (cursor <kDeltas[var].targetFrame)
            {
                *var += kDeltas[var].delta;
            }
            
        }
        cursor++;
    }
    
}

void Timeline::init()
{

    for (auto const& [var, kf] : keyframes)
    {
        auto beginK = kf.getKeyframes().upper_bound(0);
        /*
        // initialize variable to first keyframe value
        if (beginK->first == 0)
        {
            *var = beginK->second;
        }
        */
        kDeltas[var].delta = (float)(beginK->second - *var) / (float)(beginK->first - cursor);
        kDeltas[var].targetFrame = beginK->first;

    }
    
}

bool Timeline::end()
{
    return cursor >= length;
}