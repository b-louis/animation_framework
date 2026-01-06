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
        std::map<int*, Keyframes> keyframes;
        std::map<int*, deltaStruct> kDeltas;
    public:
        Timeline(int length) : cursor(0), length(length) {};
        ~Timeline() = default;
        void addKeyframe(int *var, int value, int frame);
        const int getCursor() const
        {
            return cursor-1;
        };
        void init();
        void step();
        bool end();
    };
} // namespace simpleAnimation


