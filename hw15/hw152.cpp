#include <iostream>
#include <string>
#include <random>

char random_letter(std::default_random_engine& engine)
{
    static std::uniform_int_distribution<int> letter_dist(0, 25);
    return static_cast<char>('a' + letter_dist(engine));
}

std::string random_string(std::size_t length, std::default_random_engine& engine)
{
    std::string s;
    s.reserve(length);

    for (std::size_t i = 0; i < length; ++i)
    {
        s += random_letter(engine);
    }

    return s;
}

int metric(const std::string& s, const std::string& target)
{
    int diff = 0;

    for (std::size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] != target[i])
        {
            ++diff;
        }
    }

    return diff;
}

std::string mutate(const std::string& parent, std::default_random_engine& engine)
{
    static std::uniform_real_distribution<double> prob_dist(0.0, 1.0);

    std::string child = parent;

    for (std::size_t i = 0; i < child.size(); ++i)
    {
        if (prob_dist(engine) < 0.05)
        {
            char new_char;
            do
            {
                new_char = random_letter(engine);
            }
            while (new_char == child[i]);

            child[i] = new_char;
        }
    }

    return child;
}

int main()
{
    const std::string target = "methinksitislikeaweasel";
    const int copies = 100;

    std::random_device rd;
    std::default_random_engine engine(rd());

    std::string current = random_string(target.size(), engine);
    int generation = 0;

    while (true)
    {
        int current_metric = metric(current, target);

        std::cout << "Generation " << generation
                  << ": " << current
                  << " (metric = " << current_metric << ")\n";

        if (current_metric == 0)
        {
            break;
        }

        std::string best_child;
        int best_metric = static_cast<int>(target.size()) + 1;

        for (int i = 0; i < copies; ++i)
        {
            std::string child = mutate(current, engine);
            int child_metric = metric(child, target);

            std::cout << "  Child " << i + 1
                      << ": " << child
                      << " (metric = " << child_metric << ")\n";

            if (child_metric < best_metric)
            {
                best_metric = child_metric;
                best_child = child;
            }

            if (child_metric == 0)
            {
                std::cout << "Found target: " << child << '\n';
                return 0;
            }
        }

        current = best_child;
        ++generation;
    }

    return 0;
}