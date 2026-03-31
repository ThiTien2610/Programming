#include <cassert>
#include <stack>

template <typename T>
class Stack
{
public:
    void push(const T& x)
    {
        if (m_stack.empty()) {
            m_stack.push(x);
            m_min = x;
        } else if (x < m_min) {
            m_stack.push(2 * x - m_min);
            m_min = x;
        } else {
            m_stack.push(x);
        }
    }

    T top() const
    {
        assert(!m_stack.empty());

        if (m_stack.top() < m_min) {
            return m_min;
        }

        return m_stack.top();
    }

    void pop()
    {
        assert(!m_stack.empty());

        T t = m_stack.top();
        m_stack.pop();

        if (m_stack.empty()) {
            return;
        }

        if (t < m_min) {
            m_min = 2 * m_min - t;
        }
    }

    T min() const
    {
        assert(!m_stack.empty());
        return m_min;
    }

    bool empty() const
    {
        return m_stack.empty();
    }

private:
    std::stack<T> m_stack;
    T m_min = T();
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