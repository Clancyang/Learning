> ###　动机
* 在面向对象系统中，有些对象由于某种原因(比如对象创建的开
销很大，或者某些操作需要安全控制，或者需要进程外的访问等)
直接访问会给使用者、或者系统结构带来很多麻烦。
* 如何在不失去透明操作对象的同时来管理/控制这些对象特有的复
杂性?增加一层间接层是软件开发中常见的解决方式。

> ### 模式定义
> 为其他对象提供一种代理以控制 (隔离，使用接口)对这个
对象的访问。

```
class ISubject{
public:
    virtual void process();
};　　
```
```
class RealSubject: public ISubject{　　
public:
    virtual void process(){　
    }
};　　　　
``` 
> Proxy的设计:对RealSubject的一种间接访问
```
class SubjectProxy: public ISubject{　　
public:
    virtual void process(){ 
        //....
    }
};
```
```
class ClientApp{　
    ISubject* subject;　
public:　
    ClientApp(){
        subject=new SubjectProxy();
    }
    
    void DoTask(){
        //...
        subject->process();
        
        //....
    }
};
``` 

> ###　要点总结
* “增加一层间接层”是软件系统中对许多复杂问题的一种常见解决方
法。在面向对象系统中，直接使用某些对象会带来很多问题，作为
间接层的`proxy对象`便是解决这-问题的常用手段。
* 具体`proxy设计模式`的实现方法、实现粒度都相差很大，有些可能
对单个对象做细粒度的控制，如`copy-on-write`技术， 有些可能对组
件模块提供抽象代理层,在架构层次对对象做`proxy`。
* `Proxy`并不一定要求保持接口完整的一致性， 只要能够实现间接控
制，有时候损及一些透明性是可以接受的。

