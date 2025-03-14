#include "bits/stdc++.h"
using namespace std;

class Airplane {
private:
    int flight_number;
    int departure_time;
    char arrive_city[100];
    char depart_city[100];
    char airplane_type[100];
    int passengers_amount;
public:
    Airplane() : flight_number(0), departure_time(0), passengers_amount(0) {}

    // Конструктор с параметрами
    Airplane(int flightNum, int depTime, const char* arrCity, const char* depCity, const char* airType, int passAmount)
            : flight_number(flightNum), departure_time(depTime), passengers_amount(passAmount) {
        strcpy(arrive_city, arrCity);
        strcpy(depart_city, depCity);
        strcpy(airplane_type, airType);
    }

    // Геттеры
    int get_flight_number() const { return flight_number; }
    int get_departure_time() const { return departure_time; }
    const char* get_arrive_city() const { return arrive_city; }
    const char* get_depart_city() const { return depart_city; }
    const char* get_airplane_type() const { return airplane_type; }
    int get_passengers_amount() const { return passengers_amount; }

    // Сеттеры для изменения данных
    void set_flight_number(int num) { flight_number = num; }
    void set_departure_time(int time) { departure_time = time; }
    void set_arrive_city(const char* city) { strcpy(arrive_city, city); }
    void set_depart_city(const char* city) { strcpy(depart_city, city); }
    void set_airplane_type(const char* type) { strcpy(airplane_type, type); }
    void set_passengers_amount(int amount) { passengers_amount = amount; }
};
void write_to_file(const char* filename, Airplane flights[], int size) {
    ofstream file(filename, ios::binary | ios::app); // Открываем файл в бинарном режиме для добавления
    if (!file) {
        cout << "Cannot open file for writing.\n";
        return;
    }

    // Записываем данные в файл
    for (int i = 0; i < size; i++) {
        file.write(reinterpret_cast<const char*>(&flights[i]), sizeof(Airplane));
    }

    file.close();
}
void read_from_file(const char* filename) {
    ifstream file(filename, ios::binary); // Открываем файл в бинарном режиме для чтения
    if (!file) {
        cout << "Cannot open file for reading.\n";
        return;
    }

    // Выводим заголовок таблицы
    printf("%-15s%-15s%-15s%-15s%-20s%-20s\n",
           "Flight number", "Departure time", "Departure city", "Arrival city", "Airplane type", "Passengers amount");

    Airplane temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Airplane))) {
        printf("%-15d%-15d%-15s%-15s%-20s%-20d\n",
               temp.get_flight_number(),
               temp.get_departure_time(),
               temp.get_depart_city(),
               temp.get_arrive_city(),
               temp.get_airplane_type(),
               temp.get_passengers_amount());
    }

    file.close();
}
void add_to_file(const char* filename) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cout << "Cannot open file for appending.\n";
        return;
    }

    Airplane new_flight;
    cout << "Enter flight number: ";
    int flight_number; cin >> flight_number;
    new_flight.set_flight_number(flight_number);

    cout << "Enter departure time: ";
    int departure_time; cin >> departure_time;
    new_flight.set_departure_time(departure_time);

    cout << "Enter departure city: ";
    char dep_city[100];
    cin.ignore(); // Очищаем буфер после числа
    cin.getline(dep_city, 100);
    new_flight.set_depart_city(dep_city);

    cout << "Enter arrival city: ";
    char arr_city[100];
    cin.getline(arr_city, 100);
    new_flight.set_arrive_city(arr_city);

    cout << "Enter airplane type: ";
    char type[100]; cin.getline(type, 100);
    new_flight.set_airplane_type(type);

    cout << "Enter passengers amount: ";
    int pass_amount; cin >> pass_amount;
    new_flight.set_passengers_amount(pass_amount);

    file.write(reinterpret_cast<const char*>(&new_flight), sizeof(Airplane));

    file.close();
    cout << "New flight has been added to the file.\n";
}
int read_from_file_to_array(const char* filename, Airplane flights[], int max_size) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Cannot open file for reading.\n";
        return 0;
    }

    int count = 0;
    while (count < max_size && file.read(reinterpret_cast<char*>(&flights[count]), sizeof(Airplane))) {
        if (strlen(flights[count].get_arrive_city()) == 0 || strlen(flights[count].get_depart_city()) == 0 ||
            strlen(flights[count].get_airplane_type()) == 0) {
            break;
        }
        count++;
    }

    file.close();
    return count;
}
void number_linear_search(Airplane flights[], int size, int number)
{
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (number == flights[i].get_flight_number())
        {
            cout << "The race is " << i;
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout << "The race is not found.\n";
    }
}
void view_flights(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Cannot open file for reading.\n";
        return;
    }

    printf("%-15s%-15s%-15s%-15s%-20s%-20s\n",
           "Flight number", "Departure time", "Departure city", "Arrival city", "Airplane type", "Passengers amount");

    Airplane temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Airplane))) {
        printf("%-15d%-15d%-15s%-15s%-20s%-20d\n",
               temp.get_flight_number(),
               temp.get_departure_time(),
               temp.get_depart_city(),
               temp.get_arrive_city(),
               temp.get_airplane_type(),
               temp.get_passengers_amount());
    }

    file.close();
}

