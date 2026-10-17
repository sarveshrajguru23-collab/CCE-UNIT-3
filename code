
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string emergency;
    string location;
    int priority;
    Node* next;
};

Node* head = NULL;

// Function to add an emergency alert
void addAlert()
{
    Node* newNode = new Node;

    cout << "\nEnter Alert ID: ";
    if (!(cin >> newNode->id))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        delete newNode;
        cout << "Invalid Alert ID!\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->id == newNode->id)
        {
            cout << "Alert ID already exists!\n";
            delete newNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Emergency Type (one word): ";
    cin >> newNode->emergency;

    cout << "Enter Location (one word): ";
    cin >> newNode->location;

    cout << "Enter Priority (1=High, 2=Medium, 3=Low): ";

    if (!(cin >> newNode->priority))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        delete newNode;
        cout << "Invalid priority!\n";
        return;
    }

    if (newNode->priority < 1 ||
        newNode->priority > 3)
    {
        cout << "Priority must be 1, 2, or 3!\n";
        delete newNode;
        return;
    }

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Emergency alert added successfully!\n";
}

// Function to display all alerts
void displayAlerts()
{
    if (head == NULL)
    {
        cout << "\nNo active alerts available.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== ACTIVE EMERGENCY ALERTS =====\n";

    while (temp != NULL)
    {
        cout << "\nAlert ID: " << temp->id;
        cout << "\nEmergency Type: " << temp->emergency;
        cout << "\nLocation: " << temp->location;

        if (temp->priority == 1)
            cout << "\nPriority: HIGH";
        else if (temp->priority == 2)
            cout << "\nPriority: MEDIUM";
        else
            cout << "\nPriority: LOW";

        cout << "\n-----------------------------------\n";

        temp = temp->next;
    }
}

// Function to search for an alert
void searchAlert()
{
    int id;

    cout << "\nEnter Alert ID to search: ";

    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Alert ID!\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nAlert found!\n";
            cout << "Alert ID: " << temp->id << "\n";
            cout << "Emergency Type: " << temp->emergency << "\n";
            cout << "Location: " << temp->location << "\n";

            if (temp->priority == 1)
                cout << "Priority: HIGH\n";
            else if (temp->priority == 2)
                cout << "Priority: MEDIUM\n";
            else
                cout << "Priority: LOW\n";

            return;
        }

        temp = temp->next;
    }

    cout << "Alert not found.\n";
}

// Function to resolve an alert
void resolveAlert()
{
    int id;

    cout << "\nEnter Alert ID to resolve: ";

    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Alert ID!\n";
        return;
    }

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (previous == NULL)
                head = temp->next;
            else
                previous->next = temp->next;

            delete temp;

            cout << "Alert resolved successfully!\n";
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "Alert not found.\n";
}

// Function to free memory
void clearAlerts()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "   EMERGENCY ALERT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Emergency Alert\n";
        cout << "2. Display All Alerts\n";
        cout << "3. Search Alert\n";
        cout << "4. Resolve Alert\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                addAlert();
                break;

            case 2:
                displayAlerts();
                break;

            case 3:
                searchAlert();
                break;

            case 4:
                resolveAlert();
                break;

            case 5:
                clearAlerts();
                cout << "Program closed successfully.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
