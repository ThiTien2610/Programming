#include<iostream>
#include <iterator>
#include <memory>

///////////////////////////////////////////////////////////////////////////////////

template < typename T > class List
{
private :

	struct Node
	{ 
		T x = T();

		std::shared_ptr < Node > next{};
        std::weak_ptr <Node> prev{};

        Node(const T& value) : x(value) {}
    };
	
public :

	class Iterator
	{
	public :

		using iterator_category = std::bidirectional_iterator_tag;
        using value_type =T;
        using pointer =T*;
        using reference =T&;

	//  -------------------------------------------------------------------

		Iterator(std::shared_ptr < Node > node = nullptr, const List* owner = nullptr) : m_node(node), m_owner(owner) {}

	//  -------------------------------------------------------------------

        reference operator*() const
        {
            return m_node->x;
        }

        pointer operator->() const
        {
            return &m_node->x;
        }


		Iterator operator++(int)
        {
            Iterator x = *this;

            if (m_node)
            {
                m_node = m_node->next;
            }

            return x;
        }

        Iterator& operator++()
        {
            if (m_node)
            {
                m_node = m_node->next;
            }

            return *this;
        }

        Iterator& operator--()
        {
            if (m_node)
            {
                m_node = m_node->prev.lock();
            }
            else if (m_owner)
            {
                m_node = m_owner->m_tail;
            }
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;

            if (m_node)
            {
                m_node = m_node->prev.lock();
            }
            else if (m_owner)
            {
                m_node = m_owner->m_tail;
            }

            return temp;
        }

		
	//  -------------------------------------------------------------------

		friend auto operator==(Iterator const & lhs, Iterator const & rhs)
		{
			return lhs.m_node == rhs.m_node;
		}
        friend auto operator!=(Iterator const & lhs, Iterator const & rhs)
		{
			return !(lhs == rhs);
		}

	private :

		std::shared_ptr < Node > m_node{};
        const List* m_owner{};

	};
private:
    std::shared_ptr<Node> m_head{};
    std::shared_ptr<Node> m_tail{};
//  -----------------------------------------------------------------------
public:
	Iterator begin() const { return Iterator(m_head, this); }

	Iterator end  () const { return Iterator( nullptr, this); }

//  -----------------------------------------------------------------------


	void push_back(const T& value)
    {
        auto node = std::make_shared<Node>(value);

        if (!m_head)
        {
            m_head = node;
            m_tail = node;
        }
        else
        {
            node->prev = m_tail;
            m_tail->next = node;
            m_tail = node;
        }
	}
};

///////////////////////////////////////////////////////////////////////////////////

int main()
{
    List<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::cout << "Forward: ";
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    std::cout << "Backward: ";
    auto it = list.end();
    while (it != list.begin())
    {
        --it;
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////