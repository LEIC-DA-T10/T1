//
// Created by dudud on 09/04/2022.
//

#ifndef DA_T1_APPLICATIONCONTROLLER_H
#define DA_T1_APPLICATIONCONTROLLER_H


class applicationController {
private:
    unsigned int state;
public:
    applicationController();
    void run();
    void setState(int state);
};


#endif //DA_T1_APPLICATIONCONTROLLER_H
