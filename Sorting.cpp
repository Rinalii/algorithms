#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        int tmp = vec[i];
        int j = i - 1;
        for (j; j >= 0; --j) {
            if (vec[j] > tmp) {
                vec[j + 1] = vec[j];
            }
            else {
                break;
            }
        }
        vec[j + 1] = tmp;
    }
}

void SelectionSort(std::vector<int>& vec) {
    for (int i = 0; i + 1 < vec.size(); ++i) {
        int j_min = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j_min] > vec[j]) {
                j_min = j;
            }
        }
        if (i != j_min) {
            std::swap(vec[i], vec[j_min]);
        }
    }
}

void BubbleSort(std::vector<int>& vec) {
    bool not_sorted = true;
    while (not_sorted) {
        not_sorted = false;
        for (int i = 0; i + 1 < vec.size(); ++i) {
            if (vec[i] > vec[i + 1]) {
                std::swap(vec[i], vec[i + 1]);
                not_sorted = true;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec) {
    out << "vector: { ";
    if (!vec.empty()) {
        out << vec[0];
    }
    for (int i = 1; i < vec.size(); ++i) {
        out << ", " << vec[i];
    }
    out << " }" << std::endl;
    return out;
}

void MakeHeap(std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        int curr = i;
        while (curr) {
            int parent = (curr - 1) / 2;
            if (vec[curr] <= vec[parent]) {
                break;
            }

            std::swap(vec[curr], vec[parent]);
            curr = parent;
        }
    }
}

int RemoveTopItem(std::vector<int>& vec) {
    if (vec.empty()) return 0;
    int res = vec[0];
    vec[0] = vec.back();
    vec.pop_back();

    int index = 0;
    int num = vec.size();
    while (true) {
        
        int child1 = index * 2 + 1;
        int child2 = index * 2 + 2;

        if (child1 >= num) child1 = index;
        if (child2 >= num) child2 = index;

        if (vec[index] >= vec[child1] && vec[index] >= vec[child2]) {
            break;
        }

        int swap_index = (vec[child1] > vec[child2]) ? child1 : child2;

        std::swap(vec[swap_index], vec[index]);
        index = swap_index;
        
    }
    return res;
}

int RemoveTopItem(std::vector<int>& vec, int count) {
    if (count <= 0) return 0;
    int res = vec[0];
    vec[0] = vec[count - 1];

    int index = 0;
    while (true) {
        int child1 = index * 2 + 1;
        int child2 = index * 2 + 2;

        if (child1 >= count) child1 = index;
        if (child2 >= count) child2 = index;

        if (vec[index] >= vec[child1] && vec[index] >= vec[child2]) break;

        int swap_index = (vec[child1] > vec[child2]) ? child1 : child2;

        std::swap(vec[swap_index], vec[index]);
        index = swap_index;
    }
    return res;
}

void HeapSort(std::vector<int>& vec) {
    MakeHeap(vec);

    for (int i = vec.size() - 1; i > 0; --i) {
        vec[i] = RemoveTopItem(vec, i + 1);
    }
}

void QuickSort(std::vector<int>& vec, int start, int end) {
    if (start >= end) return;
    int middle = start;
    for (int i = start; i < end; ++i) {
        if (vec[middle] > vec[i]) {
            int tmp = vec[i];
            for (int j = i; j > middle; --j) {
                vec[j] = vec[j - 1];
            }
            vec[middle] = tmp;
            ++middle;
        }
    }
    QuickSort(vec, start, middle);
    QuickSort(vec, middle + 1, end);
}

int main()
{
    std::cout << "Hello World123!\n";

    {
        std::vector<int> vec = { 5, 4, 3, 2, 1, 0 };
        std::cout << vec;
        BubbleSort(vec);
        std::cout << vec;
    }

    {
        std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15 };
        std::cout << vec;
        MakeHeap(vec);
        std::cout << vec;
    }

    {
        std::vector<int> vec = { 15, 11, 10, 7, 5, 9, 2, 6, 4, 3, 1, 8, 12 };
        std::cout << vec;
        MakeHeap(vec);
        std::cout << vec;
    }

    {
        std::vector<int> vec = { 15, 11, 10, 7, 5, 9, 2, 6, 4, 3, 1, 8, 12 };
        std::cout << vec;
        HeapSort(vec);
        std::cout << vec;
    }

    {
        std::vector<int> vec = { 15, 11, 10, 7, 5, 9, 2, 6, 4, 3, 1, 8, 12 };
        std::cout << vec;
        QuickSort(vec, 0, vec.size());
        std::cout << vec;
    }

}
