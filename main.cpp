#include "linked_list.hpp"
#include <string>

using namespace std;

int main() {
    LinkedList<int> list1;
    cout << "--printing empty list--" << endl;
    list1.print_list();
    cout << "-- one insertion --" << endl;
    list1.insert(5, 0);
    list1.print_list();
    cout << "--insert at end" << endl;
    list1.insert(2, 1);
    list1.print_list();
    cout << "--insert in middle--" << endl;
    list1.insert(3, 1);
    list1.print_list();
    cout << "--insertion oob--" << endl;
    list1.insert(2, 8);
    list1.insert(4, -1);
    list1.print_list();
    cout << "--copying list using = --" << endl;
    LinkedList<int> list2 = list1;
    list2.print_list();
    cout << "--insert into deep-copied list--" << endl;
    list2.insert(3, 4);
    cout << "list 1: ";
    list1.print_list();
    cout << "list 2: ";
    list2.print_list();
    cout << "--copying list using copy constructor (and proving deep copy with an insert)--" << endl;
    LinkedList<int> list3(list1);
    list3.insert(-25, 14);
    cout << "list 1: ";
    list1.print_list();
    cout << "list3: ";
    list3.print_list();
    cout << "--removing from list 1 at beginning--" << endl;
    list1.remove(0);
    list1.print_list();
    cout << "--removing from list 2 at the end--" << endl;
    list2.remove(1);
    list2.print_list();
    cout << "--removing in the middle (position 1) from list 3--" << endl;
    list3.remove(1);
    list3.print_list();
    cout << "--oob removal from list 3--" << endl;
    list3.remove(-1);
    list3.remove(20);
    list3.print_list();
    cout << "--printing items from beginning, middle, end, and oob from list 1--" << endl;
    cout << "list 1: ";
    list1.print_list();
    cout << "value at 0: ";
    list1.print_item(0);
    cout << "value at end: ";
    list1.print_item(3);
    cout << "value at 2: ";
    list1.print_item(2);
    cout << "oob:" << endl;
    list1.print_item(-1);
    list1.print_item(20);
    cout << "--template class check--" << endl;
    LinkedList<string> list_string;
    list_string.insert("yippee", 1);
    list_string.insert("yay", 2);
    list_string.insert("heck yeah", 4);
    list_string.print_list();
    list_string.remove(1);
    list_string.print_list();


    return 0;
}