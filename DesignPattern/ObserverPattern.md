# 观察者模式(代表人物MVC)

有一个模式可以帮你的对象知悉现况，不会错过该对象感兴趣的事。对象甚至在运行时可决定是否要继续被通知。

## 定义
- 观察者模式定义了一系列对象之间的一对多关系。
- 当一个对象改变状态，其他依赖者都会收到通知。

## 记住根据一个WeatherData对象，可以推送给很多天气布告板。它们之间有相互对象的引用。例如书上的P56

## 设计原则
- 4.为交互对象之间的松耦合设计而努力。

## 要点

- 观察者模式定义了对象之间一对多的关系。
- 主题(也就是可观察者)用一个共同的接口来更新观察者。
- 观察者和可观察者之间用松耦合方式结合(loosecoupling),可观察者不知道观察者的细节,只知道观察者实现了观察者接口。
- 使用此模式时,你可以从被观察者处推(push)或拉(pull)数据(然而,推的方式被认为更"正确”)。
- 有多个观察者时,不可以依赖特定的通知顺序。
- Java有多种观察者模式的实现,包括了通用的java.util.Observable。
- 要注意java.util.Observable实现上所带来的一些问题。
- 如果有必要的话,可以实现自己的Observable,这并不难,不要害怕。
- Swing大量使用观察者模式,许多GUI框架也是如此。
- 此模式也被应用在许多地方,例如：JavaBeans、RMI。



