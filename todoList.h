#ifndef TODO_LIST_H
#define TODO_LIST_H
#include <vector>
#include <string>
#include "task.h"

class TodoList
{
public:
    void addTask(const std::string&, const std::string&, const std::string&);
    void deleteTask(const std::string&);
    void isCompleted(const std::string&);
    void modifyTask(const std::string&, const std::string&, const std::string&);
    void displayTasks();
    std::string toString(const std::tm&);
    std::tm toTime(const std::string&); 
    void changeDeadline(const std::string&, const std::string&);
    int getTaskCount();
    int getCompletedTaskCount();
    int getUncompletedTaskCount();
    void checkDeadline();

private:
    std::vector<Task> mTasks;
};

#endif  //TODO_LIST_H