#include <iostream>
#include "contact.hpp"
#include "addressbook.hpp"

int main() {
    AddressBook addressBook;

    Friend* john = new Friend("John Doe", "1990-01-01", "123-456-7890", "123 Elm St");
    Acquaintance* jane = new Acquaintance("Jane Smith", "987-654-3210");
    Colleague* bob = new Colleague("Bob Johnson", "555-555-5555", "Tech Corp", "456 Oak St");

    addressBook.addContact(john);
    addressBook.addContact(jane);
    addressBook.addContact(bob);

    // Search for a contact by name
    Contact* searchResult = addressBook.searchByName("John Doe");
    if (searchResult) {
        std::cout << "Found contact: " << searchResult->getName() << std::endl;
    }
    else {
        std::cout << "Contact not found." << std::endl;
    }

    // Get a list of friends
    std::vector<Friend*> friends = addressBook.getFriends();
    std::cout << "Friends list:" << std::endl;
    for (Friend* friendContact : friends) {
        std::cout << friendContact->getName() << " - " << friendContact->getDOB() << std::endl;
    }

    // Delete a contact by name
    addressBook.deleteContact("Jane Smith");

    // Verify deletion
    searchResult = addressBook.searchByName("Jane Smith");
    if (!searchResult) {
        std::cout << "Contact 'Jane Smith' successfully deleted." << std::endl;
    }

    return 0;
}
