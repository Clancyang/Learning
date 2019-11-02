> ### 模式定义
> 将一个类的接口转换成客户希望的另一个接口。Adapter模式使得原本由于接口不兼容而不能起工作的那些类可以一起工作。

![对象适配器](/IMG/Adapter.png)
> 目标接口（新接口）
```
class ITarget{
public:
    virtual void process()=0;
};
```
> 遗留接口（老接口）
```
class IAdaptee{
public:
    virtual void foo(int data)=0;
    virtual int bar()=0;
};
```
> 遗留类型
```
class OldClass: public IAdaptee{
    //....
};
```
> `对象适配器`
```
class Adapter: public ITarget{ //继承
protected:
    IAdaptee* pAdaptee;//组合 
public: 
    Adapter(IAdaptee* pAdaptee){
        this->pAdaptee=pAdaptee;
    }
    
    virtual void process(){
        int data=pAdaptee->bar();
        pAdaptee->foo(data); 
    } 
};
```

> 类适配器
```
class Adapter: public ITarget,
               protected OldClass{ //多继承
}
 ```
 ```
int main(){
    IAdaptee* pAdaptee=new OldClass();
    ITarget* pTarget=new Adapter(pAdaptee);
    pTarget->process();
}
```
> ### 要点总结
* `Adapter模式`主要应用于“希望复用一些现存的类,但是接口又与
复用环境要求不一致的情况 ”, 在遗留代码复用、类库迁移等方
面非常有用。
* GoF 23定义了两种Adapter模式的实现结构:`对象适配器`和 `类适`
`配器`。但`类适配器`采用“多继承”的实现方式，一般不推荐使用。
`对象适配器`采用“对象组合”的方式,更符合松耦合精神。
* `Adapter模式`可以实现的非常灵活,不必拘泥于Gof23中定义的两
种结构。例如完全可以将`Adapter模式`中的 “现存对象”作为新
的接口方法参数，来达到适配的目的。
