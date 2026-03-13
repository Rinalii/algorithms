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

int main()
{
    std::cout << "Hello World123!\n";


    std::vector<int> vec = { 5, 4, 3, 2, 1, 0 };
    std::cout << vec;
    BubbleSort(vec);
    std::cout << vec;
}
