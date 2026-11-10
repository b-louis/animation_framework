#include <simpleAnimation/Timeline.hpp>
#include <iostream>
using namespace simpleAnimation;
int main(int argc, char const *argv[])
{
    /* code */
    int value = 0;
    Timeline timeline{30};

    timeline.addKeyframe(&value, 0, 0);

    timeline.addKeyframe(&value, 20, 20);

    timeline.init();
    // timeline.init();
    while (!timeline.end())
    {
        timeline.stepForward();
        std::cout << "Frame: " << timeline.getCursor() << " Value: " << value << std::endl;
    }
    std::cout << "Animation is done." << std::endl;

    return 0;
}
