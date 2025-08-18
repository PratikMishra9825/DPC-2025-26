#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A = {1, 3, 5, 7};
    vector<int> B = {2, 4, 6, 8};
    int m = A.size();
    int n = B.size();

    int i = 0, j = 0;
    while (i < m) {
        if (A[i] > B[0]) {
            swap(A[i], B[0]);
            int first = B[0];
            int k = 1;
            while (k < n && B[k] < first) {
                B[k - 1] = B[k];
                k++;
            }
            B[k - 1] = first;
        }
        i++;
    }

    for(int el : A) {
        cout << el << " ";
    }
    cout << endl;
    for(int num : B) {
        cout << num << " ";
    }
    return 0;
}
