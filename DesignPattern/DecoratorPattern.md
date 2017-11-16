# 装饰者模式
你将在本章学到如何使用对象组合的方式(其实就是俄罗斯套娃),做到在运行时装饰类。

## 为星巴克咖啡设计系统的时候可以用这个模式

## 设计原则
# 类应该对扩展开放,对修改关闭。
- 我们的目标是允许类容易扩展,在不修改现有代码的情况下,就可以搭配新的行为。如能实现这样的目标,有什么好处呢?这样的设计具有弹性可以应对改变,可以接受新的功能来应对改变的需求。

- 装饰者和被装饰者必须是一样的类型,也就是有共同的超类,这是相当关键的地方。

```
public abstract class Beverage	//Beverage是共同的超类,抽象组件
public abstract class CondimentDecorator extends Beverage	//抽象装饰者
public class Esopresso extends Beverage	//Esopresso是一种饮料，具体组件
public class Mocha extends CondimentDecorator	//摩卡，具体装饰者
```

```
Beverage beverage2 = new DarkRosat();	//创建一个DarkRosat对象
beverage2 = new Mocha(beverage2);	//用Mocha装饰它。
beverage2 = new Mocha(beverage2);	//double Mocha
beverage2 = new Whip(beverage2);	//用Whip装饰它。
System.out.println(beverage2.getDescription() + " $" + beverage2.cost);
```

## 两个缺点
- 利用装饰者模式,常常造成设计中有大量的小类,数量实在太多,可能会造成使用此API程序员的困扰。例如(java.io类)。
- 有一些代码会依赖特定的类型，而这样的代码一导入装饰者，嘭！就爆炸了！