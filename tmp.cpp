#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>

struct Task {
    std::string description;
    std::tm deadline;
    bool completed;
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description, const std::tm& deadline) {
        Task newTask;
        newTask.description = description;
        newTask.deadline = deadline;
        newTask.completed = false;
        tasks.push_back(newTask);
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void modifyTask(int index, const std::string& newDescription, const std::tm& newDeadline) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].description = newDescription;
            tasks[index].deadline = newDeadline;
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void displayTasks() {
        std::cout << "Todo List:" << std::endl;
        int completedCount = 0;
        int uncompletedCount = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << i << "] ";
            if (tasks[i].completed) {
                std::cout << "[Completed] ";
                completedCount++;
            } else {
                std::cout << "[Uncompleted] ";
                uncompletedCount++;
            }
            std::cout << tasks[i].description << " (Deadline: " << formatDeadline(tasks[i].deadline) << ")" << std::endl;
        }
        std::cout << "Completed tasks: " << completedCount << std::endl;
        std::cout << "Uncompleted tasks: " << uncompletedCount << std::endl;
    }

    std::string formatDeadline(const std::tm& deadline) {
        std::stringstream ss;
        ss << std::put_time(&deadline, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    int getTaskCount() {
        return tasks.size();
    }

    int getCompletedTaskCount() {
        int count = 0;
        for (const auto& task : tasks) {
            if (task.completed) {
                count++;
            }
        }
        return count;
    }

    int getUncompletedTaskCount() {
        int count = 0;
        for (const auto& task : tasks) {
            if (!task.completed) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    TodoList todoList;

    // Add tasks
    std::tm deadline1 = {};
    std::istringstream ss1("2023-06-14 10:00:00");
    ss1 >> std::get_time(&deadline1, "%Y-%m-%d %H:%M:%S");

    std::tm deadline2 = {};
    std::istringstream ss2("2023-06-15 14:30:00");
    ss2 >> std::get_time(&deadline2, "%Y-%m-%d %H:%M:%S");

    std::tm deadline3 = {};
    std::istringstream ss3("2023-06-16 16:45:00");
    ss3 >> std::get_time(&deadline3, "%Y-%m-%d %H:%M:%S");

    todoList.addTask("Task 1", deadline1);
    todoList.addTask("Task 2", deadline2);
    todoList.addTask("Task 3", deadline3);

    // Display initial tasks
    todoList.displayTasks();

    // Mark task as completed
    todoList.markTaskAsCompleted(1);

    // Modify task
    std::tm newDeadline = {};
    std::istringstream ss4("2023-06-17 12:00:00");
    ss4 >> std::get_time(&newDeadline, "%Y-%m-%d %H:%M:%S");
    todoList.modifyTask(2, "Modified Task", newDeadline);

    // Delete task
    todoList.deleteTask(0);

    // Display final tasks
    todoList.displayTasks();

    std::cout << "Total tasks: " << todoList.getTaskCount() << std::endl;
    std::cout << "Completed tasks: " << todoList.getCompletedTaskCount() << std::endl;
    std::cout << "Uncompleted tasks: " << todoList.getUncompletedTaskCount() << std::endl;

    return 0;
}
