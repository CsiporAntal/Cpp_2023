#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 1. Feladat
    vector<string> fruits{"melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"};
    string searchSubstring = "berry";
    auto found = find_if(fruits.begin(), fruits.end(), [searchSubstring](const string& fruit) {
        return fruit.find(searchSubstring) != string::npos;
    });
    if (found != fruits.end()) {
        cout << "Van olyan gyümölcs, amely tartalmaz \"" << searchSubstring << "\" karakterláncot." << endl;
    } else {
        cout << "Nincs olyan gyümölcs, amely tartalmaz \"" << searchSubstring << "\" karakterláncot." << endl;
    }

    // 2. Feladat
    vector<int> numbers{2, 4, 6, 8, 10};
    bool allEven = all_of(numbers.begin(), numbers.end(), [](int num) {
        return num % 2 == 0;
    });
    cout << (allEven ? "Minden szám páros." : "Nem minden szám páros.") << endl;

    // 3. Feladat
    vector<int> arrayToDouble{1, 2, 3, 4, 5};
    for_each(arrayToDouble.begin(), arrayToDouble.end(), [](int& num) {
        num *= 2;
    });

    cout << "A tömb elemei duplázva: ";
    for (int num : arrayToDouble) {
        cout << num << " ";
    }
    cout << endl;

    // 4. Feladat
    vector<string> months{"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};

    int fiveLetterMonths = count_if(months.begin(), months.end(), [](const string& month) {
        return month.length() == 5;
    });

    cout << "Az öt karakteres hónapok száma: " << fiveLetterMonths << endl;


    // 5. Feladat
    vector<double> realNumbers{3.14, 1.5, 4.0, 2.71, 0.99};
    // Lambda kifejezéssel
    sort(realNumbers.begin(), realNumbers.end(), [](double a, double b) {
        return a > b;
    });
    // greater<> funktorral
    sort(realNumbers.begin(), realNumbers.end(), greater<>());


    cout << "Rendezett sorrend (greater<> funktor): ";
    for (double num : realNumbers) {
        cout << num << " ";
    }
    cout << endl;
    // 6. Feladat
    vector<pair<string, double>> monthsWithTemperature{
            {"January", 0.5}, {"February", 2.3}, {"March", 8.0}, {"April", 15.0},
            {"May", 20.5}, {"June", 25.0}, {"July", 30.0}, {"August", 28.0},
            {"September", 22.0}, {"October", 15.5}, {"November", 8.0}, {"December", 2.5}
    };
    sort(monthsWithTemperature.begin(), monthsWithTemperature.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });

    for (const auto& month : monthsWithTemperature) {
        cout << month.first << ": " << month.second << " C" << endl;
    }

    // 7. Feladat
    vector<double> absoluteSortedNumbers{3.14, -1.5, 4.0, -2.71, 0.99};
    sort(absoluteSortedNumbers.begin(), absoluteSortedNumbers.end(), [](double a, double b) {
        return abs(a) < abs(b);
    });

    for (double number : absoluteSortedNumbers) {
        cout << number << " ";
    }


    // 8. Feladat
    transform(months.begin(), months.end(), months.begin(), [](string& month) {
        transform(month.begin(), month.end(), month.begin(), ::tolower);
        return month;
    });


    return 0;
}
