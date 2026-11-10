#include <simpleAnimation/Keyframes.hpp>
namespace simpleAnimation
{
    class Timeline
    {
        struct deltaStruct
        {
            int targetFrame;
            float delta;
        };

    private:
        /* data */
        int cursor;
        int length;
        std::map<int *, KeyframeMap> keyframes;
        std::map<int *, float> kDeltas;
        std::map<int *, KeyframeMap::iterator> keyframesIterators;
        std::map<int *, std::pair<int, int> *> prevkeyf_ptrs;
        std::map<int *, std::pair<int, int> *> nextkeyf_ptrs;

    public:
        Timeline(int length) : cursor(0), length(length) {};
        ~Timeline() = default;
        void addKeyframe(int *var, int value, int frame);
        const int getCursor() const
        {
            return cursor - 1;
        };
        void init();
        void stepForward();
        void stepBackward();
        void pause();
        bool end();
    };
} // namespace simpleAnimation
