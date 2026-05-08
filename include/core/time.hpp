#ifndef TIME_HPP
#define TIME_HPP

namespace FuraiEngine {
    class Time {
    private:
        static float s_DeltaTime;
        static float s_LastFrameTime;

    public:
        static void Update();

        static float GetDeltaTime();
    };
}

#endif // TIME_HPP