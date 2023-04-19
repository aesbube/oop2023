#include <iostream>

using namespace std;

class List {
    int *array;
    int number;

public:
    List(int *array = 0, int number = 0) : number(number) {
        this->array = new int[number];
        for (int i = 0; i < number; ++i) {
            this->array[i] = array[i];
        }
//        cout << "default" << endl;
    }

    List(const List &other) {
        this->number = other.number;
        this->array = new int[other.number];
        for (int i = 0; i < number; ++i) {
            this->array[i] = other.array[i];
        }
//        cout << "copy" << endl;
    }

    List &operator=(const List &other) {
        if (this != &other) {
            delete[] array;
            this->number = other.number;
            this->array = new int[other.number];
            for (int i = 0; i < number; ++i) {
                this->array[i] = other.array[i];
            }
        }
        return *this;
//        cout<<"equal"<<endl;

    }

    int sum() {
        int temp = 0;
        for (int i = 0; i < number; ++i) {
            temp += array[i];
        }
        return temp;
    }

    double average() {
        return double(sum()) / number;
    }

    void print() {
        cout << number << ": ";
        for (int i = 0; i < number; ++i) {
            cout << array[i] << " ";
        }
        cout << "sum: " << sum() << " average: " << average() << endl;
    }

    void setArray(int *array) {
        for (int i = 0; i < number; ++i) {
            this->array[i] = array[i];
        }
    }

    int *getArray() const {
        return array;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        List::number = number;
    }

    ~List() {
        delete[] array;
    }
};

class ListContainer {
    List *array;
    int number;
    int numberOfAttempts;

public:
    ListContainer(List *array = 0, int number = 0, int numberOfAttempts = 0) : number(number),
                                                                               numberOfAttempts(numberOfAttempts) {
        this->array = new List[number];
        for (int i = 0; i < number; ++i) {
            this->array[i] = array[i];
        }
    }

//    ListContainer(List *array = {0}, int number = 0, int numberOfAttempts = 0 ) : number(number),
//                                                                                 numberOfAttempts(numberOfAttempts),
//                                                                                 array(new List[number]) {
//        for (int i = 0; i < number; ++i) {
//            this->array[i] = array[i];
//        }
//    }


    ListContainer(const ListContainer &other) : number(other.number), numberOfAttempts(other.numberOfAttempts) {
        this->array = new List[other.number];
        for (int i = 0; i < other.number; ++i) {
            this->array[i] = other.array[i];
        }
    }

    ListContainer &operator=(const ListContainer &other) {
        if (this != &other) {
            delete[] array;
            this->number = other.number;
            this->numberOfAttempts = other.numberOfAttempts;
            this->array = new List[other.number];
            for (int i = 0; i < other.number; ++i) {
                this->array[i] = other.array[i];
            }
        }
        return *this;
    }

    int sum() {
        int temp = 0;
        for (int i = 0; i < number; ++i) {
            temp += array[i].sum();
        }
        return temp;
    }

    double average() {
        double temp = 0;
        int no = 0;
        for (int i = 0; i < number; ++i) {
            no += array[i].getNumber();
        }
        temp = double(sum()) / no;
        return temp;
    }

    void print() {
        if (number == 0) {
            cout << "The list is empty" << endl;
        } else {
            for (int i = 0; i < number; ++i) {
                cout << "List number: " << i + 1 << " List info: ";
                array[i].print();
            }
            cout << "Sum: " << sum() << " Average: " << average() << endl;
            cout << "Successful attempts: " << number << " Failed attempts: " << numberOfAttempts - number << endl;
        }
    }

    void addNewList(List &l) {
        int a = 1;
        for (int i = 0; i < number; ++i) {
            if (l.sum() == array[i].sum()) {
                a = 0;
                break;
            }
        }
        if (a) {
            List *temp = new List[number + 1];
            for (int i = 0; i < number; ++i) {
                temp[i] = array[i];
            }
            temp[number++] = l;
            delete[]array;
            array = temp;
        }
        numberOfAttempts++;
    }

//    ~ListContainer() {
//        delete[] array;
//
//    }
};


int main() {

    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];

        }

        List l = List(niza, n);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();

    } else {
        lc.print();
    }
}