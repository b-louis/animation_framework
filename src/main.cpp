#include <simpleAnimation/Timeline.hpp>

using namespace SimpleAnimation;
int main(int argc, char const *argv[])
{
    /* code */
    int value = 0;
    Timeline timeline {30};

    timeline.addKeyframe(value,0,0);

    timeline.addKeyframe(value,10,20);

    while (!timeline.end())
    {
        timeline.step();
    }
    
    return 0;
}
