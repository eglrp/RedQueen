//
//  createAthread.h
//  multiThread
//
//  Created by 徐意 on 15/04/2018.
//  Copyright © 2018 徐意. All rights reserved.
//

#ifndef createAthread_h
#define createAthread_h

#include <iostream>
#include <thread>
using namespace std;

//不过这个示例是有问题的，因为在创建了线程后线程开始执行，但是主线程main()并没有停止脚步，仍然继续执行然后退出，此时线程对象还是joinable的，线程仍然存在但指向它的线程对象已经销毁，所以会抛出异常。

void t11()  //普通的函数，用来执行线程
{
    for (int i = 0; i < 20; ++i)
    {
        cout << "t1111\n";
    }
}
void t21()
{
    for (int i = 0; i < 20; ++i)
    {
        cout << "t22222\n";
    }
}

int testCreateAthread()
{
    thread th1(t11);  //实例化一个线程对象th1，使用函数t1构造，然后该线程就开始执行了（t1()）
    thread th2(t21);
    
    cout << "here is main\n\n";
    
    return 0;
}

#endif /* createAthread_h */
