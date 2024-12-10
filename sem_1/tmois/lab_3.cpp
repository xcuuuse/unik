#include <bits/stdc++.h>

using namespace std;

vector<int> qnike_pro(vector<int> a)
{
    vector <int> UNIC;
    for (int i : a) {
        bool seen = false;
        for (int j : UNIC) {
            if (i == j) {
                seen = true;
                break;
            }
        }
        if (!seen) {
            UNIC.push_back(i);
        }
    }
    return UNIC;
}
// объединение
void union_sets(const vector<int>& A, const vector<int>& B, vector<int>& res)
{
    res = A; // Начинаем с всех элементов A
    for (auto i : B) {
        if (find(A.begin(), A.end(), i) == A.end())
        {
            res.push_back(i);
        }
    }
}

// пересечение
void inter_sets(const vector<int>& A, const vector<int>& B, vector<int>& res)
{
    for (auto i : A)
    {
        if (find(B.begin(), B.end(), i) != B.end())
        {
            res.push_back(i);
        }
    }
}

// разность
void diff_sets(const vector<int>& A, const vector<int>& B, vector<int>& res)
{
    for (auto i : A) {
        if (find(B.begin(), B.end(), i) == B.end())
        {
            res.push_back(i); // Добавляем элементы, которых нет в B
        }
    }
}

// разность пар
void diff_pairs(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& res)
{
    for (auto i : A)
    {
        if (find(B.begin(), B.end(), i) == B.end())
        {
            res.push_back(i); // Добавляем пары, которых нет в B
        }
    }
}

// объединение пар
void union_pairs(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& res)
{
    res = A; // Начинаем с всех пар из A
    for (auto i : B)
    {
        if (find(A.begin(), A.end(), i) == A.end())
        {
            res.push_back(i); // Добавляем уникальные пары из B
        }
    }
}

// пересечение пар
void intersectionPairs(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& res)
{
    for (auto i : A)
    {
        if (find(B.begin(), B.end(), i) != B.end())
        {
            res.push_back(i); // Добавляем совпадающие пары
        }
    }
}

