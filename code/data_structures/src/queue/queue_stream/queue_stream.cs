using System;

namespace Cosmos_Data_Structures
{
    /// <summary>
    /// QueueStream provides an alternative Queue implementation to High speed 
    /// IO/Stream operations that works on multitheaded environment.
    /// Internally use 'circular array' in the implementation.
    /// </summary>
	[Serializable]
    public class QueueStream
    {
        byte[] _array = new byte[64]; // array in memory
        int _head;       // head index
        int _tail;       // tail index
        int _size;       // Number of elements.

        /// <summary>
        /// Buffer size (maximum limit) for single stream operation (Default is 64 KB)
        /// </summary>
        const int BufferBlock = 1024 * 64;

        /// <summary>
        /// Get total bytes in queue
        /// </summary>
        public int Count
        {
            get { return _size; }
        }

        /// <summary>
        /// Remove all bytes in queue
        /// </summary>
        public virtual void Clear()
        {
            _head = 0;
            _tail = 0;
            _size = 0;
        }

        /// <summary>
        /// Remove all bytes in queue and discard waste memory to GC.
        /// </summary>
        public void Clean()
        {
            _head = 0;
            _tail = 0;
            _size = 0;
            _array = new byte[64];
        }

        /// <summary>
        /// Adds a byte to the back of the queue.
        /// </summary>
        public virtual void Enqueue(byte obj)
        {
            if (_size == _array.Length)
            {
                SetCapacity(_size << 1);
            }

            _array[_tail] = obj;
            _tail = (_tail + 1) % _array.Length;
            _size++;
        }

        /// <summary>
        /// Removes and returns the byte at the front of the queue.
        /// </summary>
        /// <returns></returns>
        public byte Dequeue()
        {
            if (_size == 0)
                throw new InvalidOperationException("Invalid operation. Queue is empty!");

            byte removed = _array[_head];
            _head = (_head + 1) % _array.Length;
            _size--;
            return removed;
        }

        /// <summary>
        /// Returns the byte at the front of the queue.
        /// </summary>
        /// <returns></returns>
        public byte Front()
        {
            if (_size == 0)
                throw new InvalidOperationException("Invalid operation. Queue is empty!");

            return _array[_head];
        }

        /// <summary>
        /// Read and push stream bytes to queue. Can be multi-threaded.
        /// </summary>
        /// <param name="stream">The stream to push</param>
        /// <param name="maxSize">Maximum bytes size for this operation</param>
        /// <returns>Size of pushed bytes</returns>
        public int Enqueue(Stream stream, long maxSize = int.MaxValue)
        {
            if ((_size + BufferBlock) > _array.Length)
            {
                SetCapacity(Math.Max((_size + BufferBlock), _size << 1));
            }

            var count = Math.Min(Math.Min((int)maxSize, BufferBlock), _array.Length - _tail);

            lock (_array)
            {
                count = stream.Read(_array, _tail, count);
                _tail = (_tail + count) % _array.Length;
                _size += count;
            }

            return count;
        }

        /// <summary>
        /// Pop and write stream bytes to queue. Can be multi-threaded.
        /// </summary>
        /// <param name="stream">The stream to pop</param>
        /// <param name="maxSize">Maximum bytes size for this operation</param>
        /// <returns>Size of popped bytes</returns>
        public int Dequeue(Stream stream, long maxSize = int.MaxValue)
        {
            if (_size == 0)
                return 0; // It's okay to be empty

            int count = Math.Min(Math.Min(BufferBlock, _size), Math.Min((int)maxSize, _array.Length - _head));

            lock (_array)
            {
                stream.Write(_array, _head, count);
                _head = (_head + count) % _array.Length;
                _size -= count;
            }

            return count;
        }

        /// <summary>
        /// Set new capacity
        /// </summary>
        private void SetCapacity(int capacity)
        {
            lock (_array)
            {
                byte[] newarray = new byte[capacity];

                if (_size > 0)
                {
                    if (_head < _tail)
                    {
                        Array.Copy(_array, _head, newarray, 0, _size);
                    }
                    else
                    {
                        Array.Copy(_array, _head, newarray, 0, _array.Length - _head);
                        Array.Copy(_array, 0, newarray, _array.Length - _head, _tail);
                    }
                }

                _array = newarray;
                _head = 0;
                _tail = (_size == capacity) ? 0 : _size;
            }
        }
    }
}