#include <iostream>
using namespace std;

void bubbleSort(int* num, int size) {
    int count=0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (num[j - 1] > num[j]) {
                count++;
                swap(num[j-1], num[j]);
            }
        }
    }
    cout << "Количество перестановок: " << count << "\nОтсортированный список: ";
    for (int i=0; i<size; i++) {
        cout << num[i] << " ";
    }
}

void extremSort(int* num, int size) {
    int count=0;
    for (int start = 0; start < size - 1; start++) {
        int small = start;
        for (int now = start + 1; now < size; now++) {
            if (num[now] < num[start]) {
                count++;
                small = now;
                swap(num[start], num[small]);
            }
        }
    }
    cout << "Количество сравнений: " << count << "\nОтсортированный список: ";
    for (int i=0; i<size; i++) {
        cout << num[i] << " ";
    }
}

void insertSort(int *num, int size) {
    int temp, item;
    for (int counter = 1; counter < size; counter++) {
        temp = num[counter];
        item = counter-1;
        while(item >= 0 && num[item] > temp) {
            swap(num[item+1], num[item]);
            item--;
        }
    }
    cout << "Отсортированный список: ";
    for (int i=0; i<size; i++) {
        cout << num[i] << " ";
    }
}

int main (){
    int len;
    cout << "Задайте размерность списка: " ;
    cin >> len;
    int *list = new int[len];

    cout << "Введите список: ";
    for (int i=0; i<len; i++) {
        cin >> list[i];
    }

    cout << "Ваш список: ";
    for (int i=0; i<len; i++) {
        cout << list[i] << " ";
    }

    int m=0;
    cout << "\nВыберите метод сортировки: 1 - Метод Пузырька, 2 - Метод Экстремумов, 3 - Метод Простой Вставки" << endl;
    cin >> m;
    if (m==1) {
        bubbleSort(list, len);
    }
   else if (m==2) {
        extremSort(list, len);
   }
   else if (m==3) {
       insertSort(list, len);
   }
    delete [] list;
    return 0;
}

