#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class Timer
{
public:
    using clock_t = std::chrono::steady_clock;
    using duration_t = std::chrono::duration<double>;

    Timer(const std::string& scope) : m_scope(scope) {}

    void start()
    {
        if (!m_is_running)
        {
            m_begin = clock_t::now();
            m_is_running = true;
        }
    }

    void stop()
    {
        if (m_is_running)
        {
            duration_t interval = clock_t::now() - m_begin;
            m_intervals.push_back(interval);
            m_is_running = false;
        }
    }

    double average() const
    {
        if (m_intervals.empty())
        {
            return 0.0;
        }

        double sum = 0.0;
        for (const auto& interval : m_intervals)
        {
            sum += interval.count();
        }

        return sum / m_intervals.size();
    }

private:
    std::string m_scope;
    clock_t::time_point m_begin;
    bool m_is_running = false;
    std::vector<duration_t> m_intervals;
};

int main()
{
    Timer timer("main");

    for (int i = 0; i < 3; ++i)
    {
        timer.start();

        for (volatile int j = 0; j < 1000000; ++j)
        {
        }

        timer.stop();
    }

    std::cout << "average = " << timer.average() << " s\n";

    return 0;
}