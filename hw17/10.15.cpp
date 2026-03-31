#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>

template <typename T>
class Stack
{
public:
    void push(const T& x)
    {
        if (m_stack.empty()) {
            m_stack.emplace(x, x);
        } else {
            m_stack.emplace(x, std::min(x, m_stack.top().second));
        }
    }

    T top() const
    {
        assert(!m_stack.empty());
        return m_stack.top().first;
    }

    void pop()
    {
        assert(!m_stack.empty());
        m_stack.pop();
    }

    T min() const
    {
        assert(!m_stack.empty());
        return m_stack.top().second;
    }

    bool empty() const
    {
        return m_stack.empty();
    }

private:
    std::stack<std::pair<T, T>> m_stack;
};

int main()
{
    Stack<int> stack;

    stack.push(3);
    assert(stack.top() == 3 && stack.min() == 3);

    stack.push(1);
    assert(stack.top() == 1 && stack.min() == 1);

    stack.push(2);
    assert(stack.top() == 2 && stack.min() == 1);

    assert(stack.top() == 2 && stack.min() == 1);

    stack.pop();
    assert(stack.top() == 1 && stack.min() == 1);

    stack.pop();
    assert(stack.top() == 3 && stack.min() == 3);

    stack.pop();
    assert(stack.empty());
}