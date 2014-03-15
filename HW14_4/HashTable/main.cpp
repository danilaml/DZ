#include <iostream>
#include <QTextStream>
#include "myhashtable.h"

using namespace std;

void uiLoop(MyHashTable *mht);
void changeFunc(MyHashTable *mht);

int main()
{
    int tableSize = 0;
    MyHashTable *mht;

    cout << "Enter Hashtable size: ";
    cin >> tableSize;

    mht = new MyHashTable(tableSize, new HashFunction(211));
    changeFunc(mht);
    uiLoop(mht);

    delete mht;

    return 0;
}

void changeFunc(MyHashTable *mht)
{
    bool flag = true;
    while (flag)
    {
        cout << "Choose hash function:" << endl
             << "#1 : prime is 211" << endl
             << "#2 : prime is 1013" << endl
             << "#3 : prime is 3559" << endl;
        cout << "Enter the number of function: ";

        int fnum = 0;
        cin >> fnum;

        switch (fnum)
        {
        case 1:
            mht->changeHashFunc(new HashFunction(211));
            flag = false;
            break;
        case 2:
            mht->changeHashFunc(new HashFunction(1013));
            flag = false;
            break;
        case 3:
            mht->changeHashFunc(new HashFunction(3559));
            flag = false;
            break;
        default:
            cout << "Number is incorrect. Please try again";
            break;
        }
    }
}

void uiLoop(MyHashTable *mht)
{
    QString cmdlist = "Command list: \n"
                      "print - prints HashTable \n"
                      "add {str} - adds string str to hashtable \n"
                      "del {str} - deletes string str from hashtable \n"
                      "contains {str} - checks if string str belongs to hashtable \n"
                      "stats - shows statistics for current HashTable \n"
                      "changeHash - changes hash function \n"
                      "help - prints this text \n";

    QTextStream qout(stdout, QIODevice::WriteOnly);
    QTextStream qin(stdin, QIODevice::ReadOnly);
    qout << cmdlist << flush;

    while (true)
    {
        QString input;
        qin >> input;
        if(input == "changeHash")
        {
            changeFunc(mht);
        }
        else
        {
            switch (input[0].toLatin1())
            {
            case 'h':
                qout << cmdlist << flush;
                continue;
            case 'p':
                mht->print();
                break;
            case 'a':
                qin >> input;
                mht->add(input);
                break;
            case 'd':
                qin >> input;
                mht->del(input);
                break;
            case 'c':
                qin >> input;
                cout << (mht->contains(input) ? "Element is found" : "No such element") << endl;
                break;
            case 's':
                cout << "Table size is: " << mht->tableSize() << endl
                     << "Load factor is: " << mht->loadFactor() << endl
                     << "Number of conflicts is: " << mht->numberOfConflicts() << endl
                     << "Biggest conflict length is: " << mht->biggestConflitSize() << endl;
                break;
            default:
                cout << "Incorrect input. Please try again" << endl;
                continue;
                break;
            }
        }
    }
}
