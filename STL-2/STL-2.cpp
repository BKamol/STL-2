#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
struct triple
{
    T x, y, z;
};

template <class Val>
inline Val clamp(Val value, Val min_bound, Val max_bound)
{
    return value < min_bound ? min_bound
        : max_bound < value ? max_bound
        : value;
}

template <class Val>
vector<Val> clamped(const vector<Val>& values, Val min_bound, Val max_bound)
{
    vector<Val> clv(values.size());
    for (size_t i = 0, sz = values.size(); i < sz; ++i)
        clv[i] = clamp(values[i], min_bound, max_bound);
    return clv;
}

template <class T>
void print_vector(vector<T> a_vector)
{
    for (int i = 0; i < a_vector.size(); i++)
        cout << a_vector[i] << ' ';
    cout << endl;
}

template <class T>
vector<T> slopes(vector<T>& a)
{
    vector<T> result(a.size());

    T maxi, mini;
    for (int i = 0; i < a.size(); i++)
    {
        maxi = a[0];
        mini = a[0];
        for (int j = 1; j <= i; j++)
        {
            if (a[j] > maxi) maxi = a[j];
            if (a[j] < mini) mini = a[j];
        }
        result[i] = maxi - mini;
    }
    return result;
}

template <class T>
vector<T> means(vector<T>& a)
{
    vector<T> b(a.size());
    T s = 0;

    for (int i = 0; i < a.size(); i++)
    {
        s += a[i];
        b[i] = s / (i+1);
    }

    return b;
}

template <class T>
vector<T> geometric_means(vector<T>& a)
{
    vector<T> b(a.size());
    T s = 1;

    for (int i = 0; i < a.size(); i++)
    {
        s *= a[i];
        b[i] = pow(s, 1.0/(i+1));
    }

    return b;
}

template <class T>
T length(pair<T, T>& a2, pair<T, T>& a1)
{
    return sqrt((a2.first - a1.first) * (a2.first - a1.first) + (a2.second - a1.second) * (a2.second - a1.second));
}
template <class T>
vector<T> task5(vector<pair<T, T>>& a)
{
    vector<T> b(a.size());
    T b0 = 0;
    b[0] = b0;
    for (int i = 1; i < a.size(); i++)
    {
        b0 += length(a[i], a[i-1]);
        b[i] = b0;
    }
    return b;
}

template <class T>
T k_mean(vector<T>& a, int i, int k)
{
    T result = a[i];
    for (int j = i + 1; j < i + k; j++)
    {
        result += a[j];
    }
    return result / k;
}
template <class T>
vector<T> task6(vector<T>& a, int k)
{
    vector<T> b(a.size()-k+1);
    T b0;
    for (int i = 0; i < a.size() - k + 1; i++)
    {
        b[i] = k_mean(a, i, k);
    }
    return b;
}

template <class T>
T reverse_sum(vector<T>& a, int i)
{
    T result = a[i];
    for (int j = i + 1; j < a.size(); j++)
    {
        result += a[j];
    }
    return result;
}
template <class T>
vector<T> task7(vector<T>& a)
{
    vector<T> b(a.size());
    T data = reverse_sum(a, 0);
    for (int i = 0; i < a.size(); i++)
    {
        b[i] = data;
        data -= a[i];
    }
        
    return b;
}

template <class T>
T length(triple<T>& a2, triple<T>& a1)
{
    return sqrt((a2.x - a1.x) * (a2.x - a1.x) + (a2.y - a1.y) * (a2.y - a1.y) + (a2.z - a1.z)*(a2.z - a1.z));
}
template <class T>
vector<T> task8(vector<triple<T>>& a)
{
    vector<T> b(a.size());
    T b0 = 0;
    b[0] = b0;
    for (int i = 1; i < a.size(); i++)
    {
        b0 += length(a[i], a[i - 1]);
        b[i] = b0;
    }
    return b;
}

template <class T>
T k_geometric_mean(vector<T>& a, int i, int k)
{
    T result = a[i];
    for (int j = i + 1; j < i + k; j++)
    {
        result *= a[j];
    }
    return pow(result, 1.0/k);
}
template <class T>
vector<T> task9(vector<T>& a, int k)
{
    vector<T> b(a.size() - k + 1);
    T b0;
    for (int i = 0; i < a.size() - k + 1; i++)
    {
        b0 = k_geometric_mean(a, i, k);
        b[i] = b0;
    }
    return b;
}

template <class T>
vector<T> task10(vector<T>& a, vector<int>& p)
{
    vector<T> b(a.size());
    for (int i = 0; i < a.size(); i++)
        b[i] = a[p[i]];
    return b;
}

vector<int> task11(vector<int>& a)
{
    vector<int> b(a.size());

    for (int i = 0; i < a.size(); i++)
        b[a[i]] = i;
    return b;
}

