#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>

template <typename T>
class IndexPriorityQueue{
public:
    IndexPriorityQueue(bool isMax = true);

    bool isMax();

    int getSize();

    bool empty();

    void insert(T content, double value);

    T peek();

    T pop();

    void update(T content, double newVal);

private:
    bool m_isMax {true};
    int m_size {0};
    std::vector<double> m_values {};
    std::vector<T> m_content {};
    std::unordered_map<T, int> m_content2index {};
    std::vector<int> m_positionMap {};
    std::vector<int> m_inverseMap {};

    std::vector<int>& getPositionMap(){
        return m_positionMap;
    }
    std::vector<int>& getInverseMap(){
        return m_inverseMap;
    }

    void swap(int p1, int p2);

    void swim(int position);

    void sink(int position);

};

#include "indexPriorityQueue.tpp"