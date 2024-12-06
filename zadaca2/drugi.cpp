#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <type_traits>

using namespace std;

// Corrected template definition with remove_reference_t
template<typename mat1, typename mat2, typename Func>
auto GeneraliziraniKroneckerovProizvod(mat1 m1, mat2 m2, Func func) -> vector<vector<typename std::remove_reference_t<decltype(func(m1[0][0], m2[0][0]))>>>
{
    using tiprez = typename std::remove_reference_t<decltype(func(m1[0][0], m2[0][0]))>;
    vector<vector<tiprez>> rez;
    
    int cols1 = end(m1[0]) - begin(m1[0]);
    int cols2 = end(m2[0]) - begin(m2[0]);
    int rows1 = end(m1) - begin(m1);
    int rows2 = end(m2) - begin(m2);
    
    // Resize the result matrix to match the Kronecker product dimensions
    rez.resize(rows1 * rows2);
    for (int i = 0; i < rows1 * rows2; i++) {
        rez.at(i).resize(cols1 * cols2);
    }

    // Compute the generalized Kronecker product
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            for (int k = 0; k < rows2; k++) {
                for (int l = 0; l < cols2; l++) {
                    // Map the element of m1[i][j] and m2[k][l] to the appropriate position in the result matrix
                    rez.at(i * rows2 + k).at(j * cols2 + l) = func(m1[i][j], m2[k][l]);
                }
            }
        }
    }

    return rez;
}

int main() {
    int a, b, element;
    cout << "Unesite dimenzije prve matrice" << endl;
    cin >> a >> b;
    vector<deque<int>> m1(a, deque<int>(b));
    cout << "Unesite elemente prve matrice" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> element;
            m1[i][j] = element;
        }
    }

    cout << "Unesite dimenzije druge matrice" << endl;
    cin >> a >> b;
    deque<vector<int>> m2(a, vector<int>(b));
    cout << "Unesite elemente druge matrice" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> element;
            m2[i][j] = element;
        }
    }

    // Define a function pointer that matches the expected function signature
    auto multiply = [](int x, int y) { return x * y; };

    // No need to explicitly cast the lambda function to a function pointer type
    auto result = GeneraliziraniKroneckerovProizvod(m1, m2, multiply);

    cout << "Njihov gen. Kroneckerov proizvod glasi: " << endl;
    for (const auto &row : result) {
        for (const auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
