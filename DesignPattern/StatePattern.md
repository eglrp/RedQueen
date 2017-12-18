# 状态模式
基本常识：策略模式和状态模式是双胞胎，在出生时才分开。

## 糖果机器，需要完成一个状态图。如果用程序状态机(PSM),太多的if,如果变更需求，会造成混乱的状态。因为我们没有遵循开放封闭原则，将不会改变的状态封装起来。

## 状态模式
<font color="red">允许对象在内部状态改变时改变它的行为，对象看起来好像修改了它的类。</font>
- 首先，我们定义一个State接口。在这个接口内，糖果机的每个动作都有一个对应的方法。
- 然后为机器中的每个状态实现状态内。这些类将在负责在对应的状态下进行机器的行为。
- 最后，我们要摆脱旧的条件代码，取而代之的方式是，将动作委托到状态类。
```
pubic interface State
{
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void despense();
}
```

```
public class NoQuarterState implements State
{
	GumballMachine gumballMachine;

	public NoQuarterState(GumballMachine gumballMachine)
	{
		this.gumballMachine = gumballMachine;
	}

	public void insertQuarter()
	{
		System.out.println("You inserted a quarter");
		gumballMachine.setState(gumballMachine.getHasQurterState());
	}

	public void ejectQuarter()
	{
		System.out.println("You haven't inserted a quarter");
	}
	public void turnCrank();
	public void despense();
}
```

```
public class GumballMachine
{
	State soldOutState;
	State noQuarterState;
	State hasQuarterState;
	State soldState;

	State state = soldOutState;
	int count = 0;

	public GumballMachine(int numberGumballs)
	{
		soldOutState = new SoldOutState(this);
		...
		this.count = numberGumballs;
		if(numberGumbers > 0)
		{
			state = noQuarterState;
		}
	}

	public void insertQuarter()
	{
		state.insertQuarter();
	}

	public void turnCrank()
	{
		state.turnCrank();
		state.dispense();
	}

	...
}
```

## 状态模式和策略模式的类图是一样的，但是这两个的“意图”不一样。
- 状态模式的Context对象会随着时间而改变状态，而任何的状态改变都是定义好的。“改变行为”这件事是建立在我的方案中的。
- 策略模式会控制我的对象使用什么策略。

## 如果我们没有共同的功能可以放进抽象类中，就会使用接口。

## 要点
- 状态模式允许一个对象基于内部状态而拥有不同的行为。
- 和程序状态机(PSM)不同，状态模式用类代表状态。
- Context会将行为委托给当前的行为对象。
- 策略模式通常会用行为或算法来配置Context类。
- 状态模式可以由State类或Context类控制。
- 使用状态模式通常会导致设计中的类的数目大量增加。
- 状态类可以被多个Context实例共享。


