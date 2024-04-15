#include <iostream>;
#include "windows.h";
using namespace std;

struct SearchResult {
    int searchValue = -1;
    int attemptsCount = 0;
};

SearchResult binarySearch(int n, const int const *a, int count) {
    int low = 0;
    int high = count - 1;
    SearchResult searchResult;

    while (low < high) {
        searchResult.attemptsCount++;
        int mid = low + (high - low) / 2;
        if (a[mid] > n) {
            high = mid - 1;
        }
        else if (a[mid] < n) {
            low = mid + 1;
        }
        else {
            searchResult.searchValue = mid;
            return searchResult;
        }
    }
    return searchResult;

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int count = 25;
    int a[count];

    for (int i = 0; i < count; i++) {
        if (i == 0) {
            a[i] = 1;
        }
        else {
            a[i] = a[i - 1] * 2;
        }
    }

    unsigned int n;
    cout << "Введіть число для пошуку: ";
    cin >> n;

    SearchResult searchResult = binarySearch(n, a, count);

    if (searchResult.searchValue == -1) {
        cout << "Число " << n << " не знайдено. ";
    }
    else {
        cout << "Число " << n << " знайдено. Його індекс " << searchResult.searchValue << ". ";
    }
    cout << "Кількість ітерацій пошуку: " << searchResult.attemptsCount << endl;
}