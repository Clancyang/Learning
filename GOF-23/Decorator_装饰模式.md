> ### 模式定义
> 动态（组合）地给一个对象增加一些额外的职责。就增加功 能而言，`Decorator`模式比生成子类（继承）更为灵活（消 除重复代码 & 减少子类个数）
 
> 业务操作
```
class Stream{

public：
    virtual char Read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    
    virtual ~Stream(){}
};
```
```
//主体类
class FileStream: public Stream{
public:
    virtual char Read(int number){
        //读文件流
    }
    virtual void Seek(int position){
        //定位文件流
    }
    virtual void Write(char data){
        //写文件流
    }

};
```
```
class NetworkStream :public Stream{
public:
    virtual char Read(int number){
        //读网络流
    }
    virtual void Seek(int position){
        //定位网络流
    }
    virtual void Write(char data){
        //写网络流
    }
    
};
```
```
class MemoryStream :public Stream{
public:
    virtual char Read(int number){
        //读内存流
    }
    virtual void Seek(int position){
        //定位内存流
    }
    virtual void Write(char data){
        //写内存流
    }
    
};
```
> `扩展操作`
```
DecoratorStream: public Stream{ 
protected:
    Stream* stream;//...
    
    DecoratorStream(Stream * stm):stream(stm){
    
    } 
};
```
```
class CryptoStream: public DecoratorStream {
public:
    CryptoStream(Stream* stm):DecoratorStream(stm){
    
    }
    
    virtual char Read(int number){
       
        //额外的加密操作...
        stream->Read(number);//读文件流
    }
    virtual void Seek(int position){
        //额外的加密操作...
        stream::Seek(position);//定位文件流
        //额外的加密操作...
    }
    virtual void Write(byte data){
        //额外的加密操作...
        stream::Write(data);//写文件流
        //额外的加密操作...
    }
};
```

```
class BufferedStream : public DecoratorStream{
    
    Stream* stream;//...
    
public:
    BufferedStream(Stream* stm):DecoratorStream(stm){
        
    }
    //...
};
```
```
void Process(){

    //运行时装配
    FileStream* s1=new FileStream();
    
    CryptoStream* s2=new CryptoStream(s1);
    
    BufferedStream* s3=new BufferedStream(s1);
    
    BufferedStream* s4=new BufferedStream(s2);
}
```
> ### 要点总结
 * 通过采用组合而非继承的手法， `Decorator`模式实现了在运行时 动态扩展对象功能的能力，而且可以根据需要扩展多个功能。避免 了使用继承带来的“灵活性差”和“多子类衍生问题”。 
  
 * `Decorator`类在接口上表现为`is-a Component`的继承关系，即 `Decorator类`继承了`Component类`所具有的接口。但在实现上又 表现为`has-a Component`的组合关系，即`Decorator类`又使用了 另外一个`Component类`。 
  
 * `Decorator`模式的目的并非解决“多子类衍生的多继承”问题， `Decorator`模式应用的要点在于解决“主体类在多个方向上的扩展 功能”——是为“装饰”的含义。