int sum_of_digits(int num)
{
    int result = 0;
    while (num > 0)
    {
        result += num % 10;
        num /= 10;
    }
    return result;
}
vector<int> task12(vector<int>& a)
{
    vector<int> b(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        b[i] = sum_of_digits(a[i]);
    }
    return b;
}

vector<int> task13(vector<int>& a)
{
    vector<int> b = a;
    int i = 0; int j = a.size() - 1;

    do
    {
        while (i < j && b[i] % 2 == 0) i++;
        while (i < j && b[j] % 2 == 0) j--;
        int temp = b[i];
        b[i] = b[j];
        b[j] = temp;
        i++; j--;
    } while (i < j);
    return b;
}

template <class T>
T mediana(vector<T> triple)
{
    if (triple.size() == 1)
        return triple[0];
    if (triple.size() == 2)
        return (triple[0] + triple[1]) / 2;
    
    if (triple[0] <= triple[1] && triple[1] <= triple[2] || 
        triple[2] <= triple[1] && triple[1] <= triple[0])
        return triple[1];
    if (triple[1] <= triple[0] && triple[0] <= triple[2] || 
        triple[2] <= triple[0] && triple[0] <= triple[1])
        return triple[0];
    if (triple[0] <= triple[2] && triple[2] <= triple[1] || 
        triple[1] <= triple[2] && triple[2] <= triple[0])
        return triple[2];
    
}
template <class T>
vector<T> task14(vector<T> a)
{
    vector<T> b(a.size() / 3 + bool(a.size()%3));
    vector<T> temp;
    int i;
    int j = 0;
    for (i = 0; i < a.size() - a.size() % 3; i += 3)
    {
        temp.push_back(a[i]);
        temp.push_back(a[i + 1]);
        temp.push_back(a[i + 2]);
        
        T med = mediana(temp);
        b[j] = med;
        j++;

        temp.clear();
    }
    while (i < a.size())
    {
        temp.push_back(a[i]);
        i++;
    }
    if (temp.size() != 0)
    {
        T med = mediana(temp);
        b[j] = med;
    }

    return b;
}

template <class T>
pair<T, T> k_max_min(vector<T>& a, int i, int k)
{
    T max = a[i];
    T min = a[i];
    for (int j = i + 1; j < i + k; j++)
    {
        if (a[j] > max) max = a[j];
        if (a[j] < min) min = a[j];
    }
    return make_pair(max, min);
}
template <class T>
vector<T> task15(vector<T>& a, int k)
{
    vector<T> b(a.size() - k + 1);
    pair<T, T> max_min;
    for (int i = 0; i < a.size() - k + 1; i++)
    {
        max_min = k_max_min(a, i, k);
        b[i] = max_min.first - max_min.second;
    }
    return b;
}

int main()
{
    /*int cl = clamp(-1, 0, 2);
    cout << cl;*/

    /*vector<int> a = { 0, 1, 2, -1, 4, 8 };
    vector<int> b = slopes(a);
    print_vector(b);*/

    /*vector<double> a = { 1, 2, 3, 4 };
    vector<double> b = means(a);
    print_vector(b);*/

    /*vector<double> a = { 1, 2, 3, 4 };
    vector<double> b = geometric_means(a);
    print_vector(b);*/

    /*vector<pair<double, double>> a = { {1,2}, {3,4}, {5, 6}};
    vector<double> b = task5(a);
    print_vector(b);*/

    /*vector<double> a = { 1, 2, 3, 4};
    vector<double> b = task6(a, 3);
    print_vector(b);*/

    /*vector<double> a = { 1, 2, 3, 4 };
    vector<double> b = task7(a);
    print_vector(b);*/

    /*vector<triple<double>> a = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    vector<double> b = task8(a);
    print_vector(b);*/

    /*vector<double> a = { 1, 2, 3, 4 };
    vector<double> b = task9(a, 3);
    print_vector(b);*/

    /*vector<double> a = { 1, -2.5, 0.3, 8, -3, 5.7 };
    vector<int> p = { 5, 1, 3, 2, 0, 4 };
    vector<double> b = task10(a, p);
    print_vector(b);*/

    /*vector<int> a = { 0, 5, 1, 4, 2, 3 };
    vector<int> b = task11(a);
    print_vector(b);*/

    /*vector<int> a = { 5, 10, 15, 20, 25 };
    vector<int> b = task12(a);
    print_vector(b);*/

    /*vector<int> a = { 0, 1, 2, 3, 5, 6, 4, 8, 7 };
    vector<int> b = task13(a);
    print_vector(b);*/

    /*vector<int> a = { 1, 5, 1, 4, 5, 6, 2, 1, 3, 4, 4, 4, 5, 7};
    vector<int> b = task14(a);
    print_vector(b);*/

    /*vector<int> a = { 1, 2, 4, 4, 4, 6, 7, 8 };
    vector<int> b = task15(a, 2);
    print_vector(b);*/


}
