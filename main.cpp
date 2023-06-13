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
    todoList1.addTask("TODO", "aaaaaaaaaaaaaaa", "2023-06-14 06:00:00");
    todoList1.addTask("HELLO", "bbbbbbbbbbbb", "2024-01-30 12:00:00");
    todoList1.displayTasks();
    //  todoList1.deleteTask("TODO");
    todoList1.isCompleted("TODO");
    todoList1.modifyTask("TODO", "changeddddddd", "2026-07-11 23:00:00");
    todoList1.changeDeadline("HELLO", "2023-06-14 01:00:00");
    todoList1.displayTasks();
    std::cout << todoList1.getTaskCount() << std::endl;
    std::cout << todoList1.getCompletedTaskCount() << std::endl;
    std::cout << todoList1.getUncompletedTaskCount() << std::endl;
    todoList1.checkDeadline();
}
