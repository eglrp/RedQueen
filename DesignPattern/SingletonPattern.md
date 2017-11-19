# 独一无二的对象:单间模式

有一些对象其实我们只需要创建一个，比方说：线程池(threadpool)、缓存(cache)、对话框、处理偏好设置和注册表(registry)的对象、日志对象、充当打印机、显卡等设备的驱动程序的对象。如果多个实例就会：程序的行为异常、资源使用过量、或者是不一致的结果。

## 经典的单间模式实现(不适用于多线程)
```
public class Singleton
{
	private static Singleton uniqueInstance;

	private Singleton() { }

	public static Singleton getInstance() 
	{
		if(uniqueInstance == null)
		{
			uniqueInstance = new Singleton();
		}
		return uniqueInstance;
	}

}
```

## 定义单件模式
<font color="red">确保一个类只有一个实例，并提供一个全局访问点。</font>

## 再来看看多线程
- 1.如果getInstance()的性能对应用程序不是很关键，就同步getInstance()(不会有两个线程可以同时进入这个方法)。
	public static synchronized Singleton getInstance() 

- 2.使用"急切"创建实例，而不用延迟实例化的做法。
```
	private static Singleton uniqueInstance = new Sinleton();
	public static Singleton getInstance() 
	{
		return uniqueInstance;
	}
```

- 3.用"双重检查加锁"，在getInstance()中减少使用同步
	private volatile static Singleton uniqueInstance;
	只用第一次实例化才会同步。

