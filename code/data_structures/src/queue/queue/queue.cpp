/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cassert>

template <typename T>
class Queue {

private:
    int m_f;
    int m_r;
    std::size_t m_size;
    T * m_data;

public:
/*! \brief Constructs queue object with size.
 *  \param sz Size of the queue.
 */
    Queue( std::size_t sz = 10) : m_f( -1)
        , m_r( -1)
        , m_size( sz)
        , m_data( new T[sz])
    {
        /* empty */
    }


/*! \brief Destructor
 */
    ~Queue()
    {
        delete [] m_data;
    }

/*! \brief Insert element at the end of the queue.
 *  \param value Value to be inserted.
 */
    void enqueue( const T& value )
    {
        int prox_r = (m_r + 1) % m_size;

        if (prox_r == 0 or prox_r != m_f)
        {
            (m_f == -1) ? m_f = 0 : m_f = m_f;
            m_data[prox_r] = value;
            m_r = prox_r;

        }
        else
            assert(false);
    }

/*! \brief Remove element at the end of the queue.
 */
    void dequeue()
    {
        if (m_f != -1)
        {
            // If there is only 1 element, f = r = -1
            if (m_f == m_r)
                m_f = m_r = -1;
            // If size > 1, f goes forward
            else
                m_f = (m_f + 1) % m_size;
        }
        else
            assert(false);
    }

/*! \brief Get element at the beginning of the queue.
 *  \return First element at the queue.
 */
    T front()
    {
        if (m_f != -1)
            return m_data[m_f];

        assert(false);
    }

/*! \brief Check if queue is empty.
 *  \return True if queue is empty, false otherwise.
 */
    bool isEmpty()
    {
        return m_f == -1;
    }

/*! \brief Clear content.
 */
    void makeEmpty()
    {
        reserve(m_size);
        m_f = m_r = -1;
        m_size = 0;
    }

/*! \brief Get size of the queue.
 * \return Size of the queue.
 */
    T size() const
    {
        if (m_r == m_f)
            return 1;
        else if (m_r > m_f)
            return m_r - m_f + 1;
        else
            return m_f - m_r + 1;
    }

/*! \brief Increase the storage capacity of the array to a value
 *         that’s is greater or equal to 'new_cap'.
 *  \param new_cap New capacity.
 */
    void reserve( std::size_t new_cap )
    {
        if (new_cap >= m_size)
        {
            //<! Allocates new storage area
            T *temp = new T[ new_cap ];

            //<! Copy content to the new list
            for (auto i(0u); i < m_size; i++)
                temp[i] = m_data[i];

            delete [] m_data;      //<! Deallocate old storage area

            m_data = temp;        //<! Pointer pointing to the new adress
            m_size = new_cap;     //<! Updates size
        }
    }
};

int main()
{

    Queue<int> queue(3);

    queue.enqueue(5);
    assert(queue.front() == 5);
    assert(queue.size() == 1);

    queue.enqueue(4);
    queue.enqueue(3);

    //remove 2 elements
    queue.dequeue();
    queue.dequeue();
    assert( queue.size() == 1);

    //Insert one more
    queue.enqueue(2);
    assert( queue.size() == 3);

    return 0;
}
