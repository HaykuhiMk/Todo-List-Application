#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <chrono>
#include "todoList.h"

void TodoList::addTask(const std::string& name, const std::string& desc, const std::string& dl)
{
    Task tmp;
    tmp.mName = name;
    tmp.mDescription = desc;
    tmp.mDeadline = toTime(dl);
    tmp.mCompleted = false;
    mTasks.push_back(tmp);
}

void TodoList::deleteTask(const std::string& name)
{
    auto it = std::find_if(mTasks.begin(), mTasks.end(), [&name](const Task& task)
    {
        return task.mName == name;
    });
    if (it != mTasks.end()) 
    {
        mTasks.erase(it);
        std::cout << "The task " << name << " is deleted." << std::endl;
    } 
    else 
    {
        std::cout << "The task " << name << " is not found." << std::endl;
    }
}

void TodoList::isCompleted(const std::string& name)
{
    auto it = std::find_if(mTasks.begin(), mTasks.end(), [&name](const Task& task)
    {
        return task.mName == name;
    });
    if (it != mTasks.end()) 
    {
        it->mCompleted = true;
        std::cout << "The task " << name << " is completed." << std::endl;
    } 
    else 
    {
        std::cout << "The task " << name << " is not found." << std::endl;
    }
}       

void TodoList::modifyTask(const std::string& name, const std::string& desc, const std::string& dl)
{
    auto it = std::find_if(mTasks.begin(), mTasks.end(), [&name](const Task& task)
    {
        return task.mName == name;
    });
    if (it != mTasks.end()) 
    {
        it->mDescription = desc;
        it->mDeadline = toTime(dl);
        std::cout << "The task " << name << " has been changed." << std::endl;
    } 
    else 
    {
        std::cout << "The task " << name << " is not found." << std::endl;
    }
}

void TodoList::displayTasks()
{
    std::cout << "===== Todo List =====" << std::endl;
    for (Task& ts : mTasks)
    {
        std::cout << ts.mName << " : ";
        if (ts.mCompleted)
        {
            std::cout << "Completed\n" << std::endl;
        }
        else
        {
            std::cout << "Uncompleted\n" << std::endl;
        }
        std::cout << ts.mDescription << std::endl;
        std::cout << "Deadline -> " << toString(ts.mDeadline) << "\n" << std::endl;
    }
}

std::tm TodoList::toTime(const std::string& dl) 
{
    std::tm time = {};
    std::stringstream ss(dl);
    ss >> std::get_time(&time, "%Y-%m-%d %H:%M:%S");
    return time;
}

std::string TodoList::toString(const std::tm& dl) 
{
    std::stringstream ss;
    ss << std::put_time(&dl, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void TodoList::changeDeadline(const std::string& name, const std::string& dl)
{
    auto it = std::find_if(mTasks.begin(), mTasks.end(), [&name](const Task& task)
    {
        return task.mName == name;
    });
    if (it != mTasks.end()) 
    {
        it->mDeadline = toTime(dl);
        std::cout << "The deadline of task " << name << " has been changed." << std::endl;
    } 
    else 
    {
        std::cout << "The task " << name << " is not found." << std::endl;
    }
}

int TodoList::getTaskCount()
{
    return mTasks.size();
}

int TodoList::getCompletedTaskCount()
{
    int count = 0;
    for (const auto& ts : mTasks)
    {
        if (ts.mCompleted)
        {
            ++count;
        }
    }
    return count;
}

int TodoList::getUncompletedTaskCount()
{
    int count = 0;
    for (const auto& ts : mTasks)
    {
        if (!ts.mCompleted)
        {
            ++count;
        }
    }
    return count;
}

void TodoList::checkDeadline() 
{
    for (const auto& ts : mTasks)
    {
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* currentTime = std::localtime(&now);
        std::tm dufT = ts.mDeadline;
        dufT.tm_hour -= 1;
        if (std::difftime(std::mktime(&dufT), std::mktime(currentTime)) <= 0) 
        {
            std::cout << "Only one hour left before the deadline of task " << ts.mName << "!" << std::endl;
        }
    }
    
}