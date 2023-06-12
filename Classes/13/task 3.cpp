#include <iostream>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
typedef set<int> Set;

void replaceMax(Set& container, int newValue)
{
    if (!container.empty()) {
        
        int maxElement = *max_element(container.begin(), container.end());

        
        container.erase(maxElement);

        
        container.insert(newValue);
    }
}


void removeMin(Set& container)
{
    if (!container.empty()) {
        
        int minElement = *container.begin();

        
        container.erase(minElement);
    }
}


void addAverage(Set& container)
{
    if (!container.empty()) {
        
        int sum = 0;
        for (int num : container) {
            sum += num;
        }
        int average = sum / container.size();

        
        std::set<int> tempContainer;

        
        for (int num : container) {
            tempContainer.insert(num + average);
        }

        
        container = std::move(tempContainer);
    }
}
void print_set(Set container)
{
    for (int num : container) {
        cout << num << " ";
    }
    cout << endl;
}
Set make_set(int n)
{
    Set temp;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        temp.insert(a);
    }
    return temp;
}
int main()
{
    int n;
    cout << "n? " << endl;
    cin >> n;
    Set container = make_set(n);
    print_set(container);

    cout << "replace? " << endl;
    cin >> n;
    replaceMax(container, n);
    print_set(container);
    

    removeMin(container);
    print_set(container);

    
    addAverage(container);
    print_set(container);

    return 0;
}