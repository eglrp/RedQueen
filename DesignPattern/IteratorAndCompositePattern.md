# 迭代器与组合模式
如何让客户遍历你的对象而又无法窥视你存储对象的方式？如何创建一些对象的超集合(super collection)，可以一口气就跳过某些让人望而生畏的数据结构。

## 对象村餐厅和对象村煎饼屋合并了。但是它们的菜单是用不同的数据结构组合而成，我们的女服务员最好只用实现一个相同的接口，最小化女招待代码中的具体引用。这时候迭代器模式就派上用场了。
```
public interface Iterator
{
	boolean hasNext();
	object next();
}
```
```
public class DinerMenuIterator implements Iterator
{
	MenuItem[] item;
	int position = 0;
	
	public DinerMenuIterator(MenuItem[] items)
	{
		this.items = items;
	}

	public Object next()
	{
		MenuItem menuItem = items[position];
		position = position + 1;
		return menuItem;
	}

	public boolean hasNext()
	{
		if(position >= items.length || items[position] == null)
			return false;
		else
			return true;
	}
}
```
## 问：在多线程的情况下，可能有多个迭代器引用同一个对象集合。remove()会造成怎样对的影响？
答：后果并没有指明，所以很难预料。当你的程序在多线程的代码中使用到迭代器时，必须特别小心。

## 迭代器模式
- 提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露其内部的表示。
- 把游走的任务放在迭代器上，而不是聚合上。这样简化了聚合的接口和实现，也让责任各得其所。

## 设计原则
<font color="red">一个类应该只有引起变化的原因。</font>
- 类的每个责任都有改变的潜在区域。超过一个责任，意味着超过一个改变的区域。
- 这个原则告诉我们，尽量让每个类保持单一责任。

## 但是，女招待发现自己有早餐菜单、中餐菜单、晚餐菜单。但是早餐菜单里面还有一份甜品菜单，原有的数据结构已经无法使用迭代器遍历所有了，这可真让人摸不着头脑。

## 组合模式
允许你将对象组合成树形结构来表现“整体/部分”层次结构。组合能让客户以一致的方式处理个别对象以及对象组合
```
public abstract class MenuComponent
{
	public void add(MenuComponent menuComponent)
	{
		throw new UnsupportedOperationException();
	}

	public void remove(MenuComponent menuComponent)
	{
		throw new UnsupportedOperationException();
	}

	public MenuComponent getChild(int i)
	{
		throw new UnsupportedOperationException();
	}	

	public String getName()
	{
		throw new UnsupportedOperationException();
	}

	public String getDescription()
	{
		throw new UnsupportedOperationException();
	}

	public double getPrice()
	{
		throw new UnsupportedOperationException();
	}

	public boolean isVegetarion()
	{
		throw new UnsupportedOperationException();
	}

	public void print()
	{
		throw new UnsupportedOperationException();
	}
}
```
所有组件都必须实现MenuComponent接口，然而，叶节点合组合节点的角色不同，所以有些方法可能并不适合某种节点。面对这种情况，有时候，你最好市抛出运行时异常。

- 在我们写MenuComponent类的print()方法的时候，我们利用了一个迭代器来遍历组件内的每个项。如果遇到的是菜单(而不是菜单项)，我们就会递归地调用print()方法处理它。换句话说，MenuComponent是在“内部”自行处理遍历。

## 最后说一点
<font color="red">在实现组合模式时，有许多设计上的折衷。你要根据需要平衡透明性和安全性。</font>