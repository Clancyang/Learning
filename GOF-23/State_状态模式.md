> ### 模式定义
> 允许一个对象在其内部状态改变时改变它的行为。从而使对象看起来似乎修改了其行为。


```
class NetworkState{

public:
    NetworkState* pNext;
    virtual void Operation1()=0;
    virtual void Operation2()=0;
    virtual void Operation3()=0;

    virtual ~NetworkState(){}
};
```

```
class OpenState :public NetworkState{ 
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance(){
        if (m_instance == nullptr) {
            m_instance = new OpenState();
        }
        return m_instance;
    }

    void Operation1(){
        
        //**********
        pNext = CloseState::getInstance();
    }
    
    void Operation2(){
        
        //..........
        pNext = ConnectState::getInstance();
    }
    
    void Operation3(){
        
        //$$$$$$$$$$
        pNext = OpenState::getInstance();
    } 
};
```

```
class CloseState:public NetworkState{ }
//...
```

```
class NetworkProcessor{ 
    NetworkState* pState; 
public: 
    NetworkProcessor(NetworkState* pState){
        
        this->pState = pState;
    }
    
    void Operation1(){
        //...
        pState->Operation1();
        pState = pState->pNext;
        //...
    }
    
    void Operation2(){
        //...
        pState->Operation2();
        pState = pState->pNext;
        //...
    }
    
    void Operation3(){
        //...
        pState->Operation3();
        pState = pState->pNext;
        //...
    }

};

```
> ### 要点总结
* State模式将所有与一个特定状态相关的行为都放入一个State的子
类对象中，在对象状态切换时，切换相应的对象;但同时维持
State的接口，这样实现了具体操作与状态转换之间的解耦。
* 为不同的状态引入不同的对象使得状态转换变得更加明确，而且
可以保证不会出现状态不一~致 的情况，因为转换是原子性的一即
要么彻底转换过来，要么不转换。
* 如果State对象没有实例变量，那么各个上下文可以共享同一个
State对象，从而节省对象开销。
