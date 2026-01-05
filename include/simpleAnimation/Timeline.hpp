namespace SimpleAnimation
{
    class Timeline
    {
    private:
        /* data */
        int cursor;
        int length;
    public:
        Timeline(int length) : cursor(0), length(length) {};
        ~Timeline() = default;
        void addKeyframe(int &var, int value, int frame);
        void step();
        bool end();
    };
} // namespace SimpleAnimation


