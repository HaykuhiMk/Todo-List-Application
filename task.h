#ifndef TASK_H
#define TASK_H
#include <string>

struct Task
{
public:
    std::string mName;
    std::string mDescription;
    std::tm mDeadline;
    bool mCompleted;
};

#endif  //TASK_H