#include <iostream>
#include <cstring>

using namespace std;

enum Extension {
    pdf = 0, txt = 1, exe = 2
};

class File {
    char *name;
    Extension exe1;
    char *owner;
    int size;

public:
    File(const char *name = "", const char *owner = "", int size = 0, Extension exe1 = txt) : size(size) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->owner = new char[strlen(owner) + 1];
        strcpy(this->owner, owner);
        this->exe1 = exe1;
    }

    File(const File &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->owner = new char[strlen(other.owner) + 1];
        strcpy(this->owner, other.owner);
        this->exe1 = other.exe1;
        this->size = other.size;
    }

    File &operator=(const File &other) {
        if (this != &other) {
            delete[] name;
            delete[] owner;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->owner = new char[strlen(other.owner) + 1];
            strcpy(this->owner, other.owner);
            this->exe1 = other.exe1;
            this->size = other.size;
        }
        return *this;
    }

    void print() {
        cout << "File name: " << name << ".";
        char *a = "";
        if (exe1 == 0) a = "pdf";
        else if (exe1 == 1) a = "txt";
        else a = "exe";
        cout << a << "\nFile owner: " << owner << endl;
        cout << "File size: " << size << endl;
    }

    bool equals(const File &other) {
        if (strcmp(this->name, other.name) == 0 && strcmp(this->owner, other.owner) == 0 &&
            (this->exe1 == other.exe1)) {
            return true;
        } else return false;

    }

    bool equalsType(const File &other) {
        if (strcmp(this->name, other.name) == 0 && (this->exe1 == other.exe1)) {
            return true;
        } else return false;

    }

    ~File() {
        delete[] name;
        delete[] owner;
    }
};

class Folder {
    char *nameOfFolder;
    int numberOfFiles;
    File *files;
public:
    Folder(const char *nameOfFolder) {
        this->nameOfFolder = new char[strlen(nameOfFolder) + 1];
        strcpy(this->nameOfFolder, nameOfFolder);
        this->numberOfFiles = 0;
        this->files = 0;
    }
//
//    Folder(const Folder &other) {
//        this->nameOfFolder = new char[strlen(other.nameOfFolder) + 1];
//        strcpy(this->nameOfFolder, other.nameOfFolder);
//        this->files = new File[other.numberOfFiles];
//        for (int i = 0; i < numberOfFiles; ++i) {
//            this->files[i] = files[i];
//        }
//        this->numberOfFiles = other.numberOfFiles;
//    }

    ~Folder() {
        delete[] nameOfFolder;
        delete[] files;
    }

    void print() {
        cout << "Folder name: " << nameOfFolder << endl;
        for (int i = 0; i < numberOfFiles; ++i) {
            files[i].print();
        }
    }

    void remove(const File &file) {
        int temp = 0;
        for (int i = 0; i < numberOfFiles; ++i) {
            if (files[i].equals(file) == false) {
                temp++;
            }
        }
        File *tmp1 = files;
        this->files = new File[numberOfFiles - 1];
        int k = 0;
        for (int i = 0; i < numberOfFiles; ++i) {
            if (tmp1[i].equals(file) == false) {
                files[k] = tmp1[i];
                k++;
            }
        }
        numberOfFiles = temp;
    }

    void add(const File &file) {
        File *tmp = files;
        this->files = new File[numberOfFiles + 1];
        for (int i = 0; i < numberOfFiles; ++i) {
            files[i] = tmp[i];
        }
        files[numberOfFiles++] = file;
    }

};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    } else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    } else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    } else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    } else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}