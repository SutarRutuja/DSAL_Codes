//OBST
/*Given sequence k = k1 <k2 < ... <kn of n sorted keys, with a search
probability pi for each key ki. Build the Binary search tree that has the
least search cost given the access probability for each key.*/



// Enter number of keys: 3  
// Enter keys: 10 20 30  
// Enter successful probabilities: 3 3 1  
// Enter unsuccessful probabilities: 2 3 1 1  




#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class OBST {
    int* keys;
    int* p;
    int* q;
    int n;


    vector<vector<int>> w;
    vector<vector<int>> c;
    vector<vector<int>> root;


public:
    OBST(int n) : n(n) {
        keys = new int[n];
        p = new int[n];
        q = new int[n + 1];


        w = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        c = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        root = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));


        // Taking input
        cout << "Enter keys: ";
        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }


        cout << "Enter successful probabilities: ";
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }


        cout << "Enter unsuccessful probabilities: ";
        for (int i = 0; i <= n; i++) {
            cin >> q[i];
        }


        calculate();
    }


    void calculate() {
        for (int i = 0; i <= n; i++) {
            w[i][i] = q[i];
            c[i][i] = 0;
            root[i][i] = 0;
        }


        for (int L = 1; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L;
                c[i][j] = INT_MAX;
                w[i][j] = w[i][j - 1] + p[j - 1] + q[j];


                for (int k = i; k < j; k++) {
                    int t = c[i][k] + c[k + 1][j] + w[i][j];
                    if (t < c[i][j]) {
                        c[i][j] = t;
                        root[i][j] = k;
                    }
                }
            }
        }
    }


    void print_root_table() {
        cout << "\nRoot Table:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << root[i][j] << " ";
            }
            cout << endl;
        }
    }


    void print_cost_table() {
        cout << "\nCost Table:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }


    void print_tree(int i, int j, int level, int parent = -1) {
        if (i >= j)
            return;


        int k = root[i][j];
        for (int l = 0; l < level; l++) cout << "  ";


        if (parent == -1)
            cout << "Root: " << keys[k] << endl;
        else if (k < parent)
            cout << "Left child of " << keys[parent] << ": " << keys[k] << endl;
        else
            cout << "Right child of " << keys[parent] << ": " << keys[k] << endl;


        print_tree(i, k, level + 1, k);
        print_tree(k + 1, j, level + 1, k);
    }


    void mincost() {
        cout << "\nMinimum expected search cost: " << c[0][n] << endl;
    }


    void getroot() {
        cout << "Root of the optimal BST: " << keys[root[0][n]] << endl;
    }


    ~OBST() {
        delete[] keys;
        delete[] p;
        delete[] q;
    }
};


int main() {
    int n;
    cout << "Enter number of keys: ";
    cin >> n;


    OBST o(n);
    o.print_root_table();
    o.print_cost_table();
    o.mincost();
    o.getroot();
    cout << "\nOptimal BST Structure:\n";
    o.print_tree(0, n, 0);


    return 0;
}



