> ### 模式定义
> 提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露(稳定)该对象的内部表示。

```
template<typename T>
class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T& current() = 0;
};
```

```
template<typename T>
class MyCollection{ 
public: 
    Iterator<T> GetIterator(){
        //...
    }
    
};
```
```
template<typename T>
class CollectionIterator : public Iterator<T>{
    MyCollection<T> mc;
public:
    
    CollectionIterator(const MyCollection<T> & c): mc(c){ }
    
    void first() override {
        
    }
    void next() override {
        
    }
    bool isDone() const override{
        
    }
    T& current() override{
        
    }
};
```
```
void MyAlgorithm()
{
    MyCollection<int> mc;
    
    Iterator<int> iter= mc.GetIterator();
    
    for (iter.first(); !iter.isDone(); iter.next()){
        cout << iter.current() << endl;
    }
    
}
```

> ### 要点总结
* 迭代抽象:访问一个聚合对象的内容而无需暴露它的内部表示。
* 迭代多态:为遍历不同的集合结构提供- -个统-的接口，从而支持同样的算法在不同的集合结构上进行操作。
* 迭代器的健壮性考虑:遍历的同时更改迭代器所在的集合结构,会导致问题。
