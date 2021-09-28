#include<iostream>
#include<algorithm>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;
    Contact* next;
};

class ContactBook {
private:
    Contact* head;
public:
    ContactBook() {
        head = NULL;
    }

    // Adds a contact in the book
    // so that the contacts are always sorted
    // in ascending order (by name)
    void addContact(string name, string phone) {
        Contact* n1 = new Contact;
        n1->name = name;
        n1->phoneNumber = phone;
        n1->next = NULL;
        if (head == NULL) {
            head = n1;
        }
        else {
            Contact* n2 = head;
            while (n2->next != NULL) {
                if (n2->name > name) {
                    n1->next = head;
                    head = n1;
                    return;
                }
                n2 = n2->next;
            }
            n2->next = n1;
        }

    }

    // Prints all the contacts in the book
    void printList() {
        Contact* temp = head;
        if (temp == NULL) {
            std::cout << "No elements in the list " << std::endl;
            return;
        }
        else {
            while (temp != NULL) {
                std::cout << "Name: " << temp->name << " Number: " << temp->phoneNumber << std::endl;
                temp = temp->next;
            }
        }
    }

    // Searches contact book for a phone number
    // and returns the memory address of the contact.
    // If nothing is found, returns NULL.
    Contact* searchByPhoneNumber(string phNo) {
        Contact* temp = head;
        while (temp != NULL) {
            if (temp->phoneNumber == phNo) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // Deletes a contact by phone number
    void deleteByPhoneNumber(string phNo) {
        Contact* temp = head;
        while (temp != NULL) {
            if (temp->phoneNumber == phNo) {
                Contact* t1 = temp;
                head = temp->next;
                delete t1;
                return;
            }
            if (temp->next->phoneNumber == phNo) {
                Contact* t1 = temp->next;
                temp->next = temp->next->next;
                delete t1;
                return;
            }
        }
    }
    bool comparelex(char c1, char c2) {
        return std::tolower(c1) < std::tolower(c2);
    }
};

int main() {
    // Create a contact book
    ContactBook C1;
    // Add 5 contacts
    C1.addContact("Con", "015");
    C1.addContact("Aan", "016");
    C1.addContact("Jon", "017");
    C1.addContact("Bon", "018");
    // Print the book
    C1.printList();
    // Test the searchByPhoneNumber() function
    Contact* s1 = C1.searchByPhoneNumber("017");
    std::cout << s1->name << " :: " << s1->phoneNumber << std::endl;
    // Test the deleteByPhoneNumber() function
    C1.deleteByPhoneNumber("015");
    // Print the book
    cout << endl;
    C1.printList();
}