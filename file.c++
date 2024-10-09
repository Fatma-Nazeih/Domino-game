#include <bits/stdc++.h>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

class Domino {
private:
    vector<dominoT> domino;
    vector<dominoT> chain;  

public:
    Domino(int n) {
        domino.resize(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;  
            domino[i] = {a, b};
        }
    }

    bool Forms(int lastRight, vector<bool> &used, int count) {
        if (count == domino.size()) return true;

        for (int i = 0; i < domino.size(); i++) {
            if (!used[i]) {
                if (domino[i].leftDots == lastRight) {
                    used[i] = true;
                    chain.push_back(domino[i]);  
                    if (Forms(domino[i].rightDots, used, count + 1)) {
                        return true;
                    }
                    chain.pop_back();  
                    used[i] = false;
                }
            }
        }
        return false;
    }

    bool IsChain() {
        for (int i = 0; i < domino.size(); i++) {
            vector<bool> used(domino.size(), false);
            used[i] = true;
            chain.clear();  
            chain.push_back(domino[i]);  
            if (Forms(domino[i].rightDots, used, 1)) {
                return true;
            }
        }
        return false;
    }

    void PrintDominoChain() {
        for (int i = 0; i < chain.size(); i++) {
            if (i > 0) cout << " - ";
            cout << chain[i].leftDots << "|" << chain[i].rightDots;
        }
        cout << endl;
    }
    
};

int main() {
    int n;
    cin >> n; 
    Domino d(n);

    if (d.IsChain()) {
        d.PrintDominoChain();
    } else {
        cout << "It is not possible to form a domino chain!" << endl;
    }

    return 0;
}