//сортировка выбором по колву пассажиров
void passengers_choice_search(Airplane flights[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < size; j++)
        {
            if (flights[j].get_passengers_amount() < flights[mini].get_passengers_amount())
            {
                mini = j;
            }
            Airplane temp = flights[i];
            flights[i] = flights[mini];
            flights[mini] = temp;
        }
    }
}
//бинпоиск по времени вылета
int time_binary_search(Airplane flights[], int size, int time)
{
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
       int mid = left + (right - left) / 2;
       if (flights[mid].get_departure_time() == time)
       {
           return mid;
       }
       else if(flights[mid].get_departure_time() > time)
       {
           right = mid - 1;
       }
       else
       {
           left = mid + 1;
       }
    }
    return -1;
}
//вставками по типу самолета
void insertion_sort(Airplane flights[], int size)
{
    for (int i = 1; i < size; i++)
    {
        Airplane key = flights[i];
        int j = i - 1;
        while(strcmp(flights[j].get_airplane_type(), key.get_airplane_type()) > 0 && j >= 0)
        {
            flights[j + 1] = flights[j];
            j--;
        }
        flights[j + 1] = key;
    }
}

int partition(Airplane flights[], int low, int high)
{
    const char* pivot = flights[high].get_arrive_city();
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (strcmp(flights[j].get_arrive_city(), pivot) < 0)
        {
            i++;
            swap(flights[i], flights[j]);
        }
    }
    swap(flights[i + 1], flights[high]);
    return i;
}
//быстрая по направлению
void quicksort(Airplane flights[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(flights, low, high);
        quicksort(flights, low, pi - 1);
        quicksort(flights, pi + 1, high);
    }
}
//по времени
void bubble_sort_time(Airplane flights[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j =  0; j < size; j++)
        {
            if (flights[j + 1].get_departure_time() < flights[j].get_departure_time())
            {
                Airplane temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
        }
    }
}


int main() {

    const char* filename = "airplanes.txt"; // Имя бинарного файла
    const int MAX_FLIGHTS = 100; // Максимальное количество рейсов
    Airplane flights[MAX_FLIGHTS]; // Массив для хранения рейсов

    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Create initial data in file\n"
             << "2. Read data from file\n"
             << "3. Add new flight to file\n"
             << "4. Linear search by flight number\n"
             << "5. Binary search by departure time\n"
             << "6. Sort by passengers amount (Selection Sort)\n"
             << "7. Sort by airplane type (Insertion Sort)\n"
             << "8. Sort by arrival city (Quick Sort)\n"
             << "9. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Создание начальных данных в файле
                Airplane initial_flights[] = {
                        {101, 600, "Paris", "Moscow", "Boeing 737", 150},
                        {102, 600, "New York", "London", "Airbus A320", 200},
                        {103, 800, "Tokyo", "Beijing", "Boeing 777", 300},
                        {104, 900, "Berlin", "Moscow", "Airbus A321", 180}
                };

                int initial_size = sizeof(initial_flights) / sizeof(Airplane);

                // Удаляем старый файл перед созданием нового
                remove(filename);
                write_to_file(filename, initial_flights, initial_size);
                cout << "Initial data has been written to the binary file.\n";
                break;
            }
            case 2: { // Чтение данных из файла
                view_flights(filename);
                break;
            }
            case 3: { // Добавление новой записи в файл
                add_to_file(filename);
                break;
            }
            case 4: { // Линейный поиск по номеру рейса
                int number;
                cout << "Enter flight number to search: ";
                cin >> number;

                int size = read_from_file_to_array(filename, flights, MAX_FLIGHTS);
                number_linear_search(flights, size, number);
                break;
            }
            case 5: { // Бинарный поиск по времени вылета
                int time;
                cout << "Enter departure time to search: ";
                cin >> time;

                int size = read_from_file_to_array(filename, flights, MAX_FLIGHTS);
                int index = time_binary_search(flights, size, time);
                if (index != -1) {
                    cout << "Flight found at index: " << index << endl;
                } else {
                    cout << "Flight not found.\n";
                }
                break;
            }
            case 6: { // Сортировка выбором по количеству пассажиров
                int size = read_from_file_to_array(filename, flights, MAX_FLIGHTS);
                passengers_choice_search(flights, size);

                // Обновляем файл с отсортированными данными
                ofstream file(filename, ios::binary | ios::trunc); // Открываем файл для перезаписи
                if (!file) {
                    cout << "Cannot open file for writing.\n";
                    break;
                }
                for (int i = 0; i < size; ++i) {
                    file.write(reinterpret_cast<const char*>(&flights[i]), sizeof(Airplane));
                }
                file.close();
                cout << "Flights sorted by passengers amount.\n";
                break;
            }
            case 7: { // Сортировка вставками по типу самолета
                int size = read_from_file_to_array(filename, flights, MAX_FLIGHTS);
                insertion_sort(flights, size);

                // Обновляем файл с отсортированными данными
                ofstream file(filename, ios::binary | ios::trunc); // Открываем файл для перезаписи
                if (!file) {
                    cout << "Cannot open file for writing.\n";
                    break;
                }
                for (int i = 0; i < size; ++i) {
                    file.write(reinterpret_cast<const char*>(&flights[i]), sizeof(Airplane));
                }
                file.close();
                cout << "Flights sorted by airplane type.\n";
                break;
            }
            case 8: { // Быстрая сортировка по направлению
                int size = read_from_file_to_array(filename, flights, MAX_FLIGHTS);
                quicksort(flights, 0, size - 1);

                // Обновляем файл с отсортированными данными
                ofstream file(filename, ios::binary | ios::trunc); // Открываем файл для перезаписи
                if (!file) {
                    cout << "Cannot open file for writing.\n";
                    break;
                }
                for (int i = 0; i < size; ++i) {
                    file.write(reinterpret_cast<const char*>(&flights[i]), sizeof(Airplane));
                }
                file.close();
                cout << "Flights sorted by arrival city.\n";
                break;
            }
            case 9: { // Выход из программы
                cout << "Exiting program.\n";
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}



