#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {
    public:
        Vector(int cap = 1);
        Vector(const Vector<T>& vec);
        ~Vector();
        Vector<T>& operator=(const Vector<T>& vec);
        const T& operator[](int index) const;
        T& operator[](int index);
        void push_back(const T& data);
        int Size() const;
        void clear();
    private:
        T* array;
        int capacity;
        int size;

        void grow();
};

template <class T>
Vector<T>::Vector(int cap) : array(new T[cap]), capacity(cap), size(0)
{
}

template <class T>
Vector<T>::Vector(const Vector<T> &vec) : array(new T[vec.capacity]), capacity(vec.capacity), size(vec.size)
{
    for(int i = 0; i < size; i++){
        array[i] = vec.array[i];
    }
}

template <class T>
Vector<T>::~Vector()
{
    delete[] array;
    capacity = 0;
    size = 0;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
    if(this != &vec){
        delete[] array;
        array = new T[vec.capacity];
        capacity = vec.capacity;
        size = vec.size;

        for(int i = 0; i < size; i++){
            array[i] = vec.array[i];
        }
    }
}

template <class T>
const T& Vector<T>::operator[](int index) const{
    return array[index];
}

template <class T>
T& Vector<T>::operator[](int index)
{
    return array[index];
}

template <class T>
void Vector<T>::push_back(const T &data)
{
    if(size == capacity){
        grow();
    }
    array[size] = data;
    size++;
}

template <class T>
int Vector<T>::Size() const
{
    return size;
}

template <class T>
void Vector<T>::clear()
{
    delete[] array;
    array = new T[1];
    capacity = 1;
    size = 0;
}

template <class T>
void Vector<T>::grow()
{
    int newCap = capacity * 2;
    T* newArray = new T[newCap];
    for(int i = 0; i < size; i++){
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
    capacity = newCap;
}

#endif
