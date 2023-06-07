#include <iostream>
#include <vector>

//система управления задачами

struct Task {
 std::string title;
 std::string description;
};

class TaskManager {
 private:
 std::vector<Task>tasks;//хранение задач в векторе
 
 public:
  void addTask(const Task& task);
  void viewTasks();
  void deleteTask(int index);
};

void TaskManager::addTask(const Task& task) {
 tasks.push_back(task);
}

void TaskManager::viewTasks() {
 for (const Task& task : tasks) {
  std::cout << "Title: " << task.title <<std::endl;
  std::cout << "Deskription: " << task.description <<std::endl;
  std::cout << std::endl;
 }
}

void TaskManager::deleteTask(int index) {
 if (index >= 0 && index < tasks.size()) {
  tasks.erase(tasks.begin() + index);
 }
}

int main() {
 TaskManager taskManager;
 int choice;
 
 do {
  std::cout << "Task Managment System" <<std::endl;
  std::cout << "1. Add Task" <<std::endl;
  std::cout << "2. View Tasks" <<std::endl;
  std::cout << "3. Delete Task" <<std::endl;
  std::cout << "0. Exit" <<std::endl;
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  
  switch (choice) {
   case 1: {
    Task task;
    std::cin.ignore();
    std::cout << "Enter title: ";
    std::getline(std::cin, task.title);
    std::cout << "Enter description: ";
    std::getline(std::cin, task.description);
    taskManager.addTask(task);
    break;
   }
   case 2: {
    taskManager.viewTasks();
    break;
   }
   case 3: {
    int index;
    std::cout << "Enter task index to delete: ";
    std::cin >> index;
    taskManager.deleteTask(index);
    break;
   }
  }
  std::cout << std::endl;
 } while (choice != 0);
 
 return 0;
 
}