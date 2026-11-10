#include <simpleAnimation/Timeline.hpp>
#include <simpleAnimation/Keyframes.hpp>
using namespace simpleAnimation;

/// @brief Function to add a keyframe to the timeline for a specific variable at a specific frame with a specific value
/// @param var value adress of the variable to be animated
/// @param value value of the variable at the keyframe
/// @param frame frame number of the keyframe
void Timeline::addKeyframe(int *var, int value, int frame)
{
    // Keyframes varKeyframes;
    // check if keyframes for this var exist
    if (keyframes.find(var) == keyframes.end())
    {
        keyframes[var] = KeyframeMap();
        // varKeyframes = keyframes[var];
    }
    keyframes[var][frame] = value;
    return;
}

void Timeline::stepForward()
{
    if (cursor < length)
    {
        for (auto &[var, kf] : keyframes)
        {
            float dummyEase = 0;
            auto next_key = nextkeyf_ptrs[var];
            auto iter = keyframesIterators[var];
            if (next_key == nullptr)
            {
                continue;
            }

            *var += kDeltas[var] + dummyEase;

            if (cursor != next_key->first)
            {
                continue;
            }

            *var = next_key->second;
            ++iter;
            prevkeyf_ptrs[var] = next_key;

            if (iter == kf.end())
            {
                nextkeyf_ptrs[var] = nullptr;
                continue;
            }
            keyframesIterators[var] = iter;
            nextkeyf_ptrs[var] = reinterpret_cast<std::pair<int, int> *>(&(*iter));
            kDeltas[var] = (float)(nextkeyf_ptrs[var]->second - *var) / (float)(nextkeyf_ptrs[var]->first - cursor);
        }

        cursor++;
    }
}

void Timeline::init()
{
    for (auto &[var, kf] : keyframes)
    {
        keyframesIterators[var] = kf.begin();
        prevkeyf_ptrs[var] = nullptr;
        nextkeyf_ptrs[var] = nullptr;
        if (kf.begin() != kf.end())
        {
            /*
            if (kf.begin()->first == 0)
            {
                *var = kf.begin()->second;
                keyframesIterators[var]++;
            }
            */
            auto next_key = kf.begin();
            nextkeyf_ptrs[var] = reinterpret_cast<std::pair<int, int> *>(&(*kf.begin()));
            kDeltas[var] = (float)(next_key->second - *var) / (float)(next_key->first - cursor);
        }
        // nextkeyf_ptrs[var] = keyframesIterators[var];
    }

    /**
        for (auto const &[var, kf] : keyframes)
        {
            auto beginK = kf.upper_bound(0);
            kDeltas[var].delta = (float)(beginK->second - *var) / (float)(beginK->first - cursor);
            kDeltas[var].targetFrame = beginK->first;
        }
    */
}

bool Timeline::end()
{
    return cursor >= length;
}