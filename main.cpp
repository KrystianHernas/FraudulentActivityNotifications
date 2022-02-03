#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

std::vector<int> inputArray();
int activityNotifications(std::vector<int>& , const int&);

int main()
{
    int d;
    std::cout << "Input trailing days: " << std::endl; std::cin >> d;
    std::vector<int> expenditure = inputArray();
    int a = activityNotifications(expenditure, d);
    return 0;
}

std::vector<int> inputArray() {
    int n = 0, temp = 0; std::vector<int> q;
    std::cout << "Input array size: " << std::endl; std::cin >> n;
    std::cout << "Input expenditure array" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> temp; q.push_back(temp);
    }
    temp = q.size();
    try {
        if (temp < 1 || temp > 100000 || std::cin.fail()) {
            throw std::invalid_argument("Too large queue");
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return q;
};

int activityNotifications(std::vector<int>& expenditure, const int& d) {
    int j = 0, sizz = expenditure.size(), numberOfNotification = 0; double median;
    std::sort(expenditure.begin(), expenditure.end());
    for (int i = 0; i < expenditure.size(); i++) {
        std::cout << expenditure[i] << ' ';
    }
    std::cout << std::endl;
            // check for even case
    for (int i = d; i < sizz-1; i++) {
        if (d % 2 != 0)
            median = (double)expenditure[(i - d) + (d / 2)];
        else median = (double)(expenditure[((i - d) + (d - 1)) / 2]) + (double)(expenditure[(i - d) + (d / 2)]) / 2.0;
        if (expenditure[i + 1] >= 2 * median) {
            numberOfNotification++;
        }
    }
    std::cout << numberOfNotification;
    return numberOfNotification;
}