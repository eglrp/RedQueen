# 工厂模式
当有一些要实例化的具体类，究竟实例化哪个类，要在运行时由一些条件来决定。当代码使用大量具体类时，我们就要考虑使用工厂模式了。

## 简单披萨工厂生产披萨(简单工厂生产类)。加盟披萨店，对披萨进行质量控制，给披萨店使用的框架，同时允许子类做决定(工厂方法模式)。最后通过抽象工厂模式使得每家披萨店使用的原料一致。

## 工厂方法模式
<font color = red>定义了一个创建对象的接口，但由子类决定要实例化的类是哪一个。工厂方法让类把实例化推迟到子类。</font>

```
public abstract class PizzaStore
{
	public Pizza OrderPizza(String type)
	{
		Pizza pizza = createPizza(type);
		pizza.prepare();
		pizza.bake();
		pizza.cut();
		pizza.box();
	}
	
	protected abstract Pizza createPizza(String type)
}
```	

在工厂方法模式中由每个商店自行负责createPizza()方法的行为。在简单工厂中，工厂是另一个由Pizzafore使用的对象。

为了避免字符串传入参数化的类型的危险。我们可以在编译时期就将参数上的错误挑出来。你可以创建代表参数类型的对象和使用静态常量或者enum。

## 设计原则-依赖倒置原则：要依赖抽象，不要依赖具体类
PizzaStore这个抽象类现在依赖Pizza这个抽象类。
ChicagoStyleChessPizza这个具体类也是依赖Pizza这个抽象类。
在实际运行的时候，根据具体的继承ChicagoPizzaStore和传入的参数type决定生产那些具体的Pizza。

## 抽象工厂模式(为了控制披萨店只使用工厂生产出的原料)
<font color = red>提供一个接口，用于创建相关或依赖对象的家族，而不需要明确指定具体类。</font>

```
public class NYPizzaStore extends PizzaStore
{
	protect Pizza createPizza(String item)
	{
		Pizza pizza = null;

		PizzaIngredientFactory ingredientFactory = new NYPizzaIngredientFactory();

		if(item.equals("cheese"))
		{
			pizza = new CheesePizza(ingredientFactory);
		}

		return pizza;
	}
}
```

## 要点
- 所有的工厂都是用来封装对象的创建
- 简单工厂，虽然不是真正的设计模式，但仍不失为一个简单的方法，可以将客户程序从具体类解耦。
- 工厂方法使用继承:把对象的创建委托给子类，子类实现工厂方法来创建对象。
- 抽象工厂使用对象组合:对象的创建被实现在工厂接口所暴露出来的方法中。
- 工厂是很有威力的技巧，帮助我们针对抽象编程，而不是针对具体类编程。

