#include <iostream>
#include <stdexcept>
class Array
{
private:
    int *data;
    size_t size_;     // 元素个数
    size_t capacity_; // 分配的个数

    void resize(size_t new_capacity)
    {
        int *new_data = new int[new_capacity];
        int *old_ptr = data;
        int *new_ptr = new_data;
        for (int i = 0; i < size_; i++)
        {
            *new_ptr++ = *old_ptr++;
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    Array() : size_(0), capacity_(16)
    {
        data = new int[capacity_];
    }
    ~Array()
    {
        delete[] data;
    }
    size_t size() const
    {
        return this->size_;
    }
    size_t capacity() const
    {
        return this->capacity_;
    }
    bool empty() const
    {
        return (this->size_ == 0);
    }
    int at(int index) const
    {
        if (index < 0 || index >= this->size_)
            throw std::out_of_range("Index out of bounds");
        return this->data[index];
    }
    void push(int x)
    {
        if (size_ == capacity_)
        {
            resize(2 * capacity_); // [12](@ref)
        }
        *(this->data + this->size_) = x;
        ++this->size_;
    }
    void insert(int index, int x)
    {
        if (index < 0 || index >= size_)
            throw std::out_of_range("Index out of bounds");

        // 空间检查
        if (size_ == capacity_)
            resize(2 * capacity_);

        for (int i = size_ - 1; i >= index; i--)
        {
            *(this->data + i + 1) = *(this->data + i);
        }
        *(this->data + index) = x;
        ++size_;
    }
    void prepend(int x)
    {
        return insert(0, x);
    }
    int pop()
    {
        if (this->empty())
            throw std::runtime_error("Pop from empty array");
        const int value = *(data + size_ - 1);
        size_--;
        if (size_ * 4 < capacity_ && capacity_ > 16)
        {
            resize(size_ / 2);
        }
        return value;
    }
    int remove_at(int index)
    {
        if (index < 0 || index >= size_)
            throw std::out_of_range("Index out of Bounds");
        int *ptr = data + index;
        const int value = *ptr;
        for (int i = index; i < size_ - 1; ++ptr)
            *ptr = *(ptr + 1);
        size_--;
        if (size_ * 4 < capacity_ && capacity_ > 16)
            resize(size_ / 2);
        return value;
    }
    void remove(int value)
    {
        int cnt = 0;
        for (int i = 0; i + cnt < size_; i++)
        {
            if(this->data[i] == value)
            {
                ++cnt;
            }
            if(i + cnt >= size_)
            {
                break;
            }
            this->data[i] = this->data[i + cnt];
        }
        size_ -= cnt;
        if(size_ * 4 < capacity_ && capacity_ > 16)
        {
            resize(capacity_ / 2);
        }
    }
};