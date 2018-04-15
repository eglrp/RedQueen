//
//  testLock_guard.h
//  multiThread
//
//  Created by 徐意 on 15/04/2018.
//  Copyright © 2018 徐意. All rights reserved.
//

#ifndef testLock_guard_h
#define testLock_guard_h
//使用lock_guard则相对安全，它是基于作用域的，能够自解锁，当该对象创建时，它会像m.lock()一样获得互斥锁，当生命周期结束时，它会自动析构(unlock)，不会因为某个线程异常退出而影响其他线程。示例：

int cnt = 20;
mutex m;
void t14()
{
    while (cnt > 0)
    {
        lock_guard<mutex> lockGuard(m);
        if (cnt > 0)
        {
            --cnt;
            cout << cnt << endl;
        }
        
    }
}
void t24()
{
    while (cnt > 0)
    {
        lock_guard<mutex> lockGuard(m);
        if (cnt > 0)
        {
            --cnt;
            cout << cnt << endl;
        }
        
    }
}

#endif /* testLock_guard_h */
