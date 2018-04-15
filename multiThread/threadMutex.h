//
//  threadMutex.h
//  multiThread
//
//  Created by 徐意 on 15/04/2018.
//  Copyright © 2018 徐意. All rights reserved.
//

#ifndef threadMutex_h
#define threadMutex_h
//头文件是<mutex>，mutex是用来保证线程同步的，防止不同的线程同时操作同一个共享数据。运行结果，cnt是依次递减的，没有因为多线程而打乱次序：
//但是使用mutex是不安全的，当一个线程在解锁之前异常退出了，那么其它被阻塞的线程就无法继续下去。
int cnt = 20;
mutex m;
void t13()
{
    while (cnt > 0)
    {
        m.lock();
        
        if (cnt > 0)
        {
            --cnt;
            cout << cnt << endl;
        }
        
        m.unlock();
    }
}
void t23()
{
    while (cnt > 0)
    {
        m.lock();
        
        if (cnt > 0)
        {
            --cnt;
            cout << cnt << endl;
        }
        
        m.unlock();
    }
}
int testMutex()
{
    
    thread th1(t13);
    thread th2(t23);
    
    th1.join();
    th2.join();
    
    return 0;
}

#endif /* threadMutex_h */
