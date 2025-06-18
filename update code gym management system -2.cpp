#include <iostream>
#include <string>
using namespace std;

// New Class: Fees
class Fees {
private:
	// Data Members
    int amount;
    bool paid;

public:
    Fees() : amount(0), paid(false) {}

    void setFee(const string& type) {
        if (type == "Gold") amount = 5000;
        else if (type == "Silver") amount = 3000;
        else if (type == "Platinum") amount = 7000;
        else amount = 0;
        paid = false;
    }

    void markAsPaid() {
        if (paid) cout << "Fees already paid.\n";
        else {
            paid = true;
            cout << "Fees paid successfully.\n";
        }
    }

 void showFeeStatus() const {
        cout << "\tFee: " << amount << "\tStatus: " << (paid ? "Paid" : "Unpaid") << endl;
    }

    bool isPaid() const { return paid; }
};

// New Class: Membership
class Membership {
private:
    string type;
    string joinDate;

public:
    void inputMembership() {
        cout << "Enter membership type (Gold/Silver/Platinum): ";
        cin >> type;
        cout << "Enter join date (YYYY-MM-DD): ";
        cin >> joinDate;
    }

    void updateMembership() {
        inputMembership();
          }

    void displayMembership() const {
        cout << "\tMembership: " << type << "\tJoin Date: " << joinDate;
    }

    string getType() const { return type; }
};

// Updated Class: Member
class Member {
protected:
    int id;
    string name;
    int age;
    Membership membership;
    Fees fee;

public:
    Member() : id(0), age(0) {}

    void inputDetails(int memberId) {
        id = memberId;
        cout << "ID is = " << id << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
 membership.inputMembership();
        fee.setFee(membership.getType());
    }

    void updateDetails() {
        cout << "Enter new name: ";
        cin >> name;
        cout << "Enter new age: ";
        cin >> age;
        membership.updateMembership();
        fee.setFee(membership.getType());
    }

    void display() const {
        cout << id << "\t" << name << "\t" << age;
        membership.displayMembership();
        fee.showFeeStatus();
    }

    int getId() const { return id; }
    string getName() const { return name; }

    void payFee() {
        fee.markAsPaid();
    }

    bool isFeePaid() const {
        return fee.isPaid();
    }
};
// Gym class
class Gym {
private:
    Member members[100];
    int memberCount;

public:
    Gym() : memberCount(0) {}

    void addMember() {
        if (memberCount < 100) {
            members[memberCount].inputDetails(memberCount + 1);
            memberCount++;
            cout << "Member added successfully.\n";
        } else {
            cout << "Gym is at full capacity.\n";
        }
    }

    void viewMembers() const {
        if (memberCount == 0) {
            cout << "No members in the gym.\n";
        } else {
            cout << "\nID\tName\tAge\tMembership\tJoin Date\tFee\tStatus\n";
            cout << "---------------------------------------------------------------\n";
            for (int i = 0; i < memberCount; i++) {
                members[i].display();
            }
        }
        
 }

    void updateMember() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (int i = 0; i < memberCount; i++) {
            if (members[i].getId() == id) {
                members[i].updateDetails();
                cout << "Member updated successfully.\n";
                return;
            }
        }
        cout << "Member not found.\n";
    }

    void removeMember() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (int i = 0; i < memberCount; i++) {
            if (members[i].getId() == id) {
                for (int j = i; j < memberCount - 1; j++) {
                    members[j] = members[j + 1];
                }
                memberCount--;
                cout << "Member r removed successfully.\n";
                return;
            }
        }
        cout << "Member not found.\n";
    }

    void searchMember() const {
        string searchName;
        cout << "Enter name to search: ";
        cin >> searchName;

        for (int i = 0; i < memberCount; i++) {
            if (members[i].getName() == searchName) {
                cout << "Member found:\n";
                members[i].display();
                return;
            }
   }
    
        cout << "Member not found.\n";
    }

    void payFees() {
        int id;
        cout << "Enter member ID to pay fees: ";
        cin >> id;

        for (int i = 0; i < memberCount; i++) {
            if (members[i].getId() == id) {
                members[i].payFee();
                return;
}
        }
        cout << "Member not found.\n";
    }

    void viewUnpaidMembers() const {
        bool found = false;
        cout << "\nUnpaid Members:\n";
        for (int i = 0; i < memberCount; i++) {
            if (!members[i].isFeePaid()) {
                members[i].display();
                found = true;
            }
        }
        if (!found)
            cout << "All members have paid their fees.\n";
    }

    void displayMenu() const {
        cout << "\n\t\t** Gym Membership Management System **\n";
        cout << "1. Add Member\n";
        cout << "2. View All Members\n";
        cout << "3. Update Member\n";
        cout << "4. Remove Member\n";
        cout << "5. Search Member\n";
        cout << "6. Pay Fees\n";
        cout << "7. View Unpaid Members\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
    }
};

// Main function
int main() {
    Gym gym;
    int choice;

    while (true) {
        gym.displayMenu();
        cin >> choice;
        system("cls"); // for Windows. Use "clear" for Linux/Mac

        switch (choice) {
            case 1: gym.addMember(); break;
            case 2: gym.viewMembers(); break;
            case 3: gym.updateMember(); break;
            case 4: gym.removeMember(); break;
            case 5: gym.searchMember(); break;
            case 6: gym.payFees(); break;
            case 7: gym.viewUnpaidMembers(); break;
            case 8: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n"; break;
        }
    }

    return 0;
}