//вывод множества
template <typename T>
void outputSet(const vector<T>& vec)
{
    for (auto v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}

// выполнение объединения
void out_union(const vector<int>& A, const vector<int>& B)
{
    vector<int> res;
    union_sets(A, B, res);
    vector<int> res_q= qnike_pro(res);
    outputSet(res_q);
}

// выполнение пересечения
void out_inter(const vector<int>& A, const vector<int>& B)
{
    vector<int> result;
    inter_sets(A, B, result);
    vector<int> result_q = qnike_pro(result);
    outputSet(result_q);
}

// выполнение разности
void performDifference(const vector<vector<int>>& A, const vector<vector<int>>& B)
{
    vector<vector<int>> res;
    diff_pairs(A, B, res);
    for (auto i : res)
    {
        cout << "<" << i[0] << "," << i[1] << "> ";
    }
    cout << "\n";
}

//график композиции
vector<vector<int>> computeComposition(const vector<vector<int>>& F, const vector<vector<int>>& G) {
    vector<vector<int>> GK1;

    for (auto g : G) {
        for (auto f : F) {
            if (g[1] == f[0]) {
                bool flag = true; // Сброс флага

                // Проверяем на дубликаты
                for (auto pair : GK1) {
                    if (g[0] == pair[0] && f[1] == pair[1]) {
                        flag = false; // Найден дубликат
                        break;
                    }
                }

                if (flag) {
                    GK1.push_back({g[0], f[1]});
                }
            }
        }
    }

    return GK1;
}



int vvod() {
    int value;
    while (true) {
        cin >> value;
        if (value > 0 && value < 101) {
            return value;
        }
        else {
            cout << "введите число от 1 до 100 " << endl;
        }
    }
}

int main()
{
    system(" chcp 65001");

   // cin.tie(nullptr);
    vector<int> X, Y, U, V;
    vector<vector<int>> G, F;

    cout << "Введите мощность множества X: ";
    int size_x;
    while (true) {
        cin >> size_x;

        if (size_x >= 0) {
            X.resize(size_x);
            break;
        }
        else {
            cout << "Введите мощность не меньше 0" << endl;
        }
    }

    cout << "Вводите элементы множества X:\n";
    for (int i = 0; i < size_x; i++)
    {
        X[i] = vvod();
    }

    cout << "Введите мощность множества Y: ";
    int size_y;
    while (true) {
        cin >> size_y;

        if (size_y >= 0) {
            Y.resize(size_y);
            break;
        }
        else {
            cout << "Введите мощность не меньше 0" << endl;
        }
    }


    cout << "Вводите элементы множества Y:\n";
    for (int i = 0; i < size_y; i++)
    {
        Y[i] = vvod();
    }

    cout << "Введите мощность множества G: ";
    int size_g;
    while (true) {
        cin >> size_g;

        if (size_g >= 0) {
            G.resize(size_g, vector<int>(2));
            break;
        }
        else {
            cout << "Введите мощность не меньше 0" << endl;
        }
    }

    cout << "Вводите элементы множества G (пары):\n";
    for (int i = 0; i < size_g; i++)
    {
        G[i][0] = vvod();
        G[i][1] = vvod();
    }

    cout << "Введите мощность множества U: ";
    int size_u;
    while (true) {

        cin >> size_u;

        if (size_u >= 0) {
            U.resize(size_u);
            break;
        }
        else {
            cout << "Введите мощность не меньше 0" << endl;
        }
    }
    cout << "Вводите элементы множества:\n";
    for (int i = 0; i < size_u; i++)
    {
        U[i] = vvod();
    }

    cout << "Введите мощность множества V: ";
    int size_v;
    while (true) {

        cin >> size_v;

        if (size_v >= 0) {
            V.resize(size_v);
            break;
        }
        else {
            cout << "Введите мощность не меньше 0" << endl;
        }
    }


    cout << "Вводите элементы множества:\n";
    for (int i = 0; i < size_v; i++)
    {
        V[i] = vvod();
    }

    cout << "Введите мощность множества F: ";
    int size_f;
    while (true) {
        cin >> size_f;

        if (size_f >= 0) {

            F.resize(size_f, vector<int>(2));
            break;
        }
        else {
            cout << "Введите мощность не меньше 0" << endl;
        }
    }

    cout << "Вводите элементы множества F (пары):\n";
    for (int i = 0; i < size_f; i++)
    {
        F[i][0] = vvod();
        F[i][1] = vvod();
    }

    // выполнение операций над множествами
    cout << "\n-------ОБЪЕДИНЕНИЕ Г1 and Г2-------\n";
    cout << "\n       ОБЪЕДИНЕНИЕ X and U\n";
    out_union(X, U);

    cout << "\n       ОБЪЕДИНЕНИЕ Y and V\n";
    out_union(Y, V);

    cout << "\n       ОБЪЕДИНЕНИЕ G and F\n";
    vector<vector<int>> UGF;
    union_pairs(G, F, UGF);
    for (auto i : UGF)
    {
        cout << "<" << i[0] << "," << i[1] << "> ";
    }
    cout << endl;

    // выполнение операций пересечения
    cout << "\n-------ПЕРЕСЕЧЕНИЕ Г1 and Г2-------\n";
    cout << "\n        ПЕРЕСЕЧЕНИЕ X and U\n";
    out_inter(X, U);

    cout << "\n        ПЕРЕСЕЧЕНИЕ Y and V\n";
    out_inter(Y, V);

    cout << "\n       ПЕРЕСЕЧЕНИЕ G and F\n";
    vector<vector<int>> IGF;
    intersectionPairs(G, F, IGF);
    for (auto i : IGF)
    {
        cout << "<" << i[0] << "," << i[1] << "> ";
    }
    cout << endl;

    // выполнение операций разности
    cout << "\n-------РАЗНОСТЬ Г1 and Г2-------\n";
    outputSet(X); // DOMAIN OF SENDING
    cout << "       ОБЛАСТЬ ПРИБЫТИЯ\n";
    outputSet(Y); // DOMAIN OF ARRIVAL

    cout << "\n       РАЗНОСТЬ G\\F\n";
    performDifference(G, F);

    cout << "\n-------РАЗНОСТЬ Г2 and Г1-------\n";
    outputSet(Y); // DOMAIN OF SENDING
    cout << "       ОБЛАСТЬ ПРИБЫТИЯL\n";
    outputSet(X); // DOMAIN OF ARRIVAL

    cout << "\n       РАЗНОСТЬ F\\G\n";
    performDifference(F, G);



    // КОМПОЗИЦИЯ ЕБАНАЯ
    cout << "\n\n-------КОМПОЗИЦИЯ Г1*Г2-------\n       ОБЛАСТЬ ОТПРАВЛЕНИЯ\n";
    for (int x : X)
    {
        cout << x << " ";
    }

    // Область прибытия
    cout << "\n       ОБЛАСТЬ ПРИБЫТИЯ\n";
    for (int v : V) {
        cout << v << " ";
    }

    // График композиции
    cout << "\n       ГРАФИК КОМПОЗИЦИИ\n";
    vector<vector<int>> GK1 = computeComposition(F, G);

    // Выводим все пары композиции
    for (const auto& pair : GK1)
    {
        cout << "<" << pair[0] << "," << pair[1] << "> ";
    }
    cout << "\n";
    cout << "\n\n-------КОМПОЗИЦИЯ Г2*Г1-------\n       ОБЛАСТЬ ОТПРАВЛЕНИЯ\n";
    for (int u : U)
    {
        cout << u << " ";
    }
    // Область прибытия
    cout << "\n       ОБЛАСТЬ ПРИБЫТИЯ\n";
    for (int y : Y)
    {
        cout << y << " ";
    }
    // График композиции
    cout << "\n       ГРАФИК КОМПОЗИЦИИ\n";
    vector<vector<int>> GK2 = computeComposition(G, F);

    // Выводим все пары композиции
    for (auto pair : GK2)
    {
        cout << "<" << pair[0] << "," << pair[1] << "> ";
    }
    cout << "\n";


    //int n; cin >> nkpas oh s v dfids s dvdvd vd igvh vh n gh h ghhdb hg  dh  nydb bdhb b 

    return 0;
}
