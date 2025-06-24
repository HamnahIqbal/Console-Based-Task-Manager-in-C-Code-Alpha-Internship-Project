#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;

    Task(string desc, string cat = "General") : 
        description(desc), category(cat), completed(false) {}
};

class TaskManager {
private:
    vector<Task> tasks;
    string filename;

public:
    TaskManager(string file) : filename(file) {}

    void addTask(string description, string category = "General") {
        tasks.push_back(Task(description, category));
        cout << "Task added successfully!" << endl;
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void viewTasks(bool showCompleted) {
        cout << (showCompleted ? "Completed Tasks: " : "Pending Tasks: ") << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].completed == showCompleted) {
                cout << i + 1 << ". [" << tasks[i].category << "] " 
                     << tasks[i].description << endl;
            }
        }
    }

    void saveTasks() {
        ofstream file(filename.c_str());
        if (file.is_open()) {
            for (size_t i = 0; i < tasks.size(); i++) {
                file << tasks[i].description << "|" 
                     << tasks[i].category << "|" 
                     << tasks[i].completed << endl;
            }
            file.close();
            cout << "Tasks saved successfully!" << endl;
        } else {
            cout << "Unable to save tasks!" << endl;
        }
    }

    void loadTasks() {
        ifstream file(filename.c_str());
        if (file.is_open()) {
            tasks.clear();
            string line, description, category;
            bool completed;
            while (getline(file, line)) {
                size_t pos = line.find("|");
                if (pos != string::npos) {
                    description = line.substr(0, pos);
                    line = line.substr(pos + 1);
                    
                    pos = line.find("|");
                    if (pos != string::npos) {
                        category = line.substr(0, pos);
                        completed = (line.substr(pos + 1) == "1");

                        Task task(description, category);
                        task.completed = completed;
                        tasks.push_back(task);
                    }
                }
            }
            file.close();
            cout << "Tasks loaded successfully!" << endl;
        } else {
            cout << "No saved tasks found." << endl;
        }
    }
};

int main() {
    TaskManager manager("tasks.txt");
    manager.loadTasks();

    int choice;
    string description, category;

    while (true) {
        cout << "\n==== To-Do List Application ====\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View Pending Tasks\n";
        cout << "4. View Completed Tasks\n";
        cout << "5. Save and Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: 
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter task category (optional): ";
                getline(cin, category);
                manager.addTask(description, category.empty() ? "General" : category);
                break;
            case 2: 
                int index;
                cout << "Enter task number to mark as completed: ";
                if (cin >> index) {
                    manager.markTaskCompleted(index - 1);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            case 3: 
                manager.viewTasks(false);
                break;
            case 4: 
                manager.viewTasks(true);
                break;
            case 5: 
                manager.saveTasks();
                cout << "Tasks saved. Exiting..." << endl;
                return 0;
            default: 
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
