#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "todoList.h"

int main()
{
    TodoList todoList1;
    todoList1.addTask("Task 1", "Here is a description of Task 1.", "2023-06-14 06:00:00");
    todoList1.addTask("Task 2", "Here is a description of Task 2.", "2024-01-30 12:00:00");
    todoList1.displayTasks();
    //  todoList1.deleteTask("Task 1");
    todoList1.isCompleted("Task 1");
    todoList1.modifyTask("Task 1", "Changed description", "2026-07-11 23:00:00");
    todoList1.changeDeadline("Task 2", "2023-06-14 01:00:00");
    todoList1.displayTasks();
    std::cout << "Count of tasks : " << todoList1.getTaskCount() << std::endl;
    std::cout << "Count of completed tasks : " << todoList1.getCompletedTaskCount() << std::endl;
    std::cout << "Count of uncompleted tasks : " << todoList1.getUncompletedTaskCount() << std::endl;
    todoList1.checkDeadline();
}
