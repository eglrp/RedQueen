//
//  threadJoin.h
//  multiThread
//
//  Created by 徐意 on 15/04/2018.
//  Copyright © 2018 徐意. All rights reserved.
//

#ifndef threadJoin_h
#define threadJoin_h
#include <iostream>
#include <thread>
using namespace std;
//使用join接口可以解决上述问题，join的作用是让主线程等待直到该子线程执行结束，示例：
//需要注意的是线程对象执行了join后就不再joinable了，所以只能调用join一次。
void t12()
{
    for (int i = 0; i < 20; ++i)
    {
        cout << "t1111\n";
    }
}
void t22()
{
    for (int i = 0; i < 20; ++i)
    {
        cout << "t22222\n";
    }
}
int testThreadJoin()
{
    thread th1(t12);
    thread th2(t22);
    
    th1.join(); //等待th1执行完
    th2.join(); //等待th2执行完
    
    cout << "here is main\n\n";
    
    return 0;
}

#endif /* threadJoin_h */
